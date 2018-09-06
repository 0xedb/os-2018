/*
 * LAB ASSIGNMENT 1
 * Course: Operating System
 * Author: 	Bruno Edoh
 * GitHub: 	https://github.com/theBashShell
 * Date: Sep-06-18
 * */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	
	// Required Checks
	if(argc < 2) {
		printf("Missing filename(s)!\n");
		return EXIT_FAILURE;
	}
	
	for(int i = 1; i < argc; i++) {
		
	// Open file
	FILE* file_to_open = fopen(argv[i], "r");
	
	if(!file_to_open) {
		printf("Unable to open file: '%s'\n", argv[i]);
		printf("File probably doesn't exist\n");
		return EXIT_FAILURE;
	}	
		
	// Print File Content
	int check;		// track EOF
	while((check = fgetc(file_to_open)) != EOF) {
		putchar(check);		
	}
	
	printf("\n\n");	// separated the files
	
	if(ferror(file_to_open)) {
		puts("Error Encountered");
	}
	
	fclose(file_to_open);
	
	}
	
}

