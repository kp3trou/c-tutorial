#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration
void display_array(int arr[],int size);
void display_array_2(int *arr,int size);

int main(){
	// Section 1
	// one dimensional array
	int ar[] = {1,2,3};// here the block {} initializes the array
	printf("%p\n",(void*)ar);
	printf("%p\n",(void*)&ar);
	printf("%p\n",(void*)&ar[0]);
	//printf("%p\n",(void*)ar[0]);// compiler error
	printf("%d\n",ar[0]);
	printf("size of array ar is %d\n\n", sizeof(ar)/sizeof(int));
	// two dimensional array
	//int matrix[2][3] = {{1,2,3},{4,5,6}};// valid
	//int matrix[][] = {{1,2,3},{4,5,6}};// compiler error
	//int matrix[2][] = {{1,2,3},{4,5,6}};// compiler error
	//int matrix[][3] = {{1,2,3},{4,5,6}};// same as int matrix[2][3]
	int matrix[2][3] = {
			// 3 columns
			{1,2,3}, // first row
			{4,5,6}  // second row
		};
	printf("%p\n",(void*)matrix);// address of first sub array matrix[0] 
	printf("%p\n",(void*)matrix[0]);// memory address of first array
	printf("%p\n\n",(void*)matrix[1]);// memory address of second array
									// 3 bytes distance between them.
	printf("size of matrix[%d] is %d bytes\n",0,sizeof(matrix[0]));
	printf("size of matrix[%d] is %d bytes\n",1,sizeof(matrix[1]));

	// consecutive positions in memory
	printf("%p\n",(void*)&matrix[0][0]); 
	printf("%p\n",(void*)&matrix[0][1]);
	printf("%p\n",(void*)&matrix[0][2]);
	printf("%p\n",(void*)&matrix[1][0]);
	printf("%p\n",(void*)&matrix[1][1]);
	printf("%p\n",(void*)&matrix[1][2]);

	// print the values for each position
	printf("%d\n",matrix[0][0]); 
	printf("%d\n",matrix[0][1]); 
	printf("%d\n",matrix[0][2]); 
	printf("%d\n",matrix[1][0]); 
	printf("%d\n",matrix[1][1]); 
	printf("%d\n\n\n",matrix[1][2]); 

	// pointers and arrays
	int vector[] = {1,2,3,4,5};
	int *pv = vector;
	int *pv2 = &vector[0];
	printf("%p\n",(void*)vector);
	printf("%p\n",(void*)&vector[0]);
	printf("%p\n",(void*)pv);
	printf("%p\n",(void*)pv2);
	printf("%d\n",*pv2);
	pv2++;
	printf("%d\n",*pv2);
	printf("%d\n",*(pv));
	printf("%d\n",*(pv+1));// when adding 1, we add 4 as the size of integer
	printf("%d\n",*(pv+2));
	printf("%d\n",*(pv+3));
	printf("%d\n",*(pv+4));
	//printf("%d\n",*(pv+10));// undefined behavior, out of bound of the array
	printf("%d\n",*(vector));
	printf("%d\n",*(vector+1));// adding 1 at the address of vector
	printf("%d\n",*(vector+2));
	printf("%d\n",*(vector+3));
	printf("%d\n\n\n",*(vector+4));
	printf("size of array vector is %d bytes\n",sizeof(vector));
	printf("size of pv pointer is %d\n",sizeof(pv));

	// Section 2
	// using malloc to create one dimensional array -> at heap memory
	int *pv3 = (int*)malloc(5*sizeof(int));
	for(int i = 0;i<5;i++)
		pv3[i] = i + 1;// same as : *(pv+i) = i+1;

	for(int i = 0;i<5;i++)
		printf("%d\n\n\n",pv3[i]);
	free(pv3);
	
	// Section 3
	// Passing one dimensional array to a function
	// When a one-dimensional array is passed to a function,
	// the array’s address is passed by value.
	// 3.1 : using array notation
	display_array(vector,5);
	// 3.2 : using pointer notation
	int *pr = vector;
	display_array_2(pr,5);

	// create an array of pointers
	int a = 1;
	int b = 2;
	int c = 3;
	int *pa1 = &a;
	int *pa2 = &b;
	int *pa3 = &c;
	int *ppr[3] = {pa1,pa2,pa3};
	for(int i = 0;i<3;i++)
		printf("%d\n",*ppr[i]);

	printf("\n------------------\n\n");
	int* arr[5];// create an array of integer pointers
	for (int i=0;i<5;i++){
		arr[i] = (int*)malloc(sizeof(int));
		*arr[i] = i;
	}
	for(int i = 0;i<5;i++){
		printf("%d\n",*arr[i]);
		free(arr[i]);
	}
	printf("\n------------------\n\n");
	// same as above, with pointer arithmetic
	for (int i=0;i<5;i++){
		*(arr+i) = (int*)malloc(sizeof(int));
		**(arr+i) = i;
	}
	for(int i = 0;i<5;i++){
		printf("%d\n",**(arr+i));
		free(*(arr+i));
	}

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// function that displays an array.Args are that array and it's size.
void display_array(int arr[],int size){
	for(int i=0;i<size;i++)
		printf("%d\n",arr[i]);
}

// function that displays an array.Args are a pointer and array size.
void display_array_2(int *arr,int size){
	for(int i=0;i<size;i++)
		printf("%d\n",arr[i]);
}

