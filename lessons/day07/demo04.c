#include <stdio.h>

typedef int arr_t[3];

int main()
{
  int arr[2][3] = {{1, 5, 9}, {2, 6, 8}};
  printf("arr[1][1]=%d\n", *(*(arr + 1) + 1));
  printf("arr[1][1]=%d\n", *(*(arr + 2) - 2));
  printf("arr[1][1]=%d\n", *(*arr + 4));

  arr_t *p = arr;
  printf("arr[1][1]=%d\n", *(*(++p) + 1));
  // printf("arr[1][1]=%d\n", *(*(++arr) + 1)); // 常量的值不能修改。

  return 0;
}
