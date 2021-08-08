#include <stdio.h>

typedef enum {False, True}bool_t; 
typedef enum wday {
  mon = 1,
  tue,
  wed,
  thu,
  fri,
  sat,
  sun
}w_day;


int main(void){
  w_day t;

  t=(w_day)3;
  if(t>tue){
    printf("hahaha...\n");
  }

  bool_t b;
  b=True;
  printf(b?"true":"false");
  printf("\n");
  return 0;
}
