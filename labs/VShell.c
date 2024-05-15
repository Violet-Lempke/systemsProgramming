//Reminder: Test this on personal linux computer

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>


char path[50][50];
int main() {
	int TRUE = 0;
	char name[20];
	int pathDepth = 2;
	strcpy(path[0], "home");
	printf("Enter your name: ");
	fgets(name, 20, stdin);
	char *ptr = strchr(name, '\n');
	*ptr = '\0';
	strcpy(path[1], name);
	while(TRUE == 0) {
		int ii = 0;
		for (ii; ii < pathDepth; ii++) {
			printf("%s/", path[ii]);
		}
		printf("> ");
		char command[50];
		fgets(command, 50, stdin);
		char *fcommand = strtok(command, " ");
		char *ptr = strchr(fcommand, '\n');
		if (ptr) {
			*ptr = '\0';
		}
		if ((strcmp(fcommand, "logout") == 0) || (strcmp(fcommand, "quit") == 0)) {
			printf("Goodbye %s...\n", &name);
			exit(1);
		}
		char *args[10];
		char *arg = fcommand;
		args[0] = fcommand;
		int jj = 1;
		do {
			arg = strtok(NULL, " ");
			if (arg != NULL) {
				char *ptr = strchr(arg, '\n');
				if (ptr) {
					*ptr = '\0';
				}
			}
			args[jj] = arg;
			jj++;
		}
		while(arg != NULL);
		args[jj] = '\0';
		if (strcmp(fcommand, "cd") == 0) {
			if(chdir(args[1]) == 0) {
				if(strcmp(args[1], "..") == 0) {
					pathDepth -= 1;
				}
				else {
					pathDepth += 1;
					strcpy(path[pathDepth-1], args[1]);
				}
			}
		}
		else if (strcmp(fcommand, "accessRightDir") == 0) {
			pid_t pid = fork();
			if(pid == 0) {
				char *neoArgs[5] = {"ls", "-a", "-l", "-R", NULL};
				execvp(neoArgs[0], neoArgs);
			}
			else {
				int status;
				waitpid(pid, &status, 0);
			}
		}
		else if (strcmp(fcommand, "delDir") == 0) {
			char result[3];
			char *neoArgs[4] = {"rm", "-r", args[1], NULL};
			printf("Are you sure you'd like to delete %s? y/n: ", args[1]);
			fgets(result, 3, stdin);
			char *ptr = strchr(result, '\n');
			if (ptr) {
				*ptr = '\0';
			}
			if (strcmp(result, "y") == 0) {
				pid_t pid = fork();
				if(pid == 0) {
					execvp(neoArgs[0], neoArgs);
					exit(1);
				}
				else {
					int status;
					waitpid(pid, &status, 0);
				}
			}
		}
		else {
			pid_t pid = fork();
			if(pid == 0) {
				if (execvp(args[0], args) == -1) {
					printf("command %s not found...\n", fcommand);
				}
				exit(1);
			}
			else {
				int status;
				waitpid(pid, &status, 0);
			}
		}
	}
	return 1;
}
