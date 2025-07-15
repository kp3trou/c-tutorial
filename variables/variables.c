#include <stdio.h>

typedef int INT;

int main(){

	// Section 1
	int my_int = 123;
	printf("my_int is : %d\n",my_int);
	double my_double = 123.3456;
	printf("my_double is : %f\n",my_double);
	printf("my_double with 2 digits is : %.2f\n",my_double);
	float my_float = 345.3456f;// put f because my_float, c treated it as double
	printf("my_float is : %f\n",my_float);

	// Section 2
	if (1){
		printf("True \n");
	}
	if (5){
		printf("True \n");
	}
	if (0){
		printf("True \n");
	}

	// Section 3
	int i, n;
	i = 1;
	n=5;
 	while (i <= n) {
 		printf("%12d%12d\n", i, i * i);
 		i++;
 	}

	// Section 4
	int sum, j;	
	//only to show how comma works with expressions
	for (sum = 0,  j = 1; j <= 5; j++){
		sum += j;
	}
	printf("sum is : %d\n",sum);

	// Section 5
	char my_ch = 'a';
	printf("my_ch is : %c\n",my_ch);
	char my_ch2 = 52;// ASCII code 52 corresponds to the character '4'
	printf("my_ch2 is : %c\n",my_ch2);
	printf("my_ch2 is : %d\n",my_ch2);
	printf("my_ch2 is : %d\n",my_ch2+1);
	printf("my_ch is : %c\n",my_ch+1);
	char ch;
	for(ch = 'A';ch<'D';ch++){
		printf("hello !!!\n");
	}	

	// Section 6 Casting
	float my_f = 4.634;
	printf("my_f is : %d\n",(int)my_f);

	// Section 7 typedef
	INT inta,intb ;
	inta = 1;
	intb = 2;
	printf("inta is : %d , intb is : %d\n",inta,intb);

	printf("There are a lot more to discover at the previous sections...\n");

	return 0;
}
