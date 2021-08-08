#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void printSignalReceived(int signum) {
  printf("Received signal %d\n", signum);
}

int main(void) {
  // 1. 定义一个信号集 set
  sigset_t set;
  // 2. 将信号集 set 初始化为空
  sigemptyset(&set);
  // 3. 将 2/3 号信号添加到 set 信号集中
  sigaddset(&set, 3);
  // 4. 使用信号集 set 来捕捉信号
  signal(3, printSignalReceived);

  sigset_t old_set;
  sigprocmask(SIG_BLOCK, &set, &old_set);
  printf("old_set = %d\n", old_set);

  sleep(5);

  sigprocmask(SIG_UNBLOCK, &set, &old_set);
  printf("old_set = %d\n", old_set);

  return 0;
}
