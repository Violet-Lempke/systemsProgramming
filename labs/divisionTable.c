#include <stdio.h>
main() {
  int ii = 1;
  int jj = 1;
  printf("| |");
  for (ii; ii < 10; ii++) {
    printf("%4d|",ii);
  }
  printf("\n--------------------------------------------------\n");
  ii = 1;
  for (ii; ii < 10; ii++) {
    jj = 1;
    printf("| %d |", ii);
    for (jj; jj < 10; jj++) {
      float temp = (float)ii/(float)jj;
      printf("%4.2f|", temp);
    }
    printf("\n--------------------------------------------------\n");
  }
return 0;
}
