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
  sigaddset(&set, 2);
  // 4. 使用信号集 set 来捕捉信号
  signal(2, printSignalReceived);

  sigset_t old_set;
  sigprocmask(SIG_BLOCK, &set, &old_set);

  while(1) {
    // 检测2号信号是不是未决信号
    sigset_t pendingSet;
    sigpending(&pendingSet);
    if(sigismember(&pendingSet, 2)){
      // 如果是未决信号，则打印信号
      printSignalReceived(2);
      sleep(1);
    }
  }

  return 0;
}
