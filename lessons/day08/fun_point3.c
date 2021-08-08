#include <stdio.h>

typedef int p_m(int x, int y);
int p_add(int x, int y)
{
  return x + y;
}

int p_mul(int x, int y)
{
  return x * y;
}
int main(void)
{
  p_m *p;
  p = p_mul;
  int val_a = 6, val_b = 12;
  printf("%d*%d=%d\n", val_a, val_b, p(val_a, val_b));
  return 0;
}