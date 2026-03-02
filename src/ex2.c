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