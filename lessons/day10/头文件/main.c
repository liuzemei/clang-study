#include <stdio.h>
#include "pmath.h"

int main(void)
{
  int v_a = 6, v_b = 2;
  printf("%d+%d=%d\n", v_a, v_b, p_add(v_a, v_b));
  printf("%d*%d=%d\n", v_a, v_b, p_mul(v_a, v_b));
  return 0;
}