#include <stdlib.h>
#include <stdio.h>

// int *func()
// {
//   int a;
//   a = 100;
//   return &a;
// }
int fund()
{
  int a;
  a = 100;
  return a;
}
int *fune()
{
  int *p = (int *)malloc(sizeof(int));
  *p = 100;
  return p;
}
int main(void)
{
  // int *p = func(); // 返回局部变量的指针会出问题的。
  // printf("*p=%d\n", *p);
  // int q = fund();
  // printf("q=%d\n", q);
  // printf("*p=%d\n", *p);

  int *p = fune();
  int q = fund();
  printf("q=%d\n", q);
  printf("*p=%d\n", *p);
  free(p);

  return 0;
}