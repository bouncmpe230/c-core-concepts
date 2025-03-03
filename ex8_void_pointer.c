#include <stdio.h>
int main()
{
   
   void *p;
   int x;
   char ch;
   p = &x;
   printf("address of x: %p\n", p);
   p = &ch;
   printf("address of ch: %p\n", p);
   return 0;
}
