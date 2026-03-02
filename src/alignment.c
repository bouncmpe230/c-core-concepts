#include <stdio.h>
#include <stddef.h>   // offsetof
#include <stdalign.h> // alignof (C11)

struct Example {
    char   c;
    char   d;
    int    x;
    double y;
};

int main(void) {
    struct Example e = {'A', 42, 'B', 3.14};

    printf("sizeof(struct Example) = %zu\n", sizeof(e));

    printf("Addresses:\n");
    printf("  &e      = %p\n", &e);
    printf("  &e.c    = %p\n", &e.c);
    printf("  &e.d    = %p\n", &e.d);
    printf("  &e.x    = %p\n", &e.x);
    printf("  &e.y    = %p\n", &e.y);

    char *p = (char *)&e;

    p = p + 1; 


    *p = 'z';

    printf("%p %c\n", p, *p);
    printf("%p %c\n", &e.c, e.c);

    return 0;
}