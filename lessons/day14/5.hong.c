#include <stdio.h>
#include <errno.h>
#include <string.h>

#define E_MSG(s,val) do{perror(s);return val;}while(0)

int main(int argc, char *argv[]){
  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL) E_MSG("fopen...", -1);
  fclose(fp);
  return 0;
}
