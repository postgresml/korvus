# Korvus

*One query to rule them all, One query to find them, One query to bring them all and in the context bind them*

Korvus is a search SDK that unifies the entire RAG pipeline in a single database query. Built on top of Postgres with bindings for Python, JavaScript and Rust, Korvus delivers high-performance, customizable search capabilities with minimal infrastructure concerns.

<details open>
<summary><b>📕 Table of Contents</b></summary>

- [🦅 What is Korvus?](#-what-is-korvus)
- [🏆 Why Korvus?](#-why-korvus)
- [⚡ Key Features](#-key-features)
- [🧩 System Architecture](#-system-architecture)
- [🚀 Get Started](#-get-started)
- [🔍 The Power of SQL](#-the-power-of-sql)
- [📘 Documentation](#-documentation)
- [🌐 Community](#-community)
- [🤝 Contributing](#-contributing)

</details>

## 🦅 What is Korvus?

Korvus is an all-in-one, open-source RAG (Retrieval-Augmented Generation) pipeline built for Postgres. It combines LLMs, vector memory, embedding generation, reranking, summarization and custom models into a single query, maximizing performance and simplifying your search architecture.

## 🏆 Why Korvus?

Korvus stands out by harnessing the full power of Postgres for RAG operations:

1. **Postgres-Native RAG**: Korvus leverages Postgres' robust capabilities, allowing you to perform complex RAG operations directly within your database. This approach eliminates the need for external services and API calls, significantly reducing latency and complexity many times over.

2. **Single Query Efficiency**: With Korvus, your entire RAG pipeline - from embedding generation to text generation - is executed in a single SQL query. This "one query to rule them all" approach simplifies your architecture and boosts performance.

3. **Scalability and Performance**: By building on Postgres, Korvus inherits its excellent scalability and performance characteristics. As your data grows, Korvus grows with it, maintaining high performance even with large datasets.

## ⚡ Key Features

- **Simplified Architecture**: Replace complex service oriented architectures with a single, powerful query.
- **High Performance**: Eliminates API calls and data movement for faster processing and greater reliability.
- **Open Source**: Improve your developer experience with open source software and models that run locally in Docker too.
- **Multi-Language Support**: Use Korvus with Python, JavaScript and Rust. Open an issue to vote for other language support.
- **Unified Pipeline**: Combine embedding generation, vector search, reranking, and text generation in one query.
- **Postgres-Powered**: Under the hood, Korvus operations are powered by efficient SQL queries on a time-tested database platform.

## 🧩 System Architecture

[Insert system architecture diagram here]

## 🚀 Get Started

### 📋 Prerequisites

To use Korvus, you need a Postgres database with pgml and pgvector installed. You have two options:

1. **Self-hosted**: Set up your own database with pgml and pgvector.
   - For instructions, see our [self-hosting guide]().

2. **Hosted Service**: Use our managed Postgres service with pgml and pgvector pre-installed.
   - [Sign up for PostgresML Cloud](https://postgresml.org/signup).

### 🏁 Quick Start

1. Install Korvus:

   ```bash
   pip install korvus
   ```

2. Initialize Korvus with your database connection:

   ```python
   from korvus import Korvus

   # For self-hosted:
   korvus = Korvus(connection_string="postgresql://user:password@localhost/database")

   # For PostgresML Cloud:
   korvus = Korvus(connection_string="postgresql://user:password@your-instance.postgresml.org/database")
   ```

3. Perform a RAG query:

   ```python
   result = korvus.query("What is the capital of France?")
   print(result)
   ```

## 🔍 The Power of SQL

While Korvus provides a high-level interface in multiple programming languages, its core operations are built on optimized SQL queries. This approach offers several advantages:

- **Transparency**: Advanced users can inspect and understand the underlying queries.
- **Customizability**: Extend Korvus's capabilities by modifying or adding to its SQL operations.
- **Performance**: Benefit from PostgreSQL's advanced query optimization capabilities.

Don't worry if you're not a SQL expert - Korvus's intuitive API abstracts away the complexity while still allowing you to harness the full power of SQL-based operations.

## 📘 Documentation

For comprehensive documentation, including API references, tutorials, and best practices, visit our [official documentation]().

## 🌐 Community

Join our community to get help, share ideas, and contribute:

- [Discord]()
- [Twitter]()

## 🤝 Contributing

We welcome contributions to Korvus! Please read our [Contribution Guidelines](CONTRIBUTING.md) before submitting pull requests.

---

Korvus is maintained by [PostgresML](https://postgresml.org). For enterprise support and consulting services, please [contact us](https://postgresml.org/contact).
