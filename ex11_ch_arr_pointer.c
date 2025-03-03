#include <stdio.h>

int main () {

  /* an array with 5 elements */
  char letters[5] = {'a', 'b', 'c', 'd', 'e'};
  char *p;
  int i;

  p = letters;

  /* output each array element's value */

  for ( i = 0; i < 5; i++ ) {
     printf("*(p + %d) : %c associated address %p\n",  i, *(p + i) , p + i);
  }

  return 0;
}


