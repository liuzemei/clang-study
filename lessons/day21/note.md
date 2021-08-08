> Linux 操作系统下一切皆文件。
>
> 1. 设备也是文件
> 2. 文件有内容，还有除了内容以外的控制信息。

### 1. ioctl

```c
ioctl(2)
```

```c
#include <sys/ioctl.h>
int ioctl(int d, int request, ...);

```
