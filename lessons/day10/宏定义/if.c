#include <stdio.h>

int main(void)
{
#ifdef DEBUG
  printf("hello");
#endif
  return 0;
}