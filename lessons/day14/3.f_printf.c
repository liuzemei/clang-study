#include <stdio.h>

int main(int argc, char* argv[]){
  FILE *p = fopen(argv[1], "w");
  if(p==NULL){
    printf("open file error...\n");
    return -1;
  }

  fprintf(p, "hello...%d\n",300);
  fclose(p);


  
  
  return 0;
}