### 进程 和 程序

程序是计算机指令的集合. 存储在磁盘上的.

进程 程序执行的时候, 执行每一条指令的时候, 都有对计算机资源的一个具体的使用情况.
记录下来这个情况,每条指令执行情况不断的切换. 这个过程就是进程.

进程是动态的. 每条指令执行情况的不断切换(程序执行过程中, 对计算机使用情况的描述)

PCB 进程控制块

```c
struct task_struct{
  struct mm_struct *mm;// 进程的映像 - 代码段/数据段/栈段/堆
  pid_t pid;

  // 文件描述符表
  struct files_struct *files;

  // 信号相关信息的句柄
  struct signal_struct *signal;
  struct sighand_struct *sighand;

  // 内核链表 ()
  struct list_head tasks;

  // ...
}
```

僵尸进程: 子进程比父进程先结束，而父进程又没有回收子进程，释放子进程占用的资源，此时子进程将成为一个僵尸进程
孤儿进程: 父进程死了, 就过继给 init 的进程.

进程之间, 抢占式执行

进程的优先级 高的 时间片长一点
低的 时间片短一点

文件描述符 相同

没链接之前叫 section 链接之后 叫 segement
