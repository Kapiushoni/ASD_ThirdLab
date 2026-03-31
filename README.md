# Hash Table Investigation & Analysis | ADS Lab 3

This repository contains a high-performance implementation of **Hash Table** data structures, developed for the Algorithms and Data Structures course at **Kyiv Polytechnic Institute (IPSA)**. The project focuses on efficient data management, collision resolution strategies, and string-matching algorithms.

## 📌 Project Overview

The system implements a specialized database for an **iPhone Store** (Variant 5). It uses unique 64-bit serial numbers as keys to store and retrieve device information with average $O(1)$ time complexity.

### Key Implemented Features
* **Separate Chaining:** Collision resolution using a custom singly-linked list.
* **Open Addressing:** Alternative implementation using **Linear Probing**.
* **Dynamic Rehashing:** Automated table resizing and element redistribution based on a configurable `loadFactor`.
* **Rabin-Karp Algorithm:** A rolling-hash-based pattern matching algorithm for efficient text searching.
* **Automated Benchmarking:** A comprehensive test suite comparing custom implementations against the standard C++ library (`std::unordered_map`).

## 📂 Project Structure
* `Structures.h`: Contains the `Iphone` data structure and `HashNode` definitions.
* `LinkedList.h/cpp`: Logic for the singly-linked list used in the chaining method.
* `HashTable.h/cpp`: Main hash table implementation using **Separate Chaining**.
* `OpenHashTable.h/cpp`: Additional implementation using **Open Addressing**.
* `main.cpp`: Entry point containing the `testHashTable` logic and Rabin-Karp algorithm.

## 📊 Performance Benchmarks
Tested with **500,000 iterations** in a Windows environment:

| Implementation | Execution Time | Correctness |
| :--- | :--- | :--- |
| **Custom HashTable (Chaining)** | **0.746s** | **Pass** |
| **STL unordered_map** | **0.969s** | **Pass** |

*The custom implementation proved to be highly efficient, outperforming the standard library in this specific scenario due to specialized hashing for integer keys.*

## 🚀 Getting Started

### Prerequisites
* A C++ compiler supporting **C++17** or higher (e.g., GCC/MinGW).

### Installation & Execution
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/hash-table-analysis.git](https://github.com/your-username/hash-table-analysis.git)
   cd hash-table-analysis
Compile all source files:

Bash
g++ *.cpp -o main
Run the benchmark:

Bash
./main
👤 Author
Artur Halechian

University: Kyiv Polytechnic Institute (KPI), IPSA

Focus: Backend Development (Python/C++), AI & Systems Programming


Тепер твій GitHub буде виглядати солідно, особливо з огляду на те, що ти цілишся в Junior
