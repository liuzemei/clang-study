#include <stdio.h>


int main(void){
  // int a = 8;
  // printf("%d\n", a<<2);
  // printf("%d\n", a>>1);

  int a = 130;
  int b = a>>4;
  int c = ~(~0<<4); // #0000 1111

  int result = b & c;

  printf("%d\n", result);
  
  
  
  return 0;
}