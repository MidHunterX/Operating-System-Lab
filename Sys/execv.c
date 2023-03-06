// EXECV
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
  int pid;
  char *args[] = {"/bin/ls", "-1", 0};
  puts("Parent Process");
  pid = fork();
  if (pid == 0) {
    execv("/bin/ls", args);
    puts("Child Process");
  } else {
    wait();
    puts("Parent Process");
    exit(0);
  }
}
