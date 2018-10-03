/*
 * LAB ASSIGNMENT 2
 * Course: Operating System
 * Author: 	Bruno Edoh
 * GitHub: 	https://github.com/theBashShell
 * Date: Sep-10-18
 * 
 * */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void stop() {
	printf("stopping");
	exit(0);
}


int main(int argc, char* argv[]) { 
	if(argc > 2) {		
		return EXIT_FAILURE;		
	} 
	
	if(argc == 1) {
		char* str[50];
		while(true) {
		// interactive mode print wish>
		stop();
		printf("wish> "); 
	}		
}
	// batch mode
}
