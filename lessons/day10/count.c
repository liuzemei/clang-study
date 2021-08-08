#include <stdio.h>
#include <laowang.h>

void count(void){
  static int cc = 1;
  cc++;
  printf("%d\n", cc);
  return ;
}

int main(void){
  int i;
  for(i=0;i<5;i++)
    count();
  return 0;
}
