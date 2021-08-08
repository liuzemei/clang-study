\$? 在这个变量里存储了上一条指令的返回值
Linux 系统上的程序运行规则：程序正确执行，返回 0；否则，返回非 0

### 测试

```shell
test [-efdbcSp] xxx # 测试文件
# 文件类型检测
# -e: 该档名(文件或文件夹)是否存在
# -f: 该档名是否为文件
# -d: 该档名是否为目录
# -b: 该档名是否为一个块设备
# -c: 该档名是否为一个字符设备
# -S: 该档名是否为一个 Socket 文件
# -p: 该档名是否为一个 管道 文件
# -L: 该档名是否为一个 软连接 文件
# -s: 该档名是否为一个 空 文件

# 文件权限检测
# -r -w -x

# 两个档案时间比较
# -nt(newer than) -ot(older than) -ef(硬链接 inode)

# 整数比较比较
# -eq(==) -ne(!=) -gt -lt -ge(>=) -le (<=)
test file1 -nt file2
# 字符串判定
test -z file1
# -z 字符串判空
# -n 字符串判非空
```

```shell
[ -n "$USER" ] && echo "$USER" || exit 0
```

# eval

eval 将程序中输入的或者加工出来的数据作为程序来执行，只适合于解释程序，不适合编译程序。

```shell
date '+mon=%m day=%d'
echo $mon
echo $day
# mon=10 day=07
eval `date '+mon=%m day=%d'`
echo $mon
echo $day

```
