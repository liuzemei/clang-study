#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// 遗言函数
void byebye(int n ,void *desc){
  printf("n=%d desc=%s\n", n, (char *)desc);
  return;
}

void goodbye(void){
  printf("goodbye...\n");
  return;
}
void byebye1(void){
  printf("bye...bye1...\n");
  return;
}

void goodbye1(void){
  printf("goodbye1...\n");
  return;
}

int main(void){
  // 进程正常的时候注册遗言函数
  on_exit(byebye, "test"); // 将函数 byebye 注册给进程, 作为该进程的遗言函数. 
  // on_exit(goodbye); // 注册一次, 调用一次, 注册两次, 就会调用两次

  pid_t pid = fork();
  if(pid==0){
  // on_exit(byebye1); // 将函数 byebye 注册给进程, 作为该进程的遗言函数. 
  // on_exit(goodbye1); // 注册一次, 调用一次, 注册两次, 就会调用两次
  }

  printf("pid::%d\n", pid);
  return 0;
}

