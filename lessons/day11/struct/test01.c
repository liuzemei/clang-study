#include <stdio.h>
#include <string.h>

typedef struct
{
  unsigned int y, m, d;
} d_t;

typedef struct person
{
  unsigned int num;
  char name[16];
  char sex;
  d_t birth;
  char *addr;
  unsigned int (*get_n)(struct person *);
  struct person *next;
} p_t;

p_t p1;
unsigned int get_num(p_t *this)
{
  return this->num;
}

int main(void)
{
  p_t p2;
  p_t *q;
  q = &p2;
  p2.num = 101;
  q->sex = 'M';
  p2.birth.y = 1998;
  q->birth.m = 10;
  q->birth.d = 29;
  p2.next = NULL;
  p2.get_n = get_num;
  q->addr = "beijing gugong"; // 字符串的首地址给了 p2.addr
  // q->name = "test"; // 数组的首地址不能改变，所以就报错了
  strcpy(q->name, "list");
  printf("num:%d\tsex:%c\tbirth:%u-%u-%u\n", q->num, p2.sex, p2.birth.y, q->birth.m, p2.birth.d);
  // p2.next的空间里有数据，但是这个数据是多少，不确定。（野指针）
  // p1.next的空间里有数据吗？有，初始值为 NULL。
  printf("name: %s\t addr=%s\n", q->name, q->addr);
  printf("num:%u\n", p2.get_n(q));
  return 0;
}
