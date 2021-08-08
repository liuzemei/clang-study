#include <stdio.h>

int main(int argc, char* argv[]){
  FILE *p = fopen(argv[1], "r");
  if(p==NULL){
    printf("open file error...\n");
    return -1;
  }

  int ret;

  fscanf(p, "hello...%d\n", &ret);
  printf("结果为：%d\n", ret);
  fclose(p);


  
  
  return 0;
}