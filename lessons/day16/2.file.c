#include <stdio.h>
typedef struct data{
  unsigned a:3;
  unsigned b:4;
  unsigned :1;
  unsigned g:2;
  unsigned e:4;
  unsigned h:2;
  unsigned f:5;
  int i;
}data_t;


int main(void){
  data_t d;
  d.a=5;
  d.b=13;
  d.g=3;
  d.e=0;
  d.h=0;
  printf("%d\n",sizeof(data_t));
  printf("%d\t%d\n",d.a,d.b);
  char *p=(char *)&d;
  printf("%x\n",*p);
  p++;
  printf("%x\n",*p);
  return 0;
}