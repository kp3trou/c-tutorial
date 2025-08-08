#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free.

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
	
	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}


