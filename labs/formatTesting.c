#include <stdio.h>
#include <ctype.h>

double atofe(char s[]) {
	double val, power;
	int ii, sign;
	int exSign = 1.0;
	int exVal,expower;
	expower = 1.0;
	for(ii = 0; isspace(s[ii]); ii++);
		sign = (s[ii] == '-') ? -1: 1;
	
		if((s[ii] == '+') || (s[ii] == '-')) {
			ii++;
		}
	
		for(val = 0.0; isdigit(s[ii]); ii++) {
			val = 10.0 * val + (s[ii] - '0');
		}
	
		if(s[ii] == '.') {
			ii++;
		}
	
		for(power = 1.0; isdigit(s[ii]); ii++) {
			val = 10.0* val + (s[ii] - '0');
			power *= 10.0;
		}
	
		if((s[ii] == 'e') || (s[ii] == 'E')) {
			ii++;
			exSign = (s[ii] == '-') ? -1: 1;
			
			if((s[ii] == '+') || (s[ii] == '-')) {
				ii++;
			}
			
			expower = 1.0;
			
			for(ii = ii, exVal = 0.0; isdigit(s[ii]); ii++) {
				exVal = 10.0 * exVal + (s[ii] - '0');
			}
			
			for (ii = exVal; ii > 0; ii--) {
				expower *= 10;
			}
		}
	
		printf("%d", expower);
	
		if (exSign > 0) {
			return ((sign * val / power) * expower);
		}
		else {
			return (sign * val / power / expower);
		}
}
int main() {
	char s1[] = "123.45";
	char s2[] = "630000";
	char s3[] = "123.4567e-4";
	char s4[] = "-76.54321E6";
	printf("The following output uses the 'f' conversion:\n");
	printf("%s => %f\n", s1, atofe(s1));
	printf("%s => %f\n", s2, atofe(s2));
	printf("%s => %f\n", s3, atofe(s3));
	printf("%s => %f\n\n", s4, atofe(s4));
	printf("The following output uses the 'g' conversion:\n");
	printf("%s => %g\n", s1, atofe(s1));
	printf("%s => %g\n", s2, atofe(s2));
	printf("%s => %g\n", s3, atofe(s3));
	printf("%s => %g\n", s4, atofe(s4));
	return 0;
}
