#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *msg = "this is a test...\n";


  int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
  if(fd==-1){
    perror("open");
    return -1;
  }
  int s_fd = dup(STDOUT_FILENO); // 保存一下的标准输出的文件描述符
  
  dup2(fd, STDOUT_FILENO); // 文件输出重定向的底层实现
  write(STDOUT_FILENO, msg, strlen(msg)+1);
  dup2(s_fd, STDOUT_FILENO); // 恢复标准输出的文件描述符。
  write(STDOUT_FILENO, msg, strlen(msg)+1); // 输出到显示器上了
  close(fd);
  return 0;
}