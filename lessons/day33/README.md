
# 1. 

phread_mutex_t 数据类型

跟这种数据类型相关的操作. 

描述这种数据类型再地址空间的布局. 描述跟这种数据类型相关的操作. 

数据结构: 
链表类型 跟链表类型相关的操作 封装数据类型
节点类型 跟节点类型相关的操作 封装数据类型



# 2. 
```c
pthread_cond_t cond = PTHREAD_COND_INITALIZER

// pthread_cond_t 就是一种数据类型
int pthread_cond_destroy(pthread_cond_t *cond); // 销毁
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr); // 初始化

int pthrea_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex);

// 一个 condition 总是和 Mutex 搭配使用
// 1. 释放 Mutex
// 2. 阻塞等待
// 3. 当被唤醒时, 重新获得 Mutex 并返回
```

信号

信号集

# 3. 信号量: 
表示可用资源的数量, 和 Mutex buts的是这个数量可以大于1 .

```c
// 初始化一个信号量 sem, 
// pshared 参数位 0 表示信号量用于同一进程的线程间同步. 
// value 表示可用资源的数量
int sem_init(sem_t *sem, int pshared, unsigned int value); 
// 可以获得资源, 使 semaphore 的值减1, 如果调用 sem_wait() 时 semaphore 的值已经是 0, 则挂起等待.
int sem_wait(sem_t *sem);
// 
int sem_trywait(sem_t *sem);

int sem_post(sem_t *sem);

int sem_destroy(sem_t *sem);
```


# 终端
1. 控制台是终端的一种.
2. 控制台是真终端.
3. 控制台 /dev/tty1-6

4. /dev/ttys001




