#include <stdio.h>

#include "korvus.h"

int main() {
  // Create the Collection and Pipeline
  CollectionC * collection = korvus_collectionc_new("test_c", NULL);
  PipelineC * pipeline = korvus_pipelinec_new("test_c", "{\"text\": {\"splitter\": {\"model\": \"recursive_character\"},\"semantic_search\": {\"model\": \"intfloat/e5-small\"}}}");

  // Add the Pipeline to the Collection
  korvus_collectionc_add_pipeline(collection, pipeline);

  // Upsert the documents
  char * documents_to_upsert[2] = {"{\"id\": \"doc1\", \"text\": \"test1\"}", "{\"id\": \"doc2\", \"text\": \"test2\"}"};
  korvus_collectionc_upsert_documents(collection, documents_to_upsert, 2, NULL);

  // Retrieve the documents
  unsigned long r_size = 0;
  char** documents = korvus_collectionc_get_documents(collection, NULL, &r_size);

  // Print the documents
  printf("\n\nPrinting documents:\n");
  int i;
  for (i = 0; i < r_size; ++i) {
    printf("Document %u -> %s\n", i, documents[i]);
  }

  // Search over the documents
  r_size = 0;
  char** results = korvus_collectionc_vector_search(collection, "{\"query\": {\"fields\": {\"text\": {\"query\": \"Test query!\"}}}, \"limit\": 5}", pipeline, &r_size);
  printf("\n\nPrinting results:\n");
  for (i = 0; i < r_size; ++i) {
    printf("Result %u -> %s\n", i, results[i]);
  }

  // Test the TransformerPipeline
  TransformerPipelineC * t_pipeline = korvus_transformerpipelinec_new("text-generation", "meta-llama/Meta-Llama-3-8B-Instruct", NULL, NULL);
  GeneralJsonAsyncIteratorC * t_pipeline_iter = korvus_transformerpipelinec_transform_stream(t_pipeline, "\"AI is going to\"", "{\"max_new_tokens\": 100}", NULL);
  while (!korvus_generaljsonasynciteratorc_done(t_pipeline_iter)) {
    char * res = korvus_generaljsonasynciteratorc_next(t_pipeline_iter);
    printf("Token -> %s\n", res);
  }

  // cleanup
  korvus_transformerpipelinec_delete(t_pipeline);
  korvus_pipelinec_delete(pipeline);
  korvus_collectionc_delete(collection);

  return 0;
}
