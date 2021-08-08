#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
  // 打开文件，以写方式打开
  FILE *fp = fopen(argv[1], "w");
  if(!fp){
    printf("fopen failed...\n");
    return -1;
  }

  char buf[128];
  char *str = "happy new year";
  // 1. 将 str 中的字符串写入到文件中
  // fputs(str, fp);

  // // 2. 从 键盘输入 字符串， 将输入的字符串存放到文件中
  // char key;
  // puts("请输入字符:...\n");

  // // scanf("%s", &key);
  // gets(&key);
  // fputs(&key, fp);

  char *p;
  while(1){
    p = fgets(buf, 128, stdin);
    // 当只有一个 \n 的时候 就 break
    if(strlen(p)==1) break;
    fputs(p,fp);
  }
  
  // 关闭文件流
  fclose(fp);
  return 0;
}