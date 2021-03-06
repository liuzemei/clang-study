## 回顾

### 如何编写自己的头文件？

头文件的内容包含那些东西

1. 头文件卫士
2. 定义宏
3. 包含其他头文件
4. 函数的声明
5. 类型的定义
6. 变量的声明

### 预处理

1. 什么是预处理？
2. 预处理指令是给谁用的？不是 c 语句，是给 预处理器 下达的指令
3. 以 `#` 开头的都是预处理指令。 宏定义、文件的包含、条件编译

## 正文

### 简介

1. 数组
   > 1. 数组是一块连续的地址空间(虚拟地址空间) - 物理地址空间可能不是连续的
   > 2. 数组里所有的成员类型一致
   > 3. 数组是用户自定义的一种数据类型
2. 结构体
   > 1. 结构体的地址空间连续
   > 2. 成员的数据类型可以不一样
   > 3. 结构体是用户自定义的一种数据类型
3. 数据类型
   > 计算机访问地址空间的一种规则

```c
struct stu{
  数据类型 成员1;
  数据类型 成员2;
};
```

描述现实世界中的事物，编程是干什么？

现实事物(物理的) -> 用数据描述现实世界中的事物 -> 逻辑事物(虚拟的)

### 举例

```c
struct date{
  unsigned int y,m,d;
};

struct person{
  unsigned int num;
  char name[16];
  char gender;
  struct date birth;
  char *addr;
  unsigned int (*get_num)(struct person *); // 等价于 (struct person *this)
  // struct person next; 这个时候还没确定 person 的占用
  struct person *next; // 访问方式就是4个字节的访问方式
};
struct person p1;
// p1 的 next 是 NULL
// p2 的 next 就是野指针
```

> 野指针也叫`悬空指针`

```c
int val;
// 全局变量，在加载的时候，为其分配空间，执行之前
// 如果全局变量没有初值或初值为0，在存储的时候，初值不存储到磁盘空间。
// 在将其加载到地址空间的时候，要为其设置初值。节省了磁盘空间，但是降低了效率。
// BSS段 未初始化的数据段。

int g_val=300; // 300这个值也会存到磁盘空间

int main(void){
  int v;
  // 局部变量, 执行到这条语句的时候，再为其分配空间。
  return 0;
}

```

### 字节对齐

### malloc

在程序执行期间，需要程序员使用相应的函数向系统申请空间。
malloc(3)... ...free(3) 需要程序员自己来管理这块地址空间。

这块空间分配在堆里(heap) 动态存储区

```c
void *malloc();
```

> 在返回地址的函数，一定要注意，地址空间的可用性(局部变量在函数结束之后就释放了。)
> malloc 之后，如果不 free 直接改变 malloc 的指针指向，那么就会发生内存泄漏。

### 链表

1. 将链表初始化为空
2. 销毁链表
