#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
  pid_t pid;
  pid=fork();
  if(pid==-1){
    perror("fork");
    return -1;
  }

  if (pid == 0) {
    printf("child process...\n");
    // 使用新的进程映像 替换 调原来的 a.out
    char *e_argv[]={"ls","-l",NULL};
    // 向量表的起始地址
    execvp("ls",e_argv); 
    perror("execlp"); // 这个语句只有在 execlp 调用失败的时候会执行.
  } else {
    wait(NULL);
  }
  return 0;
}