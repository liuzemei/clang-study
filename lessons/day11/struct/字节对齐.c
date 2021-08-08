#include <stdio.h>

// typedef struct
// {
//   char n;
//   char m;
//   short g; //   int age;
// } __attribute__((packed)) d_t;
typedef struct
{
  char n;
  int age;
} d_t;
int main(void)
{
  printf("len=%lu\n", sizeof(d_t));
  return 0;
}