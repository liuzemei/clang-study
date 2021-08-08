#include <stdio.h>
#include <stdlib.h>

int main(void){
  // 如果环境变量不存在, 将其添加到环境变量中  
  int sv = setenv("Caption", "beijing", 0);
  if (sv == -1){
    printf("set env failed...");
    return -2;
  }
  
  printf("%d\n", sv);
  char *v = getenv("Caption");
  if (v!=NULL){
    printf("Caption=%s\n",v);
  }

  unsetenv("Caption");

  v = getenv("Caption");
  if (v!=NULL){
    printf("Caption=%s\n",v);
  }

  clearenv();
  v = getenv("Caption");
  if (v!=NULL){
    printf("Caption=%s\n",v);
  }
  
  return 0;
}