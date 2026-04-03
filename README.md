# Embedded Systems Reference

A personal reference repository covering low-level embedded programming concepts in C, C++, and Assembly. Topics span bare-metal microcontroller programming, classic data structures, pointer mechanics, and memory management — organized by language and subject area.

---

## Repository Structure

```
embedded/
├── c/
│   └── src/           # C programs covering embedded-relevant topics
├── cpp/               # Numbered C++ examples (e.g. 001-Basics, 002-Pointers)
├── data_structures/   # Implementations of common data structures in C/C++
├── mcu/               # Bare-metal MCU code (Assembly, Linker Scripts, Makefiles)
├── CMakeLists.txt
└── README.md
```

### `c/src` — C Programming

Core C concepts as they apply to embedded development, including:

- Pointers and pointer arithmetic
- Memory layout (stack, heap, static)
- Bit manipulation and register access
- Type qualifiers (`volatile`, `const`)
- Preprocessor macros

### `cpp` — C++ Examples

Numbered examples progressing through C++ features relevant to embedded and systems programming:

- References and pointers
- Operator overloading
- Classes and object lifecycle
- Templates and type safety

### `data_structures` — Data Structures

Implementations of foundational data structures commonly used in embedded systems:

- Linked lists
- Circular buffers
- Queues and stacks
- Trees

### `mcu` — Microcontroller Programming

Bare-metal code targeting real hardware, including:

- Startup code and Linker Scripts
- Register-level peripheral configuration
- Assembly routines
- Makefile-based build system

---

## Languages

| Language | Usage |
|----------|-------|
| C | Core embedded logic, peripheral drivers, data structures |
| Assembly | MCU startup code, low-level routines |
| C++ | Object-oriented embedded examples |
| Linker Script | Memory region definitions for bare-metal targets |
| Makefile | MCU build system |

## Build (C++ examples)

The root `CMakeLists.txt` can be used to build individual C++ examples:

```bash
cmake -S . -B build
cmake --build build
```

To build a specific example, update the `SOURCE_FILES` path in `CMakeLists.txt` to point to the desired file.

## Prerequisites

- GCC / G++ (or an ARM cross-compiler for MCU targets, e.g. `arm-none-eabi-gcc`)
- CMake ≥ 3.12 (for C++ examples)
- Make (for MCU targets)
