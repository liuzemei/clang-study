#include <strings.h>
#include "c_net.h"
#include "do_trans.h"

void do_trans(int cfd) {
  char buf[10240];
  while(1){
    bzero(buf, 10240);
    int r = read(cfd, buf, 10240);
    int i;
    for(i=0;i<r;i++)
      buf[i] = toupper(buf[i]);
    write(cfd,buf,r);
    printf("%s", buf);
    if (strcmp(buf, "QUIT") == 0) return;
  }
  return;
}
