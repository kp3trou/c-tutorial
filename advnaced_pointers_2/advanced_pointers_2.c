#include <stdio.h>

#define NULL ((void *)0)// null pointer, casts 0 to void * pointer

int *globalpi;// global pointer

// function declaration
int foobar();
void foo();

int main(){
	// Section 1
	// Declaring pointers	
	int num;// static memory allocation
	int *pi;// static memory allocation
	printf("memory allocates %d bytes in stack for num\n",sizeof(num));
	printf("memory allocates %d bytes in stack for pointer pi\n",sizeof(pi));
	printf("the memory address of num is %d, Sorry undefind behavior !\n",&num);
	printf("the memory address of num is %p\n",&num);
	printf("the memory address of num is %p\n",(void*)&num);
	printf("the memory address of pi is %p\n\n",&pi);
	//*pi = 100;//wrong, undefined behavior	

	// Section 2
	// How to read a declaration
	// Begin backwards :
	// pci is a variable
	// pci is a pointer variable
	// pci is a pointer variable to integer
	// pci is a pointer variable to a constant integer
	// constant variable is avariable that cannot be changed 
	const int *pci;

	// Section 3
	// operator & : tells to compiler to return the address of the operand
	// operands are variables and values
	// printf("%p\n",(void*)&3);// wrong the value 3 don't have a memory address !
	num = 0; // num initialization
	pi = &num; // inside pi stored the address of variable num
	printf("memory address of num is %p and stored at pointer pi\n\n",pi);
	//pi = (int *)num; // wrong, now 0 casts into hex address that i don't permit to use !

	// Section 4
	// Displaying poiter values in decimal numbers
	// Memory addresses are in virtual memory and not the physical memory addresses
	printf("Decimal address of num: %d Value: %d\n",&num, num);
	printf("Decimal address of pi: %d Value: %d\n",&pi, pi);
	printf("Address of pi: %p Value: %p\n",&pi, pi);
	num = 5;// assign 5 
	printf("%d\n",*pi); // direference a pointer shows the value that pointer points
	printf("%p\n",(void*)foobar);// memory address of function foobar
	
	// Section 5
	// Generic pointer
	int i = 5;
	double d = 3.14;
	void *p;
	p = &i;// p points to an int
	p = &d;// p points to a double
	// we cannot direference a void * pointer directly because the compiler
	// does not know the size and type of data the pointer point to.
	//*p = 10.3;// wrong
	*(double *)p = 10.3;// casting p to double *
	printf("value of the pointer p points is %.4f\n\n",*(double *)p);
	double *myd = p;
	printf("value that myd points is %.4f\n",*myd);
	void *atp ;//pointer atp points to any type
	double x = 2.5;	
	atp = &x;
	//printf("value of the pointer points is %.4f\n\n",*atp);// wrong, cannot dereference 
	// a void pointer because the compiler does not know
	// what type of data is pointing to.
	printf("value of the pointer points is %.4f\n\n",*(double *)atp);
	void *pn = NULL;// points to nothing	
	printf("%p \n",pn);
	printf("%d \n",pn);
	//*(int *)pn = 3;// Segmentation fault
	//printf("%d\n",*(int *)pn);// Segmentation fault

	// more ...
	// A pointer to void,will have same representation and memory
	// alignment as a pointer to char.
	// A pointer to void will never be equal to another pointer.Two
	// void pointers assigned to NULL will be equal.
	// Any pointer can be assigned to a pointer to void.
	// void *pv;
	int n;
	int *pnt = &n;
	printf("value of pnt is %p\n",pnt);
	void *pv = pnt;
	pnt = (int*) pv;
	printf("value of pnt is %p\n",pnt);

	// Section 6
	// Global and static pointers
	// if a pointer declared as global or static, it is initialized to NULL
	// static && global variables are allocated in different memory location from stack, heap,
	// called data segment.
	// globalpi and staticpi.
	// pointer operators :
	// *  			declare pointer/dereference a pointer
	// ->  			used to access fields of a structure referenced by a pointer
	// +    		increment a pointer
	// -    		decrement a pointer
	// ==!= 		compares 2 pointers
	// (data type)  cast, change the type of pointer
	

	// Section 7
	// Pointers and arrays,short,char
	int vector[] = {28,41,7};
	int *piv = vector;
	printf("%d\n",*piv);
	printf("%d\n",piv[0]);
	piv += 1;
	printf("%d\n",*piv);
	printf("%d\n",piv[0]);
	piv += 1;
	printf("%d\n",*piv);
	printf("%d\n\n",piv[0]);
	int *ar = vector;
	for (int i = 0; i < 3; i++)
		printf("%d\n",*(ar+i));
	short s;
	printf("size of short is %d bytes\n",sizeof(s));
	short *ps = &s;
	char c;
	printf("size of char is %d byte\n",sizeof(c));
	char *pc = &c;
	printf("address ps points before : %p\n",(void*)ps);// convert to decimal
	ps += 1;
	printf("address ps points after : %p\n",(void*)ps); // convert to decimal and see 2 bytes incr.
	ps += 1;
	printf("address ps points after : %p\n",(void*)ps); // convert to decimal and see 2 bytes incr.
	// At the previous memory addresses, that ps points,inside them are garbage.
	// Just to see that using pointer arithmetic ,have access at memory continuation.
	// The ps pointer is increnment by 2 bytes because sizeof short is 2 bytes.
	// Becareful with pointers to void and addition :
	int nu = 5;
	void *pvi = &nu;
	printf("%p\n",(int*)pvi);// use this (recommended)
	printf("%p\n",pvi);
	pvi = pvi+1;// Syntax warning is some compilers, don't use this.
	
	// Subtracking 2 pointers
	// to be continued ...

	printf("\n\nThere are a lot more to discover at the previous sections...\n\n");
	return 0;
}

// function that always returns 7
int foobar(){
	return 7;
}

void foo(){
	static int *staticpi;
}


