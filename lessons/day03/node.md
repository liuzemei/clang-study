硬盘由 1~n 张盘片构成
每个面都有一个磁臂，
磁臂上有磁头
磁头沿着磁臂做水平运动(盘片的半径)

磁道：盘片有一个一个的同心圆

磁柱：叠加的磁道

扇区：一个扇区 512 字节

分区：划分磁头的运动范围

```shell
fdisk -l # 查看磁盘分区
```

最多分为 3 个主分区和一个扩展分区

可以在扩展分区上继续进行逻辑分区

```shell
fdisk /dev/sda # 先创建扩展分区，再在扩展分区的基础上创建逻辑分区
```

`sda`: 第一块硬盘
`sdb`: 第二块硬盘

ext2 ext3 vfat => id=83

#### 对分区(文件系统)进行格式化

```shell
mkfs -t ext3 /dev/sda5 # 对 sda5 和进行 ext3 格式化
```

#### 挂载分区

`/mnt/hgfs` => `虚拟机和宿主机共享的文件夹`

```shell
mount -t ext3 /dev/sda5 /mnt #
mount -t loop
```

#### 卸载分区

```shell
umount /mnt
```

#### 第一个扇区

`0道0扇`-> `512字节` -> `0~511`
`0~445`: 存放 grub(bootloader)
`445~`(64 字节):一个分区的描述信息是 16 个字节，所以这里最多可以分为 4 个主分区，逻辑分区不记录在这 64 个字节里边
`~511`(2 字节)：结束

> bootloader:引导程序的统称, grub 是 bootloader 的一种

>

#### 开机挂载

`/etc/fstab`

#### 新建特殊装置

建立设备 200M 的特殊设备

```shell
dd if=/dev/zero of=/tmp/loopdev bs=1024k count=200 # 特殊装置 loop 内存分配
mount -t ext3 -o loop /tmp/loopdev /mnt/loopdev # 挂载 loop 设备
```

#### 扩充虚拟内存

```shell
dd if=/dev/zero of=/tmp/swap bs=4k count=16384 #
mkswap /tmp/swap # 格式化 swap 分区
free # 查看分区的空间 (包含swap)
swapon /tmp/swap # 打开 swap 分区
free # 再次查看（发现增长了）
swapoff /tmp/swap # 关闭 swap 分区
```

### 下午

#### 1. 认识 bash

bash 命令分为内部命令和外部命令

- 内部命令就是 bash 程序的一部分。这些命令的实现再 bash 这个可执行文件中
- 外部命令就是和 bash 不同的程序。和 bash 是两个独立的可执行文件。

```shell
type ls # type + 命令 查看指令是内部命令还是外部命令
```

```
在 bash 这个程序执行期间，可以设置相关的变量
bash 的变量分为两种
1. 自定义变量 当前进程私有的变量
2. 环境变量 可以被子进程继承的环境变量
环境变量：计算机中有很多资源，在程序运行期间需要访问这些资源。不同的操作环境存放的资源的位置不同。
用户可以通过设置变量的值来指定资源所在的位置。这样的变量就是环境变量。
```

#### 2. 进程和程序

```
程序是计算机指令的集合。程序是存放在磁盘上的，静态的。
进程是程序执行的时候的描述。
程序每执行一条指令的时候，计算机资源的状态有一种。
将这条指令执行的时候，计算机资源的状态描述下来。

进程是程序运行的实例。
```

进程的分类

```
1. 内核级线程

2. 用户级进程
构成了一棵树 树根是 init 进程。init 进程也是1号进程
```

```shell
ps -aux
pstree
top
```

#### 自定义变量和环境变量

```shell
env # 查看环境变量
name=test # 设置变量
echo $name # 查看变量的值
export name # 设置环境变量
env|grep name # 查看环境变量中含有 name 的项

read atest # 从命令行输入一个值赋给 自定义变量 atest
# -p 提示语
# -t 倒计时
read -p "Please input your name: " yname
read -p "Please input your name: " -t yname

```

子进程会继承父进程的环境变量，

```s
# 所有用户都执行的脚本文件 全局
/etc/profile
/etc/bashrc
# 用户似有的 局部
~/.bashrc
~/.bash_profile
```

### 数据流的重定向

进程要去文件中获取数据

- 文件描述符 -> 0 1 2
- 0 -> 标准输入 键盘
- 1 -> 标准输出 显示器
- 2 -> 标准错误输出 显示器

```shell
find / --name passwd > out.log 2> err.log # 将标准输出流重定向到 out.log 将标准错误输出流重定向到 err.log
cat > file < file2 # 将 file2 作为标准输出流，将 file 作为标准输入流，相当于创建了一个单项数据流，把file2中的文件内容流入了file文件中
```

#### 管道

```shell
commandA|commandB|commandC # commandA 的
ls -al | cut -d ' ' -f 1
echo $PATH | cut -d ':' -f 2
```
