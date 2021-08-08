#include <stdio.h>

int main()
{
  typedef char *str_t;
  str_t s1, s2;
  printf("%p %p \n", &s1, &s2);
  char *s3, *s4;
  printf("%p %p \n", &s3, &s4);
  typedef int arr_t[3];
  int arr[3];
  
  return 0;
}