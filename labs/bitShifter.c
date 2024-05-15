#include <stdio.h>
int bitFlip(int f, int n, int p) {
	int mask = 0;
	int ii = n;
	for (ii = n; ii > 0; ii--) {
		mask += 1;
		mask = mask << 1;
		p -= 1;
	}
	mask = mask << p;
	f = f ^ mask;
	return f;
}

void bitPrint(unsigned int num) {
	int ii;
	int mask = 1<<31;
	for (ii = 1; ii <= 31; ii++) {
		putchar(((num & mask) == 0) ? '0' : '1');
		num <<=1;
		if((ii % 8 == 0) && (ii != 32)) {
		putchar(' ');
		}
	}
	return;
}
int main() {
	int num = 33333;
	int f = bitFlip(num, 3, 7);
	int p;
	int n;
	printf("Sample operation (p = 3, n = 7): \n");
	printf("Initial array is: ");
	bitPrint(num);
	printf("\n");
	printf("Flipped array is: ");
	bitPrint(f);
	printf("\n");
	printf("Would you like to run a custom prompt? Enter 1 if so: ");
	int choice = 0;
	scanf(" %d", &choice);
	if (choice == 1) {
		printf("\nEnter the number to be operated on: ");
		scanf(" %d", &num);
		printf("\nEnter the position to start at: ");
		scanf(" %d", &p);
		printf("\nEnter the number of bits to be swapped: ");
		scanf(" %d", &n);
		printf("\n\nInitial bits: ");
		bitPrint(num);
		printf("\nFinal Bits: ");
		f = bitFlip(num, n, p);
		bitPrint(f);
		printf("\n");
	}
	return 0;
}
