#include <stdio.h>
int main()
{
   
   char *p;
   int *px;
   int x = 123123;
   p = &x;
   px = &x;
   //p = (char *)&x;
   printf("%d\n", *p);
   printf("%d\n", *px);
   return 0;
}
