#include <stdio.h>
int main()
{
    char *p;
    int x;
    // raise a warning
    //p = &x;
    // type casting 
    p = (char *) &x; 
    return 0;
}