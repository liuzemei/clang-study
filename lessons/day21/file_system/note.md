

1. 创建1M的空闲文件
```shell
dd if=/dev/zero of=fs count=256 bs=4K
```

2. 将这个文件 格式化 变成一个磁盘分区
```shell
mke2fs fs
```

3. 查看一下这个


4. 挂载到 /mnt 下
```shell
# -o loop 告诉 mount 这是一个常规文件而不是一个块设备文件
mount -o loop fs /mnt

# 将会在 /mnt 下生成 lost+found，
```

5. 解除挂载 /mnt 
```shell
umount
```