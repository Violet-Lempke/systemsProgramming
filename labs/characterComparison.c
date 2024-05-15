#include <stdio.h>
void main() {
int result = strNcmp("fail", "fall", 2);
int result2 = strNcmp("fail", "fall", 3);
printf("%d, %d\n", result, result2);
}
int strNcmp(char *s, char *t, int n) {
int ii = 0;
for(ii; ((ii < n) && (*s != '\0')); ii++) {
if (*t != *s) {
return 0;
}
t++;
s++;
}
return 1;
}
