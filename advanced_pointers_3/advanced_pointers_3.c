#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*funcptr)(int);
typedef int (*fptroperation)(int,int);

// function prototype
int square(int num);
int add(int num1, int num2);
int subtract(int num1, int num2);
int compute(fptroperation operation,int num1, int num2);
fptroperation select_operation(char opcode);
int evaluate(char opcode, int num1, int num2);

int main(){
	// Section 1
	// Function Pointers
	// A function pointer is a pointer that holds the address of a function
	// Simple function pointer declaration
	void (*foo)();// function pointer named foo
	void (*f2)(char*);// function pointer, returns nothing
	double* (*f3)(int,int);// function pointer to a function that returns double*
						   // and takes 2 integers as arguments
	int *f4();// function that returns a pointer to integer
	int (*f5)();// function pointer
	int* (*f6)();// function pointer to function that returns pointer to integer (int*)
	
	// usage
	int (*fptr1)(int);
	int n = 5;
	fptr1 = square;// same as : fptr1 = &square;
	printf("%d squared is %d\n",n,fptr1(n));	
	printf("address of function pointer is %p\n",(void*)&fptr1);	
	printf("address of square function is %p\n",(void*)fptr1);	
	printf("address of square function is %p\n\n",(void*)square);	

	// using typedef
	funcptr fptr2;
	fptr2 = square;
	printf("%d squared is %d\n\n",n,fptr2(n));	

	// passing function pointers to a function
	printf("%d\n",compute(add,5,6));// pass add address
	printf("%d\n",compute(subtract,5,6));// pass subtract address

	// returning function pointer
	printf("%d\n",evaluate('+', 5, 6));
	printf("%d\n",evaluate('-', 5, 6));

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// functions implementation

int square(int num){
	printf("address of num is %p\n",(void*)&num);	
	return num*num;
}

int add(int num1, int num2){
	return num1+num2;
}

int subtract(int num1, int num2){
	return num1-num2;
}

// see the first argument, is function pointer
int compute(fptroperation operation,int num1, int num2){
	return operation(num1, num2);
}

// return a function pointer fptroperation
fptroperation select_operation(char opcode) {
	switch(opcode) {
		case '+': return add;
		case '-': return subtract;
	}
}

int evaluate(char opcode, int num1, int num2) {
	fptroperation operation = select_operation(opcode);
	return operation(num1, num2);
}

