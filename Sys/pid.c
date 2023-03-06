/*-------------------------------------------------------------
Aim : To Create a process in the following hierarchy.

Algorithm :
1.Declare the necessary variables.
2.Parent process is the process of the program which is running.
3.Create the child1 process using fork() When parent is active.
4.Create the child2 process using fork() when child1 is active.
5.Create the child3 process using fork() when child2 is active.
---------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

int main() {
  int pid1, pid2, pid3;

  printf("Process id : %d Parent id : %d\n", getpid(), getppid());
  pid1 = fork();

  if (pid1 == 0) {
    printf("Process id : %d Parent id : %d\n", getpid(), getppid());
    pid2 = fork();
  }

  if (pid2 == 0) {
    printf("Process id : %d Parent id : %d\n", getpid(), getppid());
    pid3 = fork();
  }

  if (pid1 == 0 && pid2 == 0 && pid3 == 0) {
    printf("Process id : %d Parent id : %d\n", getpid(), getppid());
    pid2 = fork();
  }
}
