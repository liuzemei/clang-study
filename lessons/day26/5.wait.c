#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

  pid_t pid = fork();
  if (pid == -1){
    perror("fork");
    return -1;
  }

  int s;
  
  if (pid == 0){
    printf("child process...\n");
    // 父进程回收子进程
    // sleep(30);
    printf("child process end...\n");
    return 3;
  } else {
    // 子进程先死, 父进程没死且不回收就变成僵尸进程. 
    sleep(30);
    int w = wait(&s);
    if(-1==w) {
      perror("wait");
      return -1;
    }
    if (WIFEXITED(s)) printf("exit code:%d\n", WEXITSTATUS(s));
    if (WIFSIGNALED(s)) printf("exit signal:%d\n", WTERMSIG(s));
    printf("parent process... \n");
  }
  
  
  return 0;
}