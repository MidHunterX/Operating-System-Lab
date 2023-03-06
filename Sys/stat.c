// STAT SYSTEM CALL
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void main() {
  char path, path1[10];
  struct stat *nfile;
  nfile = (struct stat *)malloc(sizeof(struct stat));
  printf("Enter name of file : ");
  scanf("%s", path1);
  stat(path1, nfile);
  printf("user id \t\t: %d \n", nfile->st_uid);
  printf("block size \t\t: %d \n", nfile->st_blksize);
  printf("last accessed at \t: %d \n", nfile->st_atime);
  printf("last modified at \t: %d \n", nfile->st_atime);
  printf("production mode \t: %d \n", nfile->st_mode);
  printf("size of file \t\t: %d \n", nfile->st_size);
  printf("number of links \t: %d \n", nfile->st_nlink);
}
