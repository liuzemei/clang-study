#include <stdio.h>

#define PI 3.1415
#define AREA1(r) PI *r *r     // 带参数的宏定义
#define AREA(r) PI *(r) * (r) // 带参数的宏定义
#define ARR_C(arr) sizeof(arr) / sizeof(arr[0])

int main(void)
{
  int r = 5;
  double zc = PI * 2 * r;
  printf("zc=%.2f\n", zc);
  double area = AREA(3 + 2);
  printf("area=%.2f\n", area);
  // #undef AREA(r)
  // double area = AREA(3 + 2);
  printf("area=%.2f\n", area);

  char str[0];
  printf("counts of str is %d\n", ARR_C(str));

  printf("file:%s\t func: %s\t line:%d\n", __FILE__, __func__, __LINE__);

  return 0;
}