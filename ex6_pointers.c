#include <stdio.h>

int main()
{
     int var = 5;
     printf("var: %d\n", var);
     // Notice the use of & before var
     printf("address of var: %p\n", &var);  
     

     int *pvar;
     pvar = &var;
     printf("value of pvar: %p\n", pvar);
       
     // To access value pointed by pvar
     printf("value %d\n", *pvar);


     // // Change value pointed by pvar

     *pvar = 1;
     // var = 1
     printf("%d\n", var);
     return 0;
}
