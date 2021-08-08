#include <stdio.h>

int main(void){
  const int a = 300;

  // a = 200; // error
  int *p = &a;
  *p = 200;

  printf("%d\n",a);
  printf("%d\n",*p);

  return 0;
}