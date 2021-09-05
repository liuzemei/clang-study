#include <sys/types.h>
#include <unistd.h>
#include "c_net.h"
int main(int argc, char *argv[]) {
  // 创建一个通讯设备, 返回这个设备的描述符
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // 创建一个结构体, 并且设置好相关的值
  SA4 serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(1234);

  // 使用新建的 socket 设备连接到服务器
  if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) == -1) E_MSG("connect", -1);
  // 就说明和服务器连接成功了

  // 向服务器端写消息
  char send_buf[1024];
  // 阻塞等待服务器的响应
  char recv_buf[1024];
  while(1){
    gets(send_buf);
    // +1 是为了把 \0 放在末尾
    write(sockfd, send_buf, strlen(send_buf)+1);
    int n = read(sockfd, recv_buf, sizeof(recv_buf));
    if (n == -1) E_MSG("read", -1);
    printf("recv: %s\n", recv_buf);
    if (strcmp(recv_buf, "QUIT") == 0) break;
  }
  // 关闭通讯设备
  close(sockfd);
  return 0;
}