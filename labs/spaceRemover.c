#include <stdio.h>
#define IN 1
#define OUT 0
main() {
	int state = OUT;
	int c = getchar();
	while (c != EOF) {
		if ((c != '') && (c != '\n') && (c != '\t')) {
			state = IN;
			putchar(c);
		}
		else {
			if (c == '\n') {
				state = OUT;
				putchar('\n');
			}
			else {
				if (state == IN) {
					state = OUT;
					putchar(' ');
				}
			}
		}
		c = getchar();
	}
	return 0;
}
