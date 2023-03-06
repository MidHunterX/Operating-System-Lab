#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t process;
  process = fork();
  int status;

  if (process == 0) {
    puts("Child");
    sleep(10);
  } else {
    puts("Parent");
    wait(&status);
    puts("I am in parent process");
  }

  return 0;
}
