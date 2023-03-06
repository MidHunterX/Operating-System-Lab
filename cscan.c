#include <stdio.h>
#include <stdlib.h>
void main() {
  int RQ[100], i, j, n, count = 0, init, size, move;
  printf("Enter the number of Requests\n");
  scanf("%d", &n);
  printf("Enter the Requests sequence\n");
  for (i = 0; i < n; i++) scanf("%d", &RQ[i]);
  printf("Enter initial head position\n");
  scanf("%d", &init);
  printf("Enter total disk size\n");
  scanf("%d", &size);
  printf("Enter the head movement direction for high 1 and for low 0\n");
  scanf("%d", &move);
  /*logic for sort the request array */
  for (i = 0; i < n; i++)
    for (j = 0; j < n - i - 1; j++)
      if (RQ[j] > RQ[j + 1]) {
        int temp;
        temp = RQ[j];
        RQ[j] = RQ[j + 1];
        RQ[j + 1] = temp;
      }
  int index;
  for (i = 0; i < n; i++)
    if (init < RQ[i]) {
      index = i;
      break;
    }
  // if movement is towards high value
  if (move == 1) {
    for (i = index; i < n; i++) {
      count = count + abs(RQ[i] - init);
      init = RQ[i];
    }
    //  last movement for max size
    count = count + abs(size - RQ[i - 1] - 1);
    /*movement max to min disk */
    count = count + abs(size - 1 - 0);
    init = 0;
    for (i = 0; i < index; i++) {
      count = count + abs(RQ[i] - init);
      init = RQ[i];
    }
  }
  // if movement is towards low value
  else {
    for (i = index - 1; i >= 0; i--) {
      count = count + abs(RQ[i] - init);
      init = RQ[i];
    }
    //  last movement for min size
    count = count + abs(RQ[i + 1] - 0);
    /*movement min to max disk */
    count = count + abs(size - 1 - 0);
    init = size - 1;
    for (i = n - 1; i >= index; i--) {
      count = count + abs(RQ[i] - init);
      init = RQ[i];
    }
  }
  printf("Total head movement is %d", count);
}
