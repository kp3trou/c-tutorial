#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// functions declarations
void foo(char* s);
int add(int a, int b);
int subtract(int a, int b);
void calc(int a, int b, int (*op)(int, int));
int sum(int x, int y);


int main(){
	// Section 1
	// Pointers and Data structures
	// Data Structures are ways to organise and store data in memory.
	// Examples: array, Linked List, Queue, Stack,Tree.
	// 1.1: Linked List

	// Some function pointer examples, because we are going to use them.	
	void (*fptr)(char* s);// local function pointer fptr declaration
	//void (*fptr)(char*);// same as above
	printf("memory address of function pointer fptr points is %p\n",(void*)fptr);
	printf("memory address of function foo is %p\n",(void*)foo);
	fptr = foo;// the name of a function acts as a pointer.
	//fptr = &foo;// same as the above.
	printf("memory address of function pointer fptr points is %p\n",(void*)fptr);
	fptr("Function pointer works!\n");// call function foo through fptr pointer

    // Passing different functions to function calc
    calc(10, 5, add);
  	calc(10, 5, subtract);

	// Assign function pointer, call function through function pointer
	int (*fn)(int,int);
	fn = sum;
	int x = fn(12,10);
	int y = (*fn)(12,11);// (*fn) same as fn.
	printf("%d\n",x);
	printf("%d\n",y);


	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

/***  functions definition  ***/

void foo(char* s){
	printf("%s\n",s);
}

// A simple addition function
int add(int a, int b) {
    return a + b;
}

// A simple subtraction function
int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(int, int)) {
    printf("%d\n", op(a, b));
}

// A simple another subtraction for educational issues, to see which addition is called.
int sum(int x, int y){
	return x+y;
}




