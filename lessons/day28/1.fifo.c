#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

// 创建一个管道文件, 文件的名字通过 argv[1] 传递给 main 函数
int main(int argc, char *argv[]) {
  int ff = mkfifo(argv[1], 0666);
  if (ff == -1) {
    perror("mkfifo");
    return 1;
  }
  printf("fifo file %s created...\n", argv[1]);
  return 0;
}