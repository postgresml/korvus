use futures::{future::BoxFuture, FutureExt};
use itertools::Itertools;
use sqlx::PgPool;
use tracing::instrument;

use crate::get_or_initialize_pool;

// There is probably a better way to write this type and the version_migrations variable in the dispatch_migrations function
type MigrateFn =
    Box<dyn Fn(PgPool, Vec<i64>) -> BoxFuture<'static, anyhow::Result<String>> + Send + Sync>;

#[instrument]
pub fn migrate() -> BoxFuture<'static, anyhow::Result<()>> {
    async move {
        let pool = get_or_initialize_pool(&None).await?;
        let results: Result<Vec<(String, i64)>, _> =
            sqlx::query_as("SELECT sdk_version, id FROM pgml.collections")
                .fetch_all(&pool)
                .await;
        match results {
            Ok(collections) => {
                dispatch_migrations(pool, collections).await?;
                Ok(())
            }
            Err(error) => {
                anyhow::bail!(error)
            }
        }
    }
    .boxed()
}

async fn dispatch_migrations(pool: PgPool, collections: Vec<(String, i64)>) -> anyhow::Result<()> {
    // The version of the SDK that the migration was written for, and the migration function
    let version_migrations: [(&'static str, MigrateFn); 0] = [];

    let mut collections = collections.into_iter().into_group_map();
    for (version, migration) in version_migrations.into_iter() {
        if let Some(collection_ids) = collections.remove(version) {
            let new_version = migration(pool.clone(), collection_ids.clone()).await?;
            if let Some(new_collection_ids) = collections.get_mut(&new_version) {
                new_collection_ids.extend(collection_ids);
            } else {
                collections.insert(new_version, collection_ids);
            }
        }
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::internal_init_logger;

    #[tokio::test]
    async fn can_migrate() -> anyhow::Result<()> {
        internal_init_logger(None, None).ok();
        migrate().await?;
        Ok(())
    }
}
