#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }
  printf("dir %s open success...\n", argv[1]);

  struct dirent *dir_p;
  while(1) {
    dir_p = readdir(dir);
    if(dir_p==NULL){
      perror("readdir");
      return -1;
    }
    printf("file name: %s\tfile inode: %llu\n", dir_p->d_name,dir_p->d_ino);
  }
  

  
  closedir(dir);
  printf("dir %s close success...\n", argv[1]);
  return 0;
}