[![Language](https://img.shields.io/badge/Language-C-blue.svg?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build](https://img.shields.io/badge/Build-Makefile-brightgreen.svg?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![License](https://img.shields.io/badge/License-Public_Domain-lightgrey.svg?style=for-the-badge&logo=unlicense&logoColor=black)](https://unlicense.org/)
[![Status](https://img.shields.io/badge/Status-Archived-orange.svg?style=for-the-badge)](https://en.wikipedia.org/wiki/Software_archiving)
[![Course](https://img.shields.io/badge/Course-IJC_@_FIT-informational.svg?style=for-the-badge)](https://www.fit.vut.cz/study/course/280992/.en)

This repository contains projects developed for the IJC (C Language) course at FIT (Faculty of Information Technology). These projects cover fundamental C programming concepts, data structures, and algorithms.

## Project 1: Image Steganography & Prime Number Sieve

This project focuses on bitwise operations, PPM image file manipulation, and an efficient algorithm for finding prime numbers.

*   <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="currentColor" style="vertical-align: -0.125em; margin-right: 4px;"><path d="M21 19V5c0-1.1-.9-2-2-2H5c-1.1 0-2 .9-2 2v14c0 1.1.9 2 2 2h14c1.1 0 2-.9 2-2zM8.5 13.5l2.5 3.01L14.5 12l4.5 6H5l3.5-4.5z"/></svg>
    **Steganography**: Decodes a secret message hidden within the least significant bits (LSB) of PPM (Portable PixMap P6) image files.
*   <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" viewBox="0 0 16 16" style="vertical-align: -0.125em; margin-right: 4px;"> <path d="M8.39 12.648a1.32 1.32 0 0 0-.015.18c0 .305.21.508.5.508.266 0 .492-.172.555-.477l.554-2.703h1.204c.421 0 .617-.234.617-.547 0-.312-.188-.53-.617-.53h-.985l.516-2.524h1.265c.43 0 .618-.227.618-.547 0-.313-.188-.524-.618-.524h-1.046l.476-2.304a1.06 1.06 0 0 0 .016-.164.51.51 0 0 0-.516-.516.54.54 0 0 0-.539.43l-.523 2.554H7.617l.477-2.304c.008-.04.015-.118.015-.164a.512.512 0 0 0-.512-.516.539.539 0 0 0-.531.43L6.53 5.484H5.414c-.43 0-.617.22-.617.532 0 .312.187.539.617.539h.906l-.515 2.523H4.609c-.421 0-.609.219-.609.531 0 .313.188.547.61.547h.976l-.516 2.492c-.008-.04-.015.125-.015.18 0 .305.21.508.5.508.265 0 .492-.172.554-.477l.555-2.703h2.242l-.515 2.492zm-1-6.406h1.265l-.515 2.523H6.857l.532-2.523zm.031 3.549h1.233l-.515 2.5H7.4l.524-2.5z"/> </svg>
    **Prime Numbers**: Implements the Sieve of Eratosthenes to efficiently find prime numbers up to a large limit (e.g., 500,000,000).

**Key components:**
*   PPM image parser (`ppm.c`, `ppm.h`).
*   Bitset data structure (`bitset.c`, `bitset.h`) for efficient bit manipulation.
*   Sieve of Eratosthenes algorithm (`eratosthenes.c`, `eratosthenes.h`).
*   Error handling utilities (`error.c`, `error.h`).

**To build:** Navigate to `Projekt1/` and run `make`.
```bash
cd Projekt1
make
```

## Project 2: Hash Table Library & Text Utilities

This project delivers a **general-purpose hash-table library** and two small text-processing CLI tools that showcase it.

### 📦 Hash-Table Library

* **Language:** C  
* **Collision strategy:** separate chaining  
* **Key/value:** `char*` → `int`  
* **API:**  
  * `htab_init`, `htab_free` – create / destroy a table  
  * `htab_insert`, `htab_lookup`, `htab_erase`  
  * `htab_for_each` – iterate over all pairs  
  * `htab_clear` – wipe the table

Source files: `htab_*.c`, `htab.h`, `htab_private.h`  
Outputs after build:  

* **Static** library — `libhtab.a`  
* **Shared** library — `libhtab.so`

---

### 🛠️ Command-line Utilities

| Tool | Purpose |
|------|---------|
| **`wordcount`** | Reads stdin, counts word frequencies via the hash table, prints counts. |
| **`tail`** | Lightweight clone of Unix `tail`: print the last *N* lines (or from a given line number) from a file or stdin. |

Helper for tokenizing input: `io.c`, `io.h`.

---

### ⚙️ Building

```bash
cd Projekt2
make
```
