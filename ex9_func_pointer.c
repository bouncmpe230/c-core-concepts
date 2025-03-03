#include <stdio.h>
void my_int_func(int x)
{
   printf( "%d\n", x );
}

void func_no_param(){
   printf("Hello!");
}


int main()
{
   void (*foo)(int);
   
   void (*pfunc)();

   foo = &my_int_func;

   (*foo)( 2 );

   pfunc = &func_no_param;

   (*pfunc)();

   return 0;
}
