#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
  // 打开文件，以只读方式打开
  FILE *fp = fopen(argv[1], "r");
  if(!fp){
    perror("出问题了...");
    // printf("fopen failed...%d %s\n", errno, strerror(errno));
    // printf("fopen failed...%d\n", errno);
    return -1;
  }
  // 从文件读取字符串，将字符串存放到 buf 中
  char buf[128];

  char *p;
  // do {
  //   p = fgets(buf,128,fp); // 读一行
  //   printf("%s", buf);
  // }while(p!=NULL);

  while(1){
    char *p = fgets(buf,128,fp);
    if(p==NULL) break;
    printf("buf:%s", buf);
  };
  

  fclose(fp);


  
  return 0;
}