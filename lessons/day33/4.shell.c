#include <unistd.h>
#include <stdio.h>

int main()
{
  printf("fd0 : %s\n", ttyname(0));
  printf("fd1 : %s\n", ttyname(1));
  printf("fd2 : %s\n", ttyname(2));
}
