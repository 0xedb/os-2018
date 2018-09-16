/*
 * LAB ASSIGNMENT 1
 * Course: Operating System
 * Author: 	Bruno Edoh
 * GitHub: 	https://github.com/theBashShell
 * Date: Sep-06-18
 * Part 2
 * */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 100

int main(int argc, char* argv[]) {
	
	// Required Checks
	if(argc < 2) { 
		printf("my-grep: searchterm [file ...]\n");
		return EXIT_FAILURE;
	}
		
	 
	char* search_term = argv[1]; 
	char* temp = malloc(READ_SIZE);
	int current_size = READ_SIZE;
	int start = 0;
	
	if(argc == 2) {
		int ch;
		printf("Enter text: ");
		while((ch = getchar()) != '\n') {
			temp[start++] = ch;
			
			if(start == current_size) {
			current_size += start;
			temp = realloc(temp, current_size);
			start = 0;
			}
		
		}
		temp[start] = '\0'; 
		
		char* found = strstr(temp, search_term);

			if(found) { 
				printf("%s\n", temp);				
			}	 
	}
	
	
	for(int i = 2; i < argc; i++) {
		
	// Open file
	FILE* file_to_open = fopen(argv[i], "r");
	
	if(!file_to_open) {
		printf("my-grep: cannot open file\n"); 
		return EXIT_FAILURE;
	}	
		
	// Print File Content
	int check;		// track EOF
	while((check = fgetc(file_to_open)) != EOF) {
		temp[start++] = (char) check; 
		
		
		if(check == '\n') { 
			
			char* found = strstr(temp, search_term);

			
			if(found) { 
				printf("%s\n", temp);				
			}
			
			start = 0;
			temp = malloc(READ_SIZE);
			current_size = READ_SIZE;
			
		}
		
		
		if(start == current_size) {
			current_size += start;
			temp = realloc(temp, current_size);
			start = 0;
		}
	}	 
	
	if(ferror(file_to_open)) {
		puts("Error Encountered\n");
	}
	
	fclose(file_to_open);
	 		
	}
	
	return 0;
}
