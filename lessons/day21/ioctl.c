#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main(void) {
  if (isatty(STDOUT_FILENO) == 0) exit(1);

  struct winsize size;
  int fd = ioctl(STDOUT_FILENO,TIOCGWINSZ, &size);
  if (fd == -1) {
    perror("ioctl");
    return -12;
  }

  printf("row: %d, col: %d\n", size.ws_row, size.ws_col);

  return 0;
}