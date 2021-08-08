#include <stdio.h>
#include <unistd.h>
#include <signal.h>
unsigned int my_sleep(unsigned int seconds);

void s(){}

unsigned int my_sleep(unsigned int seconds){
  // 进程的状态是 sleep...
  signal(SIGALRM, s);// 不使用默认的信号处理函数 (默认的信号处理函数, 就直接终止进程了...)
  int time = alarm(seconds);
  if (time != 0) return time;
  pause(); // 阻塞等待信号的到来
  return alarm(0);// 如果被别的信号打断, 那么这个函数会取消 sleep 的计时器, 并返回 剩余的时间
}


int main(void){
  // 进程的状态是 sleep...
  printf("start...\n");
  my_sleep(2);
  printf("end...\n");
  return 0;
}
