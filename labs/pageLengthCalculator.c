#include <stdio.h>
#define PAGELENGTH 10
int main(int argc, char **argv) {
	int ii = 1;
	int pageNumber = 0;
	for (ii = 1; ii < argc; ii++) {
		pageNumber++;
		int lineCount = 0;
		FILE *fp = fopen(argv[ii], "r");
		char curLine[60] = {'\0'};
		printf("\n---%s--- Page: %d\n\n", argv[ii], pageNumber);
		while (fgets(curLine,60,fp) != NULL) {
			printf("%s", &curLine);
			lineCount++;
			if (lineCount == 10) {
				lineCount = 0;
				pageNumber++;
				printf("\nPress ENTER to continue:");
					while(getchar() != '\n') {
						printf("\n---%s--- Page: %d\n\n", argv[ii], pageNumber);
					}
			}
		}
	}
	
	printf("\n");
	return 1;
}
