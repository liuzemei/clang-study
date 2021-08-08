#include <stdio.h>

int total(int a[], int len)
{
  int sum = 0;
  int i;
  for (i = 0; i < len; i++)
  {
    sum += a[i];
  }
  return sum;
}
int main(void)
{
  int arr[] = {100, 88, 66, 11};
  int t = total(arr, sizeof(arr) / sizeof(int));
  printf("sum=%d\n", t);
  return 0;
}