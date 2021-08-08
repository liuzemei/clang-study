# 错误处理

库函数和系统调用出现错误的时候，会设置一个全局变量 errno。 int 类型的。

设置一个值。可以根据 errno 的值获取错误的描述信息。

strerror(3) perror(3)

```
# 和 ## 的用法
```

### 可变参数

```c
int printf(const char *format, ...);
... 参数的个数和每个参数的类型 都取决于 format


```
