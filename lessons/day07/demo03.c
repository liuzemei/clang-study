#include <stdio.h>

// argc 代表命令行字符串的个数 argv 就是个字符串列表
int main(int argc, char *argv[])
{
  printf("argc=%d\n", argc);
  int i;
  for (i = 0; i < argc; i++)
    printf("argv[%d]=%s\n", i, argv[i]);
  return 0;
}
