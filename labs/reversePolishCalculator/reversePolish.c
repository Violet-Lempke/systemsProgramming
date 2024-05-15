#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polHead.h"
#define MAXOP 100
#define NUMBER '0'
main() {
	int type;
	double op2;
	char s[MAXOP];
	while((type = gettop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0) {
					push(pop()/op2);
				}
					
				else printf("Error: zero decision\n");
				break;
			case '\n':
				printf("\t%.6g\n", pop());
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'c':
				push(cos(pop()));
				break;
			case 'r':
				push(sqrt(pop()));
				break;
			case 'p':
				push(pow(pop(),pop()));
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	printf("I am done!\n");
}
