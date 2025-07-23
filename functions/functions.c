#include <stdio.h>

#define SIZE 6

// function declaration/function prototype
double average (double a, double b); 
void print (void);
int foo (int a);
int sum_array (int array[], int n);
void mod_array (int array[], int n);

int main(){

	// Section 1
	double d = 10.2;
	double d2 = 5.2;
	// here d and d2 called arguments.The effect of call average(d,d2) is to copy the values of d and d2 into the parameters a and b.
	double avg  = average(d,d2); 
	printf("average is : %.4f\n",avg);
	print();
	(void)print();

	int a = 5;
	// parameter a contains a copy of the value a, a does not change it's value
	printf("%d\n",foo(a));
	printf("%d\n",a);

	// Section 2
	int ar[] = {1,2,3,4,5,6};
	printf("sum is : %d \n",sum_array(ar,SIZE));// pass by reference and by value

	mod_array (ar, SIZE); // pass by reference
	for (int i = 0; i < SIZE ; i++)
		printf("%d \n",ar[i]);
	
	printf("There are a lot more to discover at the previous sections...\n");
	return 0;
}

// Returns the average of 2 real numbers
double average(double a, double b){ // here a and b called parameters
	return (a+b)/2;
}

void print (void){
	printf("To C or not to C ?\n");
}

int foo (int a){ // int a is a copy of the argument value
	a++;
	return a;
}

// Returns the sum of integers inside of array
int sum_array (int array[], int n) {
	int sum = 0;
	for (int i = 0; i < n ; i++)
		sum += array[i];
	return sum;
}

// Modify the array
void mod_array (int array[], int n) {
	int sum = 0;
	for (int i = 0; i < n ; i++)
		array[i] += 2;
}

