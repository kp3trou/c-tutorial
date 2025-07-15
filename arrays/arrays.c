#include <stdio.h>

#define SIZE 6

int main(){

	// Section 1

	int array[SIZE] = {1,2,3,4,5,6};
	printf("array size is : %d\n",sizeof(array));// size of the whole array integers in bytes
	printf("%d , %d \n",array[0],array[1]);
	int array_2[] = {5,6,7,8,9};
	for (int i = 0; i < SIZE ;i++ ){
		array_2[i] *= 2;
		printf("%d\n",array_2[i]);
	}
	
	int sum = 0;
	for (int i = 0; i < SIZE ;i++ ){
		sum += array[i];
	}
	printf("sum is : %d\n\n",sum);

	// Section 2 : Reverse an array

	// 2.1 In place
	int temp;
	for (int i = 0; i < 3 ; i++ ){
		temp = array[i];
		array[i] = array[SIZE -1 - i];
		array[SIZE - 1 - i] = temp;
	}

	for (int i = 0; i < SIZE ;i++ ){
		printf("%d\n",array[i]);
	}
	printf("\n\n");

	// 2.2 Using a second array
	int array_3[] = {1,2,3,4,5,6};
	int reversed[SIZE];
	for (int i = 0; i < SIZE; i++) {
    	reversed[i] = array_3[SIZE - 1 - i];
	}

	for (int i = 0; i < SIZE ;i++ ){
		printf("%d\n",reversed[i]);
	}
	printf("\n\n");

	// 2.3 
	int array_4[] = {10,11,12,13,14,15};
	int array_size = sizeof(array_4)/sizeof(array_4[0]);
	printf("size of the array is : %d \n",array_size);
	for (int j = 0 ; j < array_size ; j++ ){
		printf("%d \n",array_4[j]);
	}

	printf("There are a lot more to discover at the previous sections...\n");
	return 0;
}
