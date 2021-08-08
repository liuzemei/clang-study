#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void){
  char buf[128];
  int fd = open("/dev/tty", O_RDONLY|O_NONBLOCK); // 非阻塞读取
  // int fd = open("/dev/tty", O_RDONLY); // 阻塞读取
  if(fd == -1) {
    perror("open file");
    return -1;
  }
  int n = read(fd, buf, 128);// 非阻塞读取
  if(n<0){
    perror("read");
    return -1;
  }
  write(STDOUT_FILENO, buf, n);
  return 0;
}