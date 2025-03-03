#include <stdio.h>

#define N 50

// Define an enumeration
enum Color { RED, GREEN, BLUE };

// Define a structure
// struct Point {
//     int x;
//     int y;
// };

// alias
typedef struct Point {
    int x;
    int y;
} point;


int main() {
    int x = N;
    int y = 85;   /* decimal */
    int z = 0213; /* octal */
    int t = 0x4b; /* hexadecimal */
    float a = 3.14159;
    double b = 314159E-5L; /* Exponent: 314159 x 10^(-5) */
    char ch = 'a';

    // Using the enum
    enum Color favoriteColor = BLUE;

    // Using the struct
    struct Point p1;
    p1.x = 10;
    p1.y = 20;

    struct Point p2 = {10, 20}; 

    point p3 = {10, 20};


    // Print integer values
    printf("value of x: %d, size of x: %lu bytes\n", x, sizeof(x));
    printf("value of y: %d, size of y: %lu bytes\n", y, sizeof(y));
    printf("value of z: %d, size of z: %lu bytes\n", z, sizeof(z));
    printf("value of t: %d, size of t: %lu bytes\n", t, sizeof(t));

    // Print floating-point values
    printf("value of a: %f, size of a: %lu bytes\n", a, sizeof(a));
    printf("value of b: %lf, size of b: %lu bytes\n", b, sizeof(b));

    // Print character value
    printf("value of ch: %c, ASCII: %d, size of ch: %lu bytes\n", ch, ch, sizeof(ch));

    // Print enum value
    printf("Favorite color: %d (0=RED, 1=GREEN, 2=BLUE), size of enum: %lu bytes\n", favoriteColor, sizeof(favoriteColor));

    // Print struct values
    printf("Point coordinates: (%d, %d), size of struct: %lu bytes\n", p1.x, p1.y, sizeof(p1));
    printf("Point coordinates: (%d, %d), size of struct: %lu bytes\n", p2.x, p2.y, sizeof(p2));
    printf("Point coordinates: (%d, %d), size of struct: %lu bytes\n", p3.x, p3.y, sizeof(p3));

    return 0;
}
