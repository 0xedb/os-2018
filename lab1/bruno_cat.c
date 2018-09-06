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
	// Open file
	FILE* file_to_open = fopen(argv[1], "r");
	
	if(!file_to_open) {
		perror("Unable to open file! :(");
		return EXIT_FAILURE;
	}	
	
	
	// Print File Content
	int check;		// track EOF
	while((check = fgetc(file_to_open)) != EOF) {
		putchar(check);		
	}
	
	if(ferror(file_to_open)) {
		puts("Reading Error Encountered");
	}
	
	fclose(file_to_open);
}
