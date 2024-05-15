#include <stdio.h>
int strend(char *s , char *t) {
	char *initPointer = t;
	while(*s != '\0') {
		char *curPointer = s;
		t = initPointer;
		do {
			t++;
			s++;
		}while((*s == *t) && ((*s != '\0') && (&t != NULL)));
	
		if(*s == *t) {
			break;
		}
		s = (curPointer + 1);
	}
	if(*t == '\0') {
		return 1;
	}
	else {
		return 0;
	}
}
void main() {
	int result = strend("I don't want to fail", "HCI");
	int result2 = strend("I want to pass", "pass");
	printf("%d, %d\n", result, result2);
}
