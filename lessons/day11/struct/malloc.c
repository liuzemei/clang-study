#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int num;
  char name[16];
} stu_t;

int main(void)
{
  stu_t *p;
  p = (stu_t *)malloc(sizeof(stu_t));
  if (p == NULL)
  {
    printf("malloc failed...\n");
    return -1;
  }
  p->num = 102;
  strcpy(p->name, "lisi");
  printf("num:%d\tname:%s\n", p->num, p->name);
  free(p);
  printf("num:%d\tname:%s\n", p->num, p->name);
  p = NULL;
  printf("num:%d\tname:%s\n", p->num, p->name);
  return 0;
}