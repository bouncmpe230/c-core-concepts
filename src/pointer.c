#include <stdio.h>
int main(){
    int var = 5;
    printf("var: %d\n", var);
    // Notice the use of & before var
    printf("address of var: %p \n", &var);
    int *pvar;
    pvar = &var;
    printf("value of pvar: %p\n", pvar);
    printf("address of pvar: %p\n", &pvar);
    // To access value pointed by pvar
    printf("value %d\n", *pvar);
    *pvar = 6; 

    printf("var: %d\n", var);
    printf("value of pvar: %p\n", pvar);
    printf("address of pvar: %p\n", &pvar);
    return 0;
}