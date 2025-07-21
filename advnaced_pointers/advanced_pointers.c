#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char* s1,char* s2);

int main(){
	// Section 1
	// malloc, calloc
	int* a = malloc(1000);// Allocates 1000 bytes at heap memory
	free(a); // Release the memory in heap that pointer a points.
	int *arr1 = malloc(5 * sizeof(int)); // Allocates 5x4 bytes , with garbage.
	int *arr2 = calloc(5, sizeof(int)); // here initilaze with zeros.
	for (int i = 0; i < 5; ++i)
		printf("arr1[%d] = %d, arr2[%d] = %d\n", i, arr1[i], i, arr2[i]);
	free(arr1);
	free(arr2);
	int* p = NULL;
	printf("%p\n",p);
	// malloc prototype : void *malloc(size_t size); // size_t is unsigned integer
	// Allocates a block size of bytes
	// and returns a pointer to it.

	// Section 2
	// Dynamic allocated strings
	char* s = malloc(5);
	strcpy(s,"joh");
	printf("%c\n",s[0]);
	s[3] = 'n';
	s[4] = '\0';
	printf("%s\n",s);
	printf("%d\n",strlen(s));// strlen returns the number of characters except \0.
	char n[] = " deer !"; 
	printf("%d\n",strlen(n));
	printf("%s\n\n",strcat(s,n));
	free(s);
	// Using malloc inside a function
	char s_1[] = "hello ";
	char s_2[] = "world !";
	//printf("%s\n",concat(s_1,s_2));// wrong, no free for pointer returned.Use valgrind to see.
	char* combined = concat(s_1,s_2);// need to assign pointer and make free after.
	printf("%s\n\n",combined);
	free(combined);

	// Section 3
	// Dynamic allocated arrays






	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// Function for concatenate 2 strings
char* concat(char* s1,char* s2){
	char *result;
	result = malloc(strlen(s1) + strlen(s2) + 1);
	if (result == NULL) {
		printf("Error: malloc failed in concat\n");
		exit(EXIT_FAILURE);// stops the program
	}
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}


