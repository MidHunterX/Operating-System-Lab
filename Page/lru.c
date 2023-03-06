#include <stdio.h>
#define max 100
#define min 10
int ref[max], count, frame[min], n;
void input() {
  int i, temp;
  count = 0;
  printf("Enter the number of page frames : ");
  scanf("%d", &n);
  printf("Enter the reference string (-1 for end) : ");
  scanf("%d", &temp);
  while (temp != -1) {
    ref[count++] = temp;
    scanf("%d", &temp);
  }
}
void LRU() {
  int i, j, k, stack[min], top = 0, fault = 0;
  for (i = 0; i < count; i++) {
    if (top < n)
      stack[top++] = ref[i], fault++;
    else {
      for (j = 0; j < n; j++)
        if (stack[j] == ref[i]) break;
      if (j < n) {
        for (k = j; k < n - 1; k++) stack[k] = stack[k + 1];
        stack[k] = ref[i];
      } else {
        for (k = 0; k < n - 1; k++) stack[k] = stack[k + 1];
        stack[k] = ref[i];
        fault++;
      }
    }
    printf("\nAfter inserting %d, stack : ", ref[i]);
    for (j = 0; j < top; j++) printf("%d ", stack[j]);
  }
  printf("\nEnd to inserting the reference string.");
  printf("\n\nTotal page fault is %d.\n", fault);
}
void main() {
  input();
  LRU();
}
