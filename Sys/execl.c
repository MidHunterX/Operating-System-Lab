/*
Aim : To Execute a Unix Command (Who) in a ‘C’ program using execl() system
call.

Problem Description
The Unix system call transfers an executable binary files into a process that
are theexec family of sytem calls.

General Format
Execl(filename,arg0,arg1,………argn,0)
Char *filename *Arg0* , arg1* ,…….argn*
Where filenames are the executable binary files to be transferred into a
process. arg0through argn define the argument to be passed to the process
*/

#include <process.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main() {
  int pid1;
  pid1 = fork();
  if (pid1 == 0) {
    printf("Process id is %d ", getpid());
    printf("and its parent id is %d", getppid());
    execl("/bin/who", "who", 0);
  }
}
