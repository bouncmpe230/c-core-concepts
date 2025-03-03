#include <stdio.h>

int main(){
   char c = 'A';
   char *pc = &c;
   char **ppc = &pc;
   printf("address of c %p\n", pc);
   printf("address of pc %p\n", ppc);
   
   int x = 5;
   int *px = &x;
   ppc = &px; // Not valid! types do not match! (char **, int **)
   return 0;
}
