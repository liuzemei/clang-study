#include <stdio.h>

int main(void)
{
  int var_a = 300, var_b = 400, var_c = 500;
  int *arr[3];
  arr[0] = &var_a;
  printf("arr[0]=%p\n", arr[0]);
  printf("&var_a=%p\n", &var_a);
  printf("*arr[0]=%d\n", *arr[0]);
}