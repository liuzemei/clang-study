#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int fd = open(argv[1], O_WRONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  char *msg = "this is a test \n";
  write(fd, msg, strlen(msg));
  return 0;
}