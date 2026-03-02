#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>

struct Example {
    char   c;
    int    x;
    char   d;
    double y;
};

struct Example2 {
    double y;
    int    x;
    char   c;
    char   d;
};

void inspect_example() {
    printf("==== struct Example ====\n");

    struct Example e;

    printf("sizeof = %zu\n", sizeof(struct Example));
    printf("alignof = %zu\n", alignof(struct Example));

    printf("Offsets:\n");
    printf("  c: %zu\n", offsetof(struct Example, c));
    printf("  x: %zu\n", offsetof(struct Example, x));
    printf("  d: %zu\n", offsetof(struct Example, d));
    printf("  y: %zu\n", offsetof(struct Example, y));

    printf("Addresses:\n");
    printf("  &e      = %p\n", (void*)&e);
    printf("  &e.c    = %p\n", (void*)&e.c);
    printf("  &e.x    = %p\n", (void*)&e.x);
    printf("  &e.d    = %p\n", (void*)&e.d);
    printf("  &e.y    = %p\n", (void*)&e.y);

    printf("\n");
}

void inspect_example2() {
    printf("==== struct Example2 ====\n");

    struct Example2 e;

    printf("sizeof = %zu\n", sizeof(struct Example2));
    printf("alignof = %zu\n", alignof(struct Example2));

    printf("Offsets:\n");
    printf("  y: %zu\n", offsetof(struct Example2, y));
    printf("  x: %zu\n", offsetof(struct Example2, x));
    printf("  c: %zu\n", offsetof(struct Example2, c));
    printf("  d: %zu\n", offsetof(struct Example2, d));

    printf("Addresses:\n");
    printf("  &e      = %p\n", (void*)&e);
    printf("  &e.y    = %p\n", (void*)&e.y);
    printf("  &e.x    = %p\n", (void*)&e.x);
    printf("  &e.c    = %p\n", (void*)&e.c);
    printf("  &e.d    = %p\n", (void*)&e.d);

    printf("\n");
}

int main() {
    inspect_example();
    inspect_example2();
    return 0;
}

// 64-bit 

// ==== struct Example ====
// sizeof = 24
// alignof = 8
// Offsets:
//   c: 0
//   x: 4
//   d: 8
//   y: 16
// Addresses:
//   &e      = 0xffffdf660fc0
//   &e.c    = 0xffffdf660fc0
//   &e.x    = 0xffffdf660fc4
//   &e.d    = 0xffffdf660fc8
//   &e.y    = 0xffffdf660fd0

// ==== struct Example2 ====
// sizeof = 16
// alignof = 8
// Offsets:
//   y: 0
//   x: 8
//   c: 12
//   d: 13
// Addresses:
//   &e      = 0xffffdf660fc8
//   &e.y    = 0xffffdf660fc8
//   &e.x    = 0xffffdf660fd0
//   &e.c    = 0xffffdf660fd4
//   &e.d    = 0xffffdf660fd5


// 32-bit

