#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
  int fd[2];
  // 1. 先创建一个管道, 返回一个文件描述符
  int pp=pipe(fd);
  if (pp<0) {
    perror("pipe");
    return -1;
  }
  // 到这里 fd[0] 管道的读端 fd[1] 管道的写端
  // 创建子进程, 子进程继承父进程的文件描述符
  pid_t pid=fork();
  if (pid<0) {
    perror("fork");
    return -1;
  }
  // 管道的流向是单向的, 只能从一端发送数据, 从另一端接收数据.
  // 子进程只能从管道的读端读, 父进程只能从管道的写端写
  if (pid==0) {
    // 子进程 关闭管道的写端
    close(fd[1]);
    // 从管道的读端读
    char buf[1024];
    // 从管道的读端读,阻塞, 如果管道中没有数据, 则阻塞
    ssize_t n=read(fd[0], buf, sizeof(buf));
    if (n<0) {
      perror("read");
      return -1;
    }
    printf("read %d bytes from pipe: %s \n", n, buf);
    close(fd[0]);
    exit(0);
  } else {
    // 父进程 关闭管道的读端
    close(fd[0]);
    char *msg = "this is test msg...\n";
    // 父进程向管道写入数据, 如果管道满了, 就阻塞
    // 这里 +1 是为了把 \0(字符串结束符) 也写入管道
    write(fd[1], msg, strlen(msg)+1);
    // 等待子进程结束,回收子进程的资源
    close(fd[1]);
    wait(0);
  }

  
  return 0;
}