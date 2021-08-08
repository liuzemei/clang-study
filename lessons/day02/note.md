## 课前：

多用户同时登录到服务器
用户分成两种: 系统用户和普通用户
（系统用户包含超级用户）

`useradd` `usermod` `userdel`
`/etc/passwd` `/etc/gourp` `/etc/shadow`
`su` `sudo`

## 正文：

### 文件的权限：

-rw-rw-r-- 1 neo neo 0 Oct 3 10:50 fileA

`-` `u` `g` `o`

`-rw-rw-r--`

`-`: 表示文件的类型

> `-` : 普通文件
>
> `d` : 文件夹文件
>
> `b` : 块设备
>
> `c` : 字符设备文件
>
> `s` : socket 类型的文件
>
> `l` : 软连接文件
>
> `p` : 管道类型文件

> `r`: 读
>
> `w`: 写
>
> `x`: 执行

> 第一组: 用户权限，第二组: 组权限，第三组: 陌生人权限

#### 文件权限的修改

```shell
chmod (u|g|o|a)(+|-)(r|w|x) 文件路径
chmod a+x fileA # 给文件fileA的所有(u/g/o)用户权限加上 执行权限
chmod a-x fileA # 给文件fileA的所有用户权限 删除执行权限

chmod u+x fileA # 加上 u 用户权限加上执行权限
chmod u-w fileA # 去掉 u 用户权限删除写权限
```

#### 权限问题的三句话

1. 你是谁？`echo $USER`
2. 你在哪里？ `pwd`
3. 有没有权限操作？`ls -l`

#### 文件的权限掩码

```shell
umask # 查看用户对文件的权限掩码
umask 0033 # 设置用户文件的权限掩码为 033
```

创建一个新的普通文件的时候，预设的权限是
rw-rw-rw-
-------w-
rw-rw-r--

> 把预设的权限和文件掩码进行运算，去掉预设权限中文件掩码为 1 的位。
> touch gcc

#### 改变文件目的属主和属组

改变文件的属主和数组 只有 root 权限才可以动用

```shell
chown 用户名 文件名 # 改变文件的属主和属组
chown 用户名:组名 文件名 #
chgrp 组名 文件名 #改变文件的属组
```

#### 文件夹的权限

rwxr-xr-x

r 读 w 写 x 可执行码

1. 文件夹的内容是什么？
   就是文件夹里的文件和文件夹

> 对文件夹的写就是对文件夹里的内容进行更新的时候。

> x: 通过的意思
> cd 命令切换路径的时候，是否可以进入这个文件夹。

文件夹的默认权限
drwxrwxrwx

| -    | cd  | ls  | rm  |
| ---- | --- | --- | --- |
| 0000 | n   | n   | n   |
| 0100 | y   | n   | n   |
| 0200 | n   | n   | n   |
| 0300 | y   | n   | y   |
| 0400 | n   | n   | n   |
| 0500 | y   | y   | n   |
| 0600 | n   | n   | n   |
| 0700 | y   | y   | y   |

### 文件的压缩

1. gzip 压缩
2. bzip2 压缩
3. xz 压缩

```shell
file 文件名 # 查看文件的类型
```

```shell
gzip 文件名 -9 # 压缩 文件（-9就是最大化压缩，速度最慢，-1就是最小化压缩，速度最快，默认-6）
gzip -d xxx.tar.gz # 解压 gzip 文件 -> 获取 tar 包
bzip2 文件名 # 以 bzip2 方式压缩文件
bzip2 -d xxx.tar.bz2  # 解压 .gz2 文件 -> 获取 tar 包
```

#### 压缩文件的构成

压缩头 + 原数据

#### 文件夹的打包

```shell
tar [-(c|x|t)zjvfpPN] 档案与目录 [-C 解包路径]
tar -cvf /tmp/etc.tar /etc #
```

1. `-c`: create
2. `-x`: 解压
3. `-t`: 查看 tarfile 里面的档案

4. `-z`: 启用 gzip
5. `-j`: 启用 bzip2
6. `-f`: 这个参数必须得在最后加上，指定文档名
7. `-p`: 使用原档案的原来属性（）

8. `-N`: -N '2020/10/04'

> Linux 下一切皆文件 文件是文件 文件夹也是文件的一种 设备文件

有三个分区
`/`
`/boot`
`/swap`

#### 补充

```shell
alias la='ls -a' # 为命令 起个 别名
unalias la # 删除别名
```

### 查找

```shell
which 命令 # 查看 命令的位置

locate 文件名 # 查看所有包含的文件名
updatedb # 更新文件数据库

# 文件的内容，文件的描述信息
stat 文件路径 # 查看文件的元数据


find / -name filename # 查找 名称为 filename 的文件
find /dev -type s # 查找 /dev 下， 文件类型为 s 的所有文件
```
