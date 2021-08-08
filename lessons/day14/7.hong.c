#include <stdio.h>

// 将参数s直接转换为字符串
#define STR(s) #s
#define CONS(a,b) (int)(a##e##b)

int main(void){
  printf("%s\n", STR(123abc));
  printf("%d\n", CONS(2,3));
  return 0;
}