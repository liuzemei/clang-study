#include <stdio.h>
extern int value;
static void count(void)
{
  printf("value=%d\n", value);
  return;
}