#include <stdio.h>
	int strRIndex(char s[], char t[]) {
	int sIndex = 0;
	int tIndex = 0;
	int ii, jj, kk;
	int minIndex = -1;
	for (ii = 0; s[ii] != '\0'; ii++) {
		jj = 0;
		if (s[ii] == t[jj]) {
			for (kk = ii; (t[jj] != '\0') && (s[kk] == t[jj]); jj++,kk++);
				if ((kk > 0) && (t[jj] == '\0')) {
					minIndex = ii;
				}
			}
		}
	return minIndex;
}

int main() {
	char s[] = "Missisipi";
	char t[] = "is";
	int result = strRIndex(s, t);
	printf("Test String: %s\nTest key: %s\nTest Result: %d\n", s, t, result);
}
