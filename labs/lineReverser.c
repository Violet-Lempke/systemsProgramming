#include <stdio.h>
#define MAXLINE 1000
void copy(char to[], char from[]) {
//copies all characters of the from
	array into the to array, including the null character.
	int ii = 0;
	while (from[ii] != '\0') {
		to[ii] = from[ii];
		ii++;
	}
	to[ii] = from[ii];
}
int protoGetLine(char s[], int lim) {
	int ii;
	int c = getchar();
	for (ii = 0; (ii < (lim - 1)) && (c != EOF) && (c != '\n'); ii++) {
		s[ii] = c;
		c = getchar();
	}	
	if (c == '\n') {
		s[ii] = c;
		ii++;
	}
	s[ii] = '\0';
	return ii;
}
void reverseCopy(char to[], char from[], int length) {
	int ii = length - 1;
	int jj = 0;
	for (ii = length - 1; ii >= 0; ii--) {
		to[jj] = from[ii];
		jj++;
	}
	to[jj] = '\0';
}
int main() {
	char line[MAXLINE];
	char reverseLine[MAXLINE];
	int flag = 0;
	int curLen = protoGetLine(line, MAXLINE);
	while (curLen > 0) {
		reverseCopy(reverseLine, line, curLen);	
		printf("%s", reverseLine);
		curLen = protoGetLine(line, MAXLINE);
	}
	return 0;
}
