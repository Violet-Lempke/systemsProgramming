
#include <stdio.h>
#define MAXLINE 1000
void copy(char to[], char from[]) {
//copies all characters of the from array into the to array, including the null character.
	int ii = 0;
	while (from[ii] != '\0') {
		to[ii] =
		from[ii];
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
int main() {
	int curLen = 0;
	int flag = 0;
	char curLine[MAXLINE];
	char lastValid[MAXLINE];
	curLen = protoGetLine(curLine, MAXLINE);
	while (curLen > 0) {
		if (curLen > 1) {
			flag = 1;
			copy(lastValid, curLine);
		}
		curLen = protoGetLine(curLine, MAXLINE);
	}
	if (flag > 0) {
		printf("%s", lastValid);
		return 0;
	}
	else {
		printf("This file is empty");
		return 0;
	}
}
