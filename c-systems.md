# C Core Concepts for Systems Programming (CMPE230)


This document introduces C through the lens of **systems programming**.
The goal is not only to learn C syntax, but to understand **how programs are built, how memory is organized, and how the machine executes your code**.



# 1. Why C?

C remains central in systems programming because it provides:

* **Low-level memory access**
* **Predictable data layout**
* **Minimal abstraction overhead**
* **Direct compilation to machine code**

C is used in:

* Operating systems (Linux kernel)
* Compilers and toolchains
* Embedded systems
* Network stacks
* Performance-critical libraries

In this course, C is not treated as just a programming language, but as a concrete model for understanding how code is compiled, linked, loaded, and executed on a computer system.



# 2. Structure of a C Program

A C program typically contains:

* **Preprocessor directives** (`#include`, `#define`)
* **Declarations**
* **Definitions**
* **Functions**
* **Statements and expressions**
* **Comments**

Example:

```c
#include <stdio.h>

#define MESSAGE "C programming is powerful!"

int main() {
    // Single-line comment
    /*
       Multi-line comment
    */

    printf("Hello world!\n");
    printf("%s\n", MESSAGE);
    return 0;
}
```


# 3. From Source Code to Executable

C programs must be compiled before execution.

## 3.1 Compilation Stages

```
main.c
   ↓
Preprocessor
   ↓
Compiler
   ↓
Assembler
   ↓
Object file (.o)
   ↓
Linker
   ↓
Executable (a.out)
```

### Commands

Compile only:

```bash
gcc -c main.c
```

Compile and link:

```bash
gcc main.c -o program
```


## 3.2 Inspecting Object Files

```bash
objdump -h main.o
objdump -t main.o
nm main.o
```

Important sections:

| Section   | Description                    |
| --------- | ------------------------------ |
| `.text`   | Machine instructions           |
| `.data`   | Initialized global variables   |
| `.bss`    | Uninitialized global variables |
| `.rodata` | Read-only constants            |

Understanding these sections is essential in systems programming.


# 4. Program Memory Layout

When running, a program typically looks like:

```
+----------------------+
| Stack                |
+----------------------+
| Heap                 |
+----------------------+
| BSS                  |
+----------------------+
| Data                 |
+----------------------+
| Text                 |
+----------------------+
```

Example:

```c
#include <stdio.h>

int global_init = 5;   // Data segment
int global_uninit;     // BSS

int main() {
    int local_var = 10;  // Stack

    printf("global_init: %p\n", (void*)&global_init);
    printf("global_uninit: %p\n", (void*)&global_uninit);
    printf("local_var: %p\n", (void*)&local_var);
    return 0;
}
```

Observe how addresses differ.


# 5. Data Types in C

## 5.1 Basic Types

| Type   | Typical Size | Format |
| ------ | ------------ | ------ |
| int    | 4 bytes      | %d     |
| char   | 1 byte       | %c     |
| float  | 4 bytes      | %f     |
| double | 8 bytes      | %lf    |

Example:

```c
#include <stdio.h>

int main() {
    int x = 50;
    char ch = 'a';
    double d = 3.14;

    printf("x = %d, size = %lu\n", x, sizeof(x));
    printf("ch = %c, ASCII = %d\n", ch, ch);
    printf("d = %lf\n", d);
    return 0;
}
```

Sizes depend on architecture.


## 5.2 Derived and User-defined Types

### Arrays

```c
int arr[5];
```

### Pointers

```c
int x = 5;
int *p = &x;
```

### Structs

```c
typedef struct {
    int x;
    int y;
} Point;

Point p1 = {10, 20};
```

### Enum

```c
enum Color { RED, GREEN, BLUE };
```


## 5.3 Struct Padding and Alignment

```c
struct Example {
    char c;
    int x;
};
```

Expected: 5 bytes
Actual (typically): 8 bytes

Why? Memory alignment.


# 6. Type Modifiers

## Signed vs Unsigned

```c
unsigned int x = 300;
int y = -300;
```

## Short and Long

```c
short s;
long l;
long long ll;
```

Check sizes:

```c
printf("%lu\n", sizeof(long));
```

Sizes vary by architecture.


# 7. Declaration vs Definition

## Declaration (no memory allocated)

```c
extern int num;
```

## Definition (memory allocated)

```c
int num = 100;
```


# 8. Multi-file Programs and Linking

## math.h

```c
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

#endif
```

## math.c

```c
#include "math.h"

int add(int a, int b) {
    return a + b;
}
```

## main.c

```c
#include <stdio.h>
#include "math.h"

int main() {
    printf("%d\n", add(3, 5));
}
```

Compile:

```bash
gcc -c math.c
gcc -c main.c
gcc math.o main.o -o program
```

If the definition is missing → linker error:

```
undefined reference to add
```


# 9. Pointers

A pointer stores an address.

