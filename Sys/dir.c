/*
OPENDIR & READDIR
-----------------
Aim:
To write a C program to display the files in the given directory

Algorithm:
1.Start the program
2.Declare the variable to the structure dirent (defines the file
system-independentdirectory) and also for DIR
3.Specify the directory path to be
displayed using the opendir system call
4.Check for the existence of the
directory and read the contents of the directory usingreaddir system call
(returns a pointer to the next active directory entry)
5.Repeat the above step
until all the files in the directory are listed
6.Stop the program
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
void main() {
  DIR *p;
  struct dirent *dp;
  p = opendir(".");
  if (p == NULL) {
    perror("opendir");
    exit(0);
  }
  dp = readdir(p);
  while (p != NULL) {
    printf("%d %s\n", dp->d_ino, dp->d_name);
    dp = readdir(p);
  }
}
