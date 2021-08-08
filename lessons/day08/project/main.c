#include <stdio.h>

typedef int p_m(int x, int y);
int p_add(int x, int y);
int p_sub(int x, int y);
int p_mul(int x, int y);
int p_div(int x, int y);
int process(p_m *p, int x, int y)
{
  return p(x, y);
}
int main(void)
{
  p_m *p;
  p = p_mul;
  int val_a = 6, val_b = 12;
  p_m *arr[] = {p_add, p_mul, p_sub, p_div};
  int i;
  for (i = 0; i < 4; i++)
  {
    printf("result=%d\n", process(arr[i], val_a, val_b));
  }
  return 0;
}