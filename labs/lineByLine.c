#include <stdio.h>
#define IN 1
#define OUT 0
main() {
	int c;
  	int state = OUT;
  	c = getchar();
  	while (c != EOF) {
    		if ((c != '') && (c != '\n') && (c != '\t')) {
      			state = IN;
      			putchar(c);
    		}
    		else {
      			if (state == IN) {
        			putchar('\n');
        			state = OUT;
      			}
    		}
    	c = getchar();
  	}
    	return 0;
}
