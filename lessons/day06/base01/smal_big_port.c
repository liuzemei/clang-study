#include <stdio.h>

int main(void)
{
  short var_a = 0x0001;
  char *p = &var_a;
  if (*p)
  {
    printf("small...\n");
  }
  else
  {
    printf("big...\n");
  }
  return 0;
}