#include <stdio.h>
int majority(unsigned int a,unsigned int b,unsigned int c) {
	unsigned int confirmedSingles = 0;
	unsigned int confirmedDoubles = 0;
	unsigned int temp = 0;
	confirmedDoubles = (a & b);
	confirmedSingles = (a | b);
	temp = (confirmedSingles & c);
	confirmedDoubles = (confirmedDoubles | temp);
	return confirmedDoubles;
}
void bitPrint(unsigned int num) {
	unsigned int ii;
	unsigned int mask = 1<<31;
	for (ii = 1; ii <= 32; ii++) {
		putchar(((num & mask) == 0) ? '0': '1');
		num <<= 1;
		if ((ii % 8 == 0) && (ii != 32)) {
			putchar(' ');
		}
	}
}

int main() {
	unsigned int a = 0x8E;
	unsigned int b = 0x21;
	unsigned int c = 0x84;
	int choice = 0;
	printf("Vote a: ");
	bitPrint(a);
	printf("\nVote b: ");
	bitPrint(b);
	printf("\nVote c: ");
	bitPrint(c);
	unsigned int result = majority(a, b, c);
	printf("\n\nFinal Result: ");
	bitPrint(result);
	printf("\n");
	printf("Would you like to run a custom vote? Enter 1 if so: ");
	scanf(" %d", &choice);
	if (choice == 1) {
		printf("Enter your first vote: ");
		scanf(" %x", &a);
		printf("\nEnter your second vote: ");
		scanf(" %x", &b);
		printf("\nEnter your third vote: ");
		scanf(" %x", &c);
		result = majority(a, b, c);
		printf("Vote a: ");
		bitPrint(a);
		printf("\nVote b: ");
		bitPrint(b);
		printf("\nVote c: ");
		bitPrint(c);
		printf("\n\nPassing Items: ");
		bitPrint(result);
		printf("\n");
	}
	return 0;
}


