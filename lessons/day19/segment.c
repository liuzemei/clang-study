#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int g_val=300;


int main(){
  pid_t  pid=getpid();

  printf("pid=%d\n",pid);
  printf("&pid=%p\n",&pid);
  printf("&g_val=%p\n",&g_val);

  getchar();
  return 0;
}