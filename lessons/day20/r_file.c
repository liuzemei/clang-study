#include <unistd.h>
#include <stdio.h>
int main(void){
  char buf[128];
  int n = read(STDIN_FILENO, buf, 128); // 阻塞等待读入
  if (n < 0){
    perror("read");
    return -1;
  }
  write(STDOUT_FILENO, buf, n);
  return 0;
}