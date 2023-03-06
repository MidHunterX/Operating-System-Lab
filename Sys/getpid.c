#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

void main() {
  pid_t process;
  process = fork();
  if (process == 0) {
    puts("I am a child process");
    printf("Child process PID : %d", getpid());
  } else {
    puts("I am a parent process");
    printf("pParent process PID : %d", getpid());
  }
}
