#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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







	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

