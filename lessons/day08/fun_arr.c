#include <stdio.h>

int total(int a[4])
{
  int sum = 0;
  int i;
  for (i = 0; i < 3; i++)
  {
    sum += a[i];
  }
  return sum;
}
int main(void)
{
  int arr[3] = {100, 88, 66};
  int t = total(arr);
  printf("sum=%d\n", t);
  return 0;
}