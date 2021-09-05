#include "c_net.h"

int s_bind(int domain, int type , unsigned short port) {
   // 1. 创建一个通信设备(通信端点), 返回这个通信端点的文件描述符
  int sockfd = socket(domain, type, 0);
  if (sockfd == -1) E_MSG("socket",-1);
  // 2. 创建一个地址结构
  SA4 addr;
  addr.sin_family = domain;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  // 3. 绑定地址 将 addr 指定的地址绑定到 sockfd 的设备上
  if (bind(sockfd, (SA *)&addr, sizeof(addr)) == -1) E_MSG("bind",-1);
  return sockfd;
}

int s_listen(int domain, int type , unsigned short port) {
  int sockfd = s_bind(domain, type, port);
  if (sockfd < 0) E_MSG("s_bind", -1);
  if (listen(sockfd, 5) == -1) E_MSG("listen",-1);
  // 完成了三次握手
  return sockfd;
}

int n_accept(int fd) {
    int clientfd = accept(fd, NULL, NULL);
    if (clientfd == -1) E_MSG("accept", -1);
    return clientfd;
}

int h_accept(int fd) {
    SA client_addr;
    socklen_t sockadr_len = sizeof(client_addr);
    int clientfd = accept(fd, &client_addr, &sockadr_len);
    if (clientfd == -1) E_MSG("accept", -1);

    // 将客户端的地址信息存放到了 client_addr 这个变量的地址空间里了
    // IP 地址 和 端口号 大端的 长整型 和 短整型
    // 需要将长整型转换为字符串
    char ip[20];
    inet_ntop(AF_INET, &client_addr.sa_data[2], ip, sizeof(ip));
    int port = ntohs(client_addr.sa_data[2]);
    printf("client ip: %s:%d\n", ip, port);
    return clientfd;
}