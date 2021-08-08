#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signum) {
    printf("Received signal %d\n", signum);
    return;
}

int main(void) {
  signal(2, sig_handler);
  // 子进程继承父进程的信号处理函数

  pid_t pid = fork();
  if (pid == 0) {
    // 子进程
    printf("I am child process\n");
  } else {
    // 父进程
  }
  while(1);
  return 0;
}