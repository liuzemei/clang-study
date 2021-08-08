#include <stdio.h>

void test() {}

int testInt = 100;
int main()
{
  printf("testInt: %p\n", &testInt);
  printf("test: %p\n", &test);
  int a = 1;
  int b = 2;
  return 0;
}