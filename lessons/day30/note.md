
## 回顾
### 网络
TCP/IP 协议的分层

物理地址: MAC地址
逻辑地址: IP地址

IP地址包含两部分
- 网络号
- 主机号

用子网掩码来计算网络号(同网段内的走交换机)
路由表使用这个网络号判断将数据包发送到哪里?

网帧 IP报文 TCP包

数据包的分用过程

- 集线器(物理电信号的放大和分流)
- 交换机(链路层的交换 交换的是网帧)
- 路由器(网络层的交换 交换的是ip报文)


### 交换机
交换机内部有个表
1口 -> mac地址 -> ip 地址
2口 -> mac地址 -> ip 地址
...


### 路由器
交换的是 IP 报文



## 新

C/S: 客户端与服务端框架

B/S: 是客户端的一种. 

UDP TCP
基于 TCP 的数据传输

简历客户端到服务端的一个链接, 



### socket

```c
// 创建一个通信端点, 返回一个文件描述符
int socket(int domain, int type, int protocol);
// domain: 定义通信的协议蔟
// PF_INET IPV4 的 ip协议蔟

// type: 
// SOCK_STREAM TCP 
// SOCK_DGRAM UDP

// 将 address 指定的地址绑定到 socket 上.
int bind(int socket, const struct sockaddr *address, socklen_t address_len);
// socket: socket创建的通信端点
// address: 地址
// 多种地址家族, 函数只用到其中之一, 函数设计的时候, 只是设计了一个通用的接口
// address_len: sizeof(address)


// 在一个 socket 设备上监听连接
int listen(int socket, int backlog);
// socket: socket 创建的通信端点
// backlog: 指定最大的未决连接队列的长度


// 
int accept(int socket, struct sockaddr *restrict address,
socklen_t *restrict address_len);


// 使用新建的 socket 设备连接到服务器
int connect(int socket, const struct sockaddr *address, socklen_t address_len);


struct sockaddr_in {
	sa_family_t     sin_family; // 
	in_port_t       sin_port;// 网络字节序  大端
	struct  in_addr sin_addr;// 地址
};



```