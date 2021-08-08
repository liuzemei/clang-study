进程映像的更新

进程的映像 ELF 可执行文件 脚本文件

进程中环境变量的操作

进程间通讯 管道 有名管道 无名管道

当我们在 PA 进程中调用 fork 时,就把进程的 PCB 复制了一份, 这样我们就有了另外一个进程 PB,此时只有 PID 不一样, 其他的都相同.

- 文件描述符
- 进程的映像
- 信号的处理函数

exec(3) 家族的函数来完成

```c
// 替换了原来的进程映像.
int execve(const char *path, char *const argv[], char *const envp[]);
// 向量表: 如果元素的地址连续.
// 列表: 元素的地址不一定连续.
```

每个进程都有自己的环境变量
环境变量是通过父进程继承过来的.

```c

#include <unistd.h>
extern char **environ;
// 如果指定了l, list
// 如果指定了v, vendor
// 如果指定了p, 就会去PATH的环境变量去找这个文件
// 如果有 e, 就需要传递新的环境变量
int execl(const char *path, const char *arg0, ... /*, (char *)0 */);
int execle(const char *path, const char *arg0, ... /*, (char *)0, char *const envp[] */);
int execlp(const char *file, const char *arg0, ... /*, (char *)0 */);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvP(const char *file, const char *search_path, char *const argv[]);
```

所有的父子进程都是通过

- fork(创建子进程)
- exec(更换进程映像)

获取环境变量的值

```c
char *getenv(const char *name);
```

### bash 命令

bash 命令分为两种

内部命令
外部命令

a.out 就是 bash 的外部命令

cd 这个命令的代码就是 bash 程序的一部分而已. 在 bash 提示符下, 执行 cd 命令的时候, 就不用 fork 了.

### 进程间通信

PA 和 PB 有各自的地址空间, 独立的

PA 和 PB 这两个进程需要合作完成一些事情.

这两个进程就需要通信.

操作系统运行进程, 是分时运行的.

不管是 PA 还是 PB 都有 1G 的地址空间, 映射的是 kernel 部分.

--> PA 和 PB 通信, 只能通过内核地址.

如何创建地址空间? (怎么写,怎么读)

```c
// man 2 pipe

int pipe(int fildes[2]);

```

PA 进程 调用 pipe 返回了 两个文件描述符, 但是 PB 进程还不知道.

如何让 PB 进程知道呢?

PA 进程 调用 fork(2) 创建子进程 PB,

PB 就继承了 PA 的文件描述符. 