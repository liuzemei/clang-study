#include "do_trans.h"
#include "c_net.h"
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
void do_it(int pid){
  waitpid(pid, NULL,WNOHANG); // 子进程的收尸 非阻塞
}

int main(void) {
  int sockfd = s_listen(PF_INET, SOCK_STREAM, 1234);
  signal(SIGCHLD, do_it);
  if (sockfd == -1) E_MSG("s_bind", -1);
  while (1) {
    int clientfd = h_accept(sockfd);
    if (clientfd == -1) E_MSG("s_bind", -1);
    pid_t pid = fork();
    if(pid == 0) {
      close(sockfd);
      do_trans(clientfd);
      // 8. 关闭通信端点
      close(clientfd);
      exit(0);
    } else {
      close(clientfd);
      // waitpid(pid, NULL,WNOHANG); // 子进程的收尸 非阻塞
    }
  }
  return 0;
}