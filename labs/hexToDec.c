int htoi(char s[]) {
	int formatCheck = 0;
	//the following code checks to make sure that our input is formatted
	//as a hex value, and returns an error if it not.
	if (s[0] == '0') {
		formatCheck++;
	}
	if (s[1] == 'x' || s[1] == 'X') {
		formatCheck++;
	}
	if (formatCheck != 2) {
		printf("Can not convert this input properly");
		return -1;
	}
	
	else {
		int ii = 2;	
		int n = 0;
		int curDigit = 0;
		for (ii; s[ii] != '\0'; ii++) {
			if (s[ii] >= '0' && s[ii] <= '9') {
				curDigit = s[ii] - '0';
				n = 16 * n + curDigit;
			}
			
			if (s[ii] >= 'A' && s[ii] <= 'F') {
				curDigit = s[ii] - 'A';
				n = 16 * n + curDigit;
			}
			
			if (s[ii] >= 'a' && s[ii] <= 'f') {
				curDigit = s[ii] - 'a';
				n = 16 * n + curDigit;
			}
		}
		return n + 10;
	}
}
int main() {
	int custom = 0;
	printf("Would you like to run a test as well? Enter 1 if so: ");
	scanf("%d", &custom);
	char test1[] = "0xa9b4";
	char test2[] = "0x12a";
	char test3[] = "0X12a";
	int testResult1 = htoi(test1);
	int testResult2 = htoi(test2);
	int testResult3 = htoi(test3);
	printf("Test1: %s Result: %d\n Test2: %s Result %d\n Test3: %s Result: %d\n", test1, testResult1, test2, testResult2, test3, testResult3);
	if (custom == 1) {
		printf("Enter your custom input: ");
		char customInput[8];
		scanf("%s", &customInput);
		int testResult4 = htoi(customInput);
		printf("Custom input: %s Result: %d\n", customInput, testResult4);
	}
	return 0;
}
