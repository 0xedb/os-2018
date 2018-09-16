/*
 * LAB ASSIGNMENT 1
 * Course: Operating System
 * Author: 	Bruno Edoh
 * GitHub: 	https://github.com/theBashShell
 * Date: Sep-06-18
 * Part 1
 * */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	
	// Required Checks
	if(argc < 2) { 
		return EXIT_FAILURE;
	}
	
	for(int i = 1; i < argc; i++) {
		
	// Open file
	FILE* file_to_open = fopen(argv[i], "r");
	
	if(!file_to_open) {
		printf("my-cat: cannot open file\n"); 
		return EXIT_FAILURE;
	}	
		
	// Print File Content
	int check;		// track EOF
	while((check = fgetc(file_to_open)) != EOF) {
		putchar(check);		
	}
	 
	
	if(ferror(file_to_open)) {
		puts("Error Encountered\n");
	}
	
	fclose(file_to_open);
			
	}
	
	return 0;
}

