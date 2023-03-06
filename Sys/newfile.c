/* ALGORITHM
--------------
Read a file
Copy the contents of the file
Paste it into another file
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

static char message[] = "Hello World";
void main() {
  int fd;
  char buffer[50];
  fd = open("newfile.txt", O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
  if (fd != 1) {
    puts("newfile.txt opened for read/write access");
    write(fd, message, sizeof(message));
    lseek(fd, 01, 0);
    if (read(fd, buffer, sizeof(message)) == sizeof(message))
      printf("\"%s\" was written to newfile.txt\n", buffer);
    else
      puts("error reading newfile.txt");
  } else {
    close(fd);
    puts("newfile.txt already exists");
    exit(0);
  }
}
