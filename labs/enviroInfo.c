#include<stdio.h>
#include<limits.h>
// This program is really created so that a user can get some basic information on the limits
// Defined in the implementation of C they are utilizing.
int main() {
	printf("The minimum value of an unsigned char is 0\n");
	printf("The maximum value of an unsigned char is %d\n", UCHAR_MAX);
	printf("\nThe minimum value of a signed char is %d\n", SCHAR_MIN);
	printf("The maximum value of a signed char is %d\n", SCHAR_MAX);
	printf("\nThe minimum value of an unsigned short is 0\n");
	printf("The maximum value of an unsigned short is %d\n", USHRT_MAX);
	printf("\nThe minimum value of a signed short is %d\n", SHRT_MIN);
	printf("The maximum value of a signed short is %d\n", SHRT_MAX);
	printf("\nThe minimum value of an unsigned long is 0\n");
	printf("The maximum value of an unsigned long is %lu\n", ULONG_MAX);
	printf("\nThe minimum value of a signed long is %ld\n", LONG_MIN);
	printf("The maximum value of a signed long is %ld\n", LONG_MAX);
	printf("\nThe minimum value of an unsigned int is 0\n");
	printf("The maximum value of an unsigned int is %ld\n", UINT_MAX);
	printf("\nThe minimum value of a signed int is %d\n", INT_MIN);
	printf("The maximum value of a signed int is %ld\n", INT_MAX);
	return 1;
}
