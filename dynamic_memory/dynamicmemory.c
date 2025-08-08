#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free.

// function declaration
int* allocate_array(int size, int value);

int main(){

	// Section 1
	// malloc takes as parameters the number of bytes to allocate
	// and returns a void* pointer
	// When no memory allocated returns NULL.
	
	int *pi = (int*)malloc(sizeof(int));// returns a pointer that points to the address of
										// the first byte that memory created at heap.
	*pi = 5;
	printf("%d\n",*pi);
	free(pi);// deallocation-free the memory that pointer points at heap.

	// Memory Leaks Examples :
	// 1. undefined behavior,write at memory outside the limits
	// and when using free deallocates only the 6 bytes.Wrong.
	char *pc = (char*)malloc(6);// allocating 6 bytes at heap
	for(int i = 0; i < 8;i++){
		pc[i] = 'a';
	}
	printf("%s\n",pc);
	free(pc);
	// 2. losing address example
	int* pii = (int*) malloc(sizeof(int));
	*pii = 5;
	pii = (int*) malloc(sizeof(int));// lost the memory address
	printf("%d\n",*pii); 
	free(pii);// here deallocates the second allocated memory, the first not.Wrong.

	// return pointer from function
	int* vector = allocate_array(5,45);
	for(int i = 0; i<5; i++)
		printf("%d\n",vector[i]);
	free(vector);
	// Be careful, don't return pointers from local variables inside a function.

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// fill an array with values and returns a pointer to integer
int* allocate_array(int size, int value) {
	int* arr = (int*)malloc(size * sizeof(int));
	for(int i=0; i<size; i++) {
		arr[i] = value;
	}
	return arr;
}


