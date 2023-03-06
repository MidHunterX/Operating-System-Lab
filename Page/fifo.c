#include <stdio.h>
void main() {
  int i, j = 0, n, a[50], frame[10], no, k, avail, count = 0;
  printf("Enter the number of pages : ");
  scanf("%d", &n);
  printf("Enter the reference string : ");
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  printf("Enter the number of frames : ");
  scanf("%d", &no);
  for (i = 0; i < no; i++) frame[i] = -1;
  puts("Ref string\tPage frames");
  for (i = 1; i <= n; i++) {
    printf("%d\t\t", a[i]);
    avail = 0;
    for (k = 0; k < no; k++)
      if (frame[k] == a[i]) avail = 1;
    if (avail == 0) {
      frame[j] = a[i];
      j = (j + 1) % no;
      count++;
      for (k = 0; k < no; k++) printf("%d ", frame[k]);
    }
    printf("\n");
  }
  printf("page fault is %d", count);
}
