#include <stdio.h>

int main(void)
{
  printf("int length is %lu\n", sizeof(int));
  printf("char length is %lu\n", sizeof(char));
  printf("short length is %lu\n", sizeof(short));
  printf("long length is %lu\n", sizeof(long));
  return 0;
}