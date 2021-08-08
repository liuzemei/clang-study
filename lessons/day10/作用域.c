#include <stdio.h>

void count(void){
  static int cc=1;
  cc++;
  printf(123);
}