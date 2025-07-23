#include <stdio.h>
#include <stdlib.h>

// function declaration
int* two_sum(int* nums, int nums_size, int target, int* return_size); 

int main(){
	int arr[] = {2,7,11,15};
	int size = 4;
	int trg = 18;
	int rtsize = 0;
	int* idx = two_sum(arr,size,trg,&rtsize);
	printf("indices are idx[%d] : %d , idx[%d] : %d\n", 0,1,idx[0],idx[1]);
	return 0;
}

// function given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
int* two_sum(int* nums, int nums_size, int target, int* return_size) {
	int* result = malloc(2 * sizeof(int));
	for (int i = 0; i < nums_size; i++) {
		for (int j = i + 1; j < nums_size; j++) {  // j starts at i + 1 to avoid i == j
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				*return_size = 2;
				return result;
			}
		}
	}
	free(result);
	*return_size = 0;
    return NULL;  // If no pair is found
}


