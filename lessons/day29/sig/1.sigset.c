#include <stdio.h>
#include <signal.h>


// 7. gcc -E 查看信号集的本质

void printIsInSet(sigset_t *set, int sig) {
  if (sigismember(set, sig) == 0) {
    printf("%d is not in set\n", sig);
  } else {
    printf("%d is in set\n", sig);
  }
}

int main(void) {
  // 1. 定义一个信号集 set
  sigset_t set;
  // 2. 将信号集 set 初始化为空
  sigemptyset(&set);
  printIsInSet(&set,2);
  printIsInSet(&set,3);
  // 3. 将 2/3 号信号添加到 set 信号集中
  sigaddset(&set, 2);
  sigaddset(&set, 3);
  // 4. 测试 2 号 和 3 号 信号 是不是 set 中的一员
  printIsInSet(&set,2);
  printIsInSet(&set,3);
  // 5. 将 3 号信号从 set 信号集中删除
  sigdelset(&set, 3);
  // 6. 测试 3 号信号是否 set 中的一员
  printIsInSet(&set,2);
  printIsInSet(&set,3);
  printf("unsigned int length is %d\n", sizeof(unsigned int));
}
