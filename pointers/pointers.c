#include <stdio.h>

//function declaration
void min_max (int a[],int s,int* min,int* max);
int* foomax(int* a,int* b);

int main(){

	// Section 1
	// Memory address
	int a = 5;
	printf("the value of a is %d\n",a);
	int* pa = &a;// at pointer p is stored the address of a.
	printf("The memory address of a stored %p\n",(void*)&a);
	printf("The memory address of a stored %p\n",(void*)pa);
	printf("The memory address of pointer stored %p\n",(void*)&pa);
	printf("The value of the address that pointer points is %d\n",*pa);
	printf("the size of p is %d bytes\n",sizeof(pa));
	printf("the size of a is %d bytes\n",sizeof(a));
	// w,l pointers point to integers
	//int i,j,a[10],*w,*l;// pointer declaration with other variables

	int i;
	int* p;// pointer p points nowhere
	p = &i;// p now points to integer i
	// same as above statement can be : int i, *p = &i;
	i = 1;
	printf("The value of the address that pointer points is %d\n",*p);
	printf("The value of a is %d\n",i);
	*p = 2;	
	printf("The value of the address that pointer points is %d\n",*p);
	printf("The value of a is %d\n",i);

	int i2,j2,*p2,*q2;
	p2 = &i2;
	q2 = p2;
	printf("The memory address stored at p2 is %p\n",(void*)p2);
	printf("The memory address stored at q2 is %p\n",(void*)q2);
	printf("Pointers p2,q2 point at the same memory where i2 is stored !!!\n");
	*p2 = 1;
	printf("i2 value now is  %d\n",i2);
	printf("p2 points at valeu %d\n",*p2);
	printf("q2 points at valeu %d\n\n",*q2);

	int i3 = 1,j3,*p3,*q3;
	printf("value of i3 is %d\n",i3);	
	p3 = &i3;
	q3 = &j3;// q3 points at j3 variable
	*q3 = *p3;// copy the value 1 at j3 using pointer q3
	printf("value of j3 is %d\n\n",j3);

	// Section 2
	// Pointers as arguments
	// Find the smallest and biggest element in array
	int my_ar[] = {34,2,3,45,56,1,23};
	int min = 0;
	int max = 0;
	int size = 7;// array size
	min_max (my_ar,size,&min,&max);
	printf("max element of my_ar is %d\n",max);
	printf("min element of my_ar is %d\n\n",min);

	// Section 3
	// Pointers as return values
	// Return a pointer to the biggest integer of 2 numbers
	int a_1 = 3;
	int a_2 = 5;
	int* y =  foomax(&a_1,&a_2);	
	printf("y max is %d\n",*y);
	printf("max is %d\n",*foomax(&a_1,&a_2));
	printf("max is %d\n\n\n",*(foomax(&a_1,&a_2)));

	// Section 4
	// Pointer Arithmetic
	int my_array[] = {1,2,3,4,5};
	int* p_ar = &my_array[0];
	printf("%d\n",*p_ar);
	printf("%d\n",*&my_array[1]);
	*p_ar = 12;
	printf("%d\n",*p_ar);
	int* f = my_array;
	printf("%d\n",f[0]);
	printf("%d\n\n",f[1]);
	for (int i = 0 ; i < 5 ; i++)
		printf("f[%d] is %d\n",i,f[i]);
	int* h = &my_array[2];
	h += 2;
	printf("%d\n",*h);
	int* h2 = &my_array[5];
	h2 -= 3;
	printf("%d\n",*h2);
	int* u = &my_array[5];
	int* r = &my_array[0];
	int subtr = u - r;
	printf("%d\n\n",subtr); // prints the indices that is from 5 to 0.
	int k[10];
	*k = 7;
	printf("%d\n",k[0]);
	*(k + 1) = 10;
	printf("%d\n\n\n",k[1]);

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

//Find the min , max element in array
void min_max (int a[],int s,int* min,int* max){
	*max = *min = a[0];
	for (int i = 1; i < s; i++){
		if (*max < a[i])
			*max = a[i];
		else if (*min > a[i])
			*min = a[i];
	}
}

// Return a pointer to the biggest of 2 integer numbers
int* foomax(int* a,int* b) {
	if (*a < *b)
		return b;
	else
		return a;
}

