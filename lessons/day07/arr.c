#include <stdio.h>
typedef int arr_t[3];

int main()
{
  arr_t a = {1, 2, 3};
  printf("a[0]=%d\n", a[0]);
  printf("a[1]=%d\n", a[1]);
  printf("a[2]=%d\n", a[2]);

  int arr[3] = {2, 3, 4};
  printf("arr[0]=%d\n", arr[0]);
  printf("arr[1]=%d\n", arr[1]);
  printf("arr[2]=%d\n", arr[2]);

  int *p = arr;
  printf("p length is %d \n", sizeof(p));
  printf("arr length is %d \n", sizeof(arr));
}