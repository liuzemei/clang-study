#include <stdio.h>
#include <unistd.h>
int main(void) {
  int i;
  // 设置闹钟为1秒后触发
  alarm(5);

  // 循环到1s时, 进程会收到SIGALRM信号, 并终止
  for (i=1;i<50000;i++)
    printf("i=%d\n", i);

  // alarm(0) 取消原来的闹钟 之后
  int ret = alarm(0);
  printf("ret=%d\n", ret);

  // 将闹钟重新设置为 9 秒, 原来的闹钟就取消了. 新的闹钟起作用. 
  // ret 中保存了上个闹钟的剩余时间的秒数, 称为上个 alarm 的未决时间值. 
  ret = alarm(2);
  while(1);
  return 0;
}