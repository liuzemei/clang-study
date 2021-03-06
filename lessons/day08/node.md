函数 不带参数的函数
带参数的函数
实参初始化形参

传值： 将某个变量或常量的值初始化形参
传址： 使用变量或常量的地址初始化形参

1. 数组作为函数的参数，如何传递的？

```

```

> 数组作为函数形参的时候，传参的时候，自动转换为指针。

2. 返回地址的函数 返回类型是指针类型的函数（涉及到 返回的地址 还是否有效？）

```c
int p_add(int x, int y);
int p_sub(int x, int y);
int p_div(int x, int y);
int p_mul(int x, int y);
```

> 返回值类型、函数参数个数、每个参数的类型都一样。一种数据类型，就是这种函数的数据类型。函数也是用户自定义的一种数据类型。

```c
int p_m(int x, int y);
// p_m 是常量    int(int, int); 这就是函数的数据类型
typedef int p_m(int, int);
// p_m 就是函数的数据类型的别名
p_m *p; // p是指针类型的变量，对p的内容这个地址方位的时候，遵循 p_m 这种函数数据类型的访问规则。

int (*q)(int, int);
// q 是指针类型的变量
// 对 q 变量的内容这个地址访问

```

> 数组和函数都是用户自定的数据类型。结构体、枚举、联合都是用户自定义的数据类型。

```c
int p;
int *p;
int *p[3];
int (*p)[3];
int (*p_m)(int, int);
int (*p_m[4])(int, int); // 函数指针数组
void *malloc(...); // 返回值为指针类型的函数
```

###

1. 我们做一个工程的时候, 分成多个模块
   降低了工程师的难度，由工程师完成各个模块
   最后将这多个模块整合，形成一个完整的系统
   一个模块里可以包含 0 个或任意个函数
2. 编写完模块代码以后 -> 编译这个模块(源文件) -> `gcc -c xxx.c`
   单元测试(检查语法错误，编译的基本单位是源文件)
   会生成一个 `xxx.o` 文件（源文件）
3. 链接各个模块 `gcc *.o` -> 将目标文件链接生成可执行文件 hello

```shell
nm xxx.o # 获取相对内存地址
nm xxx # 获取绝对内存地址

file xxx # 可执行文件
file xxx.o # 需要文件重定向(硬链接)
```

### 链接的原理

1. 静态链接：发生在生成可执行文件的时候
2. 动态链接：将程序加载到内存，运行程序的时候

### 运行和执行

1. 运行：将可执行程序加载到内存
2. 执行：找到程序的入口(main 函数 - 回答了一半)，执行程序。
