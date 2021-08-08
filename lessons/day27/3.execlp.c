#include <stdio.h>
#include <unistd.h>


int main(void) {
  // ----
  // 当前进程的映像是什么?
  // 使用 ls 的映像 替换调当前进程的映像
  // ---
  
  execlp("ls","ls","-l", NULL);// 这个函数执 行成功不返回, 错误才返回.
  perror("execlp");
  printf("test");
  
  return 0;
}