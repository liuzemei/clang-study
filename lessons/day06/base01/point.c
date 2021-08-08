#include <stdio.h>

int main(void)
{
  char var_c = 'c';
  char *p = &var_c;
  printf("&var_c = %p\n", &var_c);
  printf("&p = %p\n", &p);
  printf("p = %p\n", p);
  printf("*p = %d\n", *p);
  printf("*p = %c\n", *p);
  return 0;
}