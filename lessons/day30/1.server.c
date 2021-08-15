#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <netinet/in.h>


int main(void) {
  // 1. 创建一个通信设备(通信端点), 返回这个通信端点的文件描述符
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }
  int port = 1234;
  // 2. 创建一个地址结构
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  // 3. 绑定地址 将 addr 指定的地址绑定到 sockfd 的设备上
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return -1;
  }
  // 4. 开始监听
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return -1;
  }

  while (1) {
    // 5. 从未决连接队列中取出一个连接请求
    struct sockaddr client_addr;
    socklen_t sockadr_len = sizeof(client_addr);
    int clientfd = accept(sockfd, &client_addr, &sockadr_len);
    if (clientfd == -1) {
      perror("accept");
      return -1;
    }
    // 到这里, 客户端连接成功

    // 6. 接受客户端发送的数据
    char buf[1024];
    int n = read(clientfd, buf, sizeof(buf));
    if (n == -1) {
      perror("read");
      return -1;
    }
    printf("接收到了消息:...%s\n", buf);
    // 7. 将读取到的数据回显给客户端
    write(clientfd, buf, n);

    // 8. 关闭通信端点
    close(clientfd);
  }
  close(sockfd);
  return 0;
}