```c
int var = 5;
int *p = &var;

printf("var: %d\n", var);
printf("address of var: %p\n", (void*)&var);
printf("value of p: %p\n", (void*)p);
printf("dereferenced p: %d\n", *p);
```

## 9.1 Pointer Arithmetic

```c
int arr[3] = {10,20,30};
int *p = arr;

printf("%p\n", (void*)p);
printf("%p\n", (void*)(p+1));
```

`p+1` moves by `sizeof(int)` bytes.


## 9.2 Pointer to Pointer

```c
char c = 'A';
char *pc = &c;
char **ppc = &pc;
```

Type compatibility matters.


# 10. Heap and Dynamic Memory

```c
#include <stdlib.h>

int *p = malloc(sizeof(int));
*p = 10;
free(p);
```

Heap memory must be manually freed.

Common errors:

* Memory leaks
* Dangling pointers
* Double free
* Dereferencing NULL


# 11. Void Pointers

Generic pointer:

```c
void *ptr;
int x = 10;
ptr = &x;

printf("%d\n", *(int*)ptr);
```

Used in:

* malloc
* Generic libraries


# 12. Function Pointers

```c
void greet() {
    printf("Hello\n");
}

int main() {
    void (*fp)() = greet;
    fp();
}
```

Used in:

* Callback functions
* System libraries
* Event-driven programs


# 13. Reading Complex Pointer Declarations

C declarations can look confusing:

```c
int *p[5];
int (*p)[5];
int *func();
int (*func)();
```

A simple technique to read them:

> **Right–Left Rule**



## Right–Left Rule (Simplified)

To read a C declaration:

1. **Start at the variable name**
2. **Look right**
3. **Then look left**
4. Repeat until finished

Interpret symbols in order.

Symbols mean:

```text
[]  → array
()  → function
*   → pointer
```



### Example 1

```c
int *p;
```

Start at **p**

Right → nothing
Left → `*`

Result:

```text
p is a pointer to int
```

---

### Example 2

```c
int *p[5];
```

Start at **p**

Right → `[5]` → array
Left → `*` → pointer

Result:

```text
p is an array of 5 pointers to int
```

---

#### Visual View

```text
p

index
0  → int *
1  → int *
2  → int *
3  → int *
4  → int *
```

Each element is a pointer.

---

### Example 3

```c
int (*p)[5];
```

Start at **p**

Right → `[5]`
Left → `*`

But parentheses change priority.

Interpretation:

```text
p is a pointer to an array of 5 ints
```

---

## Visual Comparison

### Array of pointers

```c
int *p[5];
```

Memory idea:

```text
p

0 → int *
1 → int *
2 → int *
3 → int *
4 → int *
```

---

### Pointer to array

```c
int (*p)[5];
```

Memory idea:

```text
p → [ int int int int int ]
```

---

### Example 4

```c
int *func();
```

Start at **func**

Right → `()` → function
Left → `*` → pointer

Result:

```text
func is a function returning pointer to int
```

---

### Example 5

```c
int (*func)();
```

Start at **func**

Left → `*` → pointer
Right → `()` → function

Result:

```text
func is a pointer to a function returning int
```

---

## Why This Matters

You will often see patterns like:

```c
char *argv[]
```

in `main()`:

```c
int main(int argc, char *argv[])
```

Meaning:

```text
argv is an array of pointers to char
```

Each pointer stores a string.

---

### Common Confusion


```c
int *p[5]
```

and

```c
int (*p)[5]
```

Remember:

```text
[] binds stronger than *
```

So

```text
int *p[5]
```

means

```text
array first → then pointer
```

---

### Quick Practice

What does this mean?

```c
char *words[3];
```

Answer:

```text
words is an array of 3 pointers to char
```

Common use:

```c
char *words[3] = {"cat", "dog", "fish"};
```

---

### One More Practice

```c
int (*matrix)[5];
```

Answer:

```text
matrix is a pointer to an array of 5 ints
```

Used for **2D arrays**.


## Key Takeaway

To read complex declarations:

```text
Start at the variable name
Look right
Then look left
Repeat
```

Symbols mean:

```text
[] → array
() → function
*  → pointer
```

Parentheses change priority.


Right-left rule:

```
int (*p)[5];   → pointer to array of 5 ints
int *p[5];     → array of 5 pointers to int
int (*f)();    → pointer to function returning int
int *f();      → function returning pointer to int
```


# 14. Debugging and Memory Inspection

Compile with debug info:

```bash
gcc -g main.c
gdb ./a.out
```

Inside gdb:

```
break main
run
print x
info address x
x/4xb &x
```

Observe raw memory.


# Final Thoughts

Understanding C in systems programming means understanding:

* Memory layout
* Linking
* Object files
* Pointer arithmetic
* Alignment
* Runtime errors

C teaches you how a computer actually executes programs.

