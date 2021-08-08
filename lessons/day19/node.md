1. 内存条是内存的一部分
2. 显卡（有显存）也是内存的一部分

> 内存分两种： ROM ，RAM
> ROM：掉电不丢失的，只读存储器。
> RAM：掉电丢失，随机存储器。

每一个芯片上，至少得有一个 ROM，ROM 上有一些程序，

硬件生产商给我们提供的 ROM 程序。

代码的功能接受命令，根据命令将数据存储到响应的磁盘位置。

```js

```

寄存器

段寄存器
CS
DS
ES
SS

编译程序的时候，程序中相同的部分归为一个 section

一个程序中有多个 section 构成

每个 section 都是一个区间。一个程序由多个 section 构成
text 代码区间 -- 代码 或 常量
data 数据区间 -- 变量
stack 栈区间

链接的时候认的是 section

加载的时候认的是 segement

链接脚本：
ld --verbose // 静态链接器

readelf a.out

```c
// segment 是一个结构体

struct segment seg[8192]; // 段描述符表

// 每个元素都是 段描述符像

struct segment {
  属性;
  start;
  end;
}

struct segment data; // 数据段
struct segment text; // 代码段

// 段选择子

// 段描述符 最多有 8192 个
cs ds ss


cat /proc/${pid}/maps
```

压栈的时候，函数的参数 和 局部变量
