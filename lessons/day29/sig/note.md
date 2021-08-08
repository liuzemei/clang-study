
## 信号

sigaction(2)
- 信号的产生
- 信号的传送
- 设置进程对信号的阻塞
- 信号的捕获
- 信号的处理

未决状态 未处理的状态

信号阻塞和未决信号
每个进程都可以接收64个信号, 默认从父进程继承64个信号的处理程序

设置进程对信号的阻塞, 设置多个? 将需要设置的信号 放到一个集合里. 数组
```c
sigset_t // 信号集类型 系统封装的一种数据类型
// 跟这种数据类型相关的操作
sigemptyset(3)
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigismember(sigset_t *set, int signo);
```

1. 定义一个信号集 set
2. 将信号集 set 初始化为空
3. 将 2/3 号信号添加到 set 信号集中
4. 测试 2 号 和 3 号 信号 是不是 set 中的一员
5. 将 3 号信号从 set 信号集中删除
6. 测试 3 号信号是否 set 中的一员
7. gcc -E 查看信号集的本质



### 将信号集设置成进程的阻塞信号集
```c
sigprocmask(2);
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);
```
> PS: 0-31 号是不可靠信号, 在信号被屏蔽的时候, 多次收到信号只会触发一次信号处理函数. 这也叫信号的丢失.
> 31 以上的信号是可靠信号, 即使是在被屏蔽的时候, 多次收到信号, 当接触屏蔽的时候, 也会收到所有的信号.

### 如何获取未决信号
```c
sigpending(2);

int sigpending(sigset_t *set);
// set 地址空间里的内容是可以改变的
// 函数调用成功的时候, 当前进程的未决信号集就填充到 set 这个信号集中了.
// 得到这个信号集后, 在使用 sigismember 测试某些信号是不是未决信号. 
```

