#include <stdio.h>
#include <stdarg.h>
void myprintf(const char *format, ...){
  va_list ap;
  char c;
  char ch;
  char *p;
  va_start(ap, format);
  while(c=*format++){
    switch (c) {
    case 'c': 
      ch = va_arg(ap, int);
      putchar(ch);
      break;
    case 's': 
      p = va_arg(ap, char*);
      fputs(p, stdout);
      break;
    default:
      putchar(c);
    }
  }
  va_end(ap);
}
int main(void){
  myprintf("c\ts\n", '1', "hello");
  return 0;
}
