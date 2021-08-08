#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){ 
  pid_t pid = fork();
  if(pid == -1){
    perror("fork");
    return -1;
  }

  printf("%d\n", pid);
  if (pid == 0) {
    sleep(20);
  } else {
    sleep(10);
    exit(0);    
  }
  
  return 0;
}