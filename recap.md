## Recap: Core C Concepts

### Goal

Understand how **program structure, structs, pointers, and arrays** work together in C.


# Question

How can we write a program that:

1. Stores a **point (x, y)**
2. Prints it
3. Moves it

What C concepts do we need?

* program structure
* structs
* compilation & linking
* pointers
* pass-by-value vs pass-by-address


# Minimal C Program

```c
#include <stdio.h>

int main() {
    printf("Hello\n");
    return 0;
}
```

Compile and run:

```bash
gcc main.c -o program
./program
```

Key ideas:

* `#include` brings declarations
* `main()` is program entry
* program must be **compiled before execution**


# Running Example: A Point

Instead of separate variables:

```c
int x = 3;
int y = 4;
```

Group them with a **struct**:

```c
typedef struct {
    int x;
    int y;
} Point;
```

Usage:

```c
Point p = {3,4};
printf("%d %d\n", p.x, p.y);
```

# Task 1

Create a point and print it.

```c
Point p = {3,4};
printf("(%d,%d)\n", p.x, p.y);
```


# Splitting Code into Files

Real programs use **multiple files**.

```
point.h
point.c
main.c
```

# Header File

`point.h`

```c
#ifndef POINT_H
#define POINT_H

typedef struct {
    int x;
    int y;
} Point;

void print_point(Point p);
void move_point(Point *p, int dx, int dy);

#endif
```

Header files contain **declarations**.

# Implementation File

`point.c`

```c
#include <stdio.h>
#include "point.h"

void print_point(Point p) {
    printf("(%d,%d)\n", p.x, p.y);
}

void move_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
```

Source files contain **definitions**.


# Main Program

`main.c`

```c
#include "point.h"

int main() {

    Point p = {3,4};

    print_point(p);

    move_point(&p,2,1);

    print_point(p);

    return 0;
}
```


# Compiling Multiple Files

Compile together:

```bash
gcc main.c point.c -o program
```

Or step-by-step:

```bash
gcc -c main.c
gcc -c point.c
gcc main.o point.o -o program
```


# Task 2

What does this program print?

```c
Point p = {3,4};

print_point(p);

move_point(&p,2,1);

print_point(p);
```


# Why Use a Pointer?

Consider this function:

```c
void move_point(Point p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}
```


# Pass By Value

```
main memory

p = {3,4}
```

Function receives a **copy**

```
main p      function p
{3,4} ----> {3,4}
```

Changing the copy does **not** change the original.


# Pass By Address

Use a pointer:

```c
void move_point(Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}
```

Call:

```c
move_point(&p,2,1);
```

Now the function receives the **address**.


# Memory View

```
main

p = {3,4}
```

Function parameter:

```
Point *p
```

Pointer stores the address of the original struct.

```
p -----> {3,4}
```

Changing `*p` modifies the original.


# Task 3

Why does this work?

```c
p->x += dx;
```

Because

```
p->x
```

means

```
(*p).x
```

Access field through a pointer.



# Arrays and Pointers

Example:

```c
int coords[2] = {3,4};
int *ptr = coords;
```

Access elements:

```c
coords[0]
coords[1]

*(ptr)
*(ptr + 1)
```

Both refer to the same memory.


# Memory Layout

```
coords

index   value
0       3
1       4
```

Pointer:

```
ptr ---> coords[0]

*(ptr)      = 3
*(ptr + 1)  = 4
```


# Task 4

What does this print?

```c
int coords[2] = {3,4};
int *ptr = coords;

printf("%d\n", *(ptr + 1));
```


# Arrays of Pointers

So far we saw:

```c
int coords[2] = {3,4};
int *ptr = coords;
```

Now consider:

```c
int *ptrs[3];
```

This means:

> **`ptrs` is an array of 3 pointers to int**

---

# Example: Array of Pointers

```c
int a = 10;
int b = 20;
int c = 30;

int *ptrs[3];

ptrs[0] = &a;
ptrs[1] = &b;
ptrs[2] = &c;
```

Access values:

```c
printf("%d\n", *ptrs[0]);
printf("%d\n", *ptrs[1]);
printf("%d\n", *ptrs[2]);
```


# Memory View

```
Variables

a = 10
b = 20
c = 30
```

Array of pointers:

```
ptrs

index   value
0       &a
1       &b
2       &c
```

# Access Patterns

Two equivalent ways:

```c
*ptrs[i]
```

or

```c
*(ptrs[i])
```

Example:

```c
printf("%d\n", *ptrs[1]);
```


# Running Example with Points

We can store **multiple pointers to points**.

```c
Point p1 = {1,2};
Point p2 = {3,4};
Point p3 = {5,6};

Point *points[3];

points[0] = &p1;
points[1] = &p2;
points[2] = &p3;
```

Access:

```c
printf("%d\n", points[1]->x);
```



# Array of Pointers vs Pointer to Array

Two different declarations:

```
int *p[5]
```

```
array of 5 pointers to int
```

vs

```
int (*p)[5]
```

```
pointer to an array of 5 ints
```

Parentheses matter.

---

# Visual Comparison

Array of pointers

```
p

index
0 ---> int
1 ---> int
2 ---> int
3 ---> int
4 ---> int
```

Pointer to array

```
p ---> [ int int int int int ]
```

---

# Common Mistakes

Confusing:

```
int *p[5]
```

with

```
int (*p)[5]
```

Remember:

```
[] binds tighter than *
```

So:

```
int *p[5]
```

means

```
p is an array
```

---

# Why Arrays of Pointers Are Useful

They are often used for:

* **strings**

```
char *words[] = {"apple","banana","orange"};
```

* **jagged arrays**
* **tables of objects**
* **dynamic data structures**


---

# Key Takeaways

1. C programs are compiled before running.
2. Headers contain **declarations**, source files contain **definitions**.
3. `struct` groups related data.
4. A pointer stores a **memory address**.
5. Passing an address lets a function modify the original object.
6. Arrays often **decay into pointers**.
7. `int *p[5]` → array of pointers.
5. `int (*p)[5]` → pointer to array.


