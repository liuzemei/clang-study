### crond 定时任务 服务

###

```shell
man 3 库函数
```

### 常量和变量

不管是常量还是变量，都有自己的内存空间

#### 如何去访问变量或常量的内存空间呢？

1. 通过变量的名字找到变量的地址，然后取出这个地址空间里的内容。
2. 

#### 常量和变量的区别

1. 常量内存空间里的值是不能改变的
2. 变量内存空间里的值是可以改变的

#### 存储单元

1. 存储单元的最小单位是字节。

32bit 机(32 位机) -> 32 根地址线 -> 2 的 32 次方(4G)

地址范围： 0 ~ 4g-1

2. 变量指向一个内存地址，

3. 类型决定这个变量占用几个内存地址

4. 大端：高位字节低地址 小端：地位字节高地址

#### 数据类型

|-|-|
|名称|字节数|
|char|1 字节|
|short|2 字节|
|int|4 字节|
|long|8 字节|