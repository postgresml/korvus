# Korvus

*One query to rule them all*

Korvus is an open-source search SDK that unifies the entire RAG pipeline in a single query. Built for PostgreSQL and available in Python, JavaScript, C, and Rust, Korvus leverages the power of SQL to deliver high-performance, customizable search capabilities.

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

Korvus is an all-in-one, open-source RAG (Retrieval-Augmented Generation) pipeline built for PostgreSQL. It combines LLMs, vector memory, embedding generation, reranking, and pruning models into a single, efficient query, maximizing performance and simplifying your search architecture.

## 🏆 Why Korvus?

Korvus stands out by harnessing the full power of PostgreSQL for RAG operations:

1. **PostgreSQL-Native RAG**: Korvus leverages PostgreSQL's robust capabilities, allowing you to perform complex RAG operations directly within your database. This approach eliminates the need for external services and API calls, significantly reducing latency and complexity.

2. **Single Query Efficiency**: With Korvus, your entire RAG pipeline - from embedding generation to text generation - is executed in a single SQL query. This "one query to rule them all" approach simplifies your architecture and boosts performance.

3. **Scalability and Performance**: By building on PostgreSQL, Korvus inherits its excellent scalability and performance characteristics. As your data grows, Korvus grows with it, maintaining high performance even with large datasets.

## ⚡ Key Features

- **Unified Pipeline**: Combine embedding generation, vector search, reranking, and text generation in one query.
- **Multi-Language Support**: Use Korvus with Python, JavaScript, C, or Rust.
- **PostgreSQL Integration**: Leverages PostgresML's in-database machine learning capabilities.
- **High Performance**: Eliminates API calls and data movement for faster processing.
- **Simplified Architecture**: Replace complex microservices with a single, powerful query.
- **SQL-Powered**: Under the hood, Korvus operations are powered by efficient SQL queries.

## 🧩 System Architecture

[Insert system architecture diagram here]

## 🚀 Get Started

### 📋 Prerequisites

To use Korvus, you need a PostgreSQL database with pgml and pgvector installed. You have two options:

1. **Self-hosted**: Set up your own PostgreSQL database with pgml and pgvector.
   - For instructions, see our [self-hosting guide]().

2. **Hosted Service**: Use our managed PostgreSQL service with pgml and pgvector pre-installed.
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
