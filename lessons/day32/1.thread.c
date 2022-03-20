#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *p_f(void *arg) {
  // pthread_self： 获取当前线程的pid

  printf("%s\t pid:%d\t tid:%lu\n", (char *)arg, getpid(), pthread_self());
  return NULL;
}

int main(void) {
  pthread_t thread;
  void *retval;

  // 创建一个新线程，线程的执行函数为 p_f
  // 线程的 tid 存储在 tid 变量的地址空间里

  pthread_create(&thread, NULL, p_f, "new thread");

  // pthread_detach(tid); // 将线程 tid 分离
  // sleep(1);
  pthread_join(thread, &retval); // 等待线程结束再往后执行

  p_f("main");

  return 0;
}
