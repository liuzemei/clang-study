#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  char buf[128];
  int r = read(fd, buf, 128);
  write(STDOUT_FILENO, buf, r);
  close(fd);
  return 0;
}