#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystruct{
	int year;
	double weight;
};

struct secstr{
	int year;
	double weight;
} sec_str; // here can use the sec_str directly.is a variable.

struct node {
	int value;
	struct node* next;// next has struct node* as data type.
};

// function declaration
char* concat(char* s1,char* s2);
void printhello();

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

	struct mystruct my_str;
	my_str.year = 1980;
	sec_str.year = 1984;

	struct node* n1;
	printf("%p\n",n1); // nil
	//n1->value = 10;// segmentation fault, not initialize the pointer!
	//printf("%d,\n",n1->value);
	n1 = malloc(sizeof(struct node));
	printf("%p\n",n1);// returms the address of the first byte of the block of memory in heap
	n1->value = 10;// use -> when you have pointer to a struct
	printf("%d\n\n\n",n1->value);
	free(n1);

	// Section 3
	// Dynamic allocated arrays
	int* ar = malloc(4 * sizeof(int));// Allocates 16 bytes in heap memory.Addr of 1st byte.	
	ar[0] = 1;
	ar[1] = 2;
	ar[2] = 3;
	ar[3] = 4;
	for(int i = 0; i < 4; i++)
		printf("ar[%d] : %d\n",i,ar[i]);
	free(ar);

	// Section 4
	// function pointers
	// example 
	// declaration of function pointer : void(*funcptr)() 
	// funcptr is a variable pointer
	// () means the funcptr is function pointer
	// () no args
	// void : the function that funcptr points return nothing
	void(*funcptr)();// declare function pointer
	funcptr = printhello;// assign the address of the function to the pointer
	funcptr();

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

// Function print Hello!
void printhello(){
	printf("Hello!\n");
}

