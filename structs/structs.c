#include <stdio.h>
#include <string.h>

struct student {
	char first_name[128];
	char last_name[128];
	unsigned int year;
	double grade;
} s1,s2;

typedef struct {
	int a;
	double d;
} Part;

struct point {
	int x;
	int y;
};

typedef struct mystruct {
	int a;
	double d;
} Mystr;


struct part {
	double k;
	int j;
} prt1,prt2;

struct my_struct {
	struct student name;
	int w;
};

// function declaration/prototype
void print_part (struct part p);
struct part build_part(double number,int z);

int main(){
	// Section 1
	/*
	Struct is a data structure.
	The elements of struct called members. 
	Declare struct : struct struct_name { members } ;
	Declare struct variable : struct struct_name variable_name;
	Examples : 
	struct student , st1, st2;// st1, st2 variable names
	struct student* student_pointer; // pointer as struct student
	struct student student_array[100]; // array with 100 struct student
	*/
	s1.year = 1980;
	printf("%d\n",s1.year);
	s2.year = 1984;
	printf("%d\n",s2.year);
	struct student s3;
	s3.year = 2000;
	printf("%u\n",s3.year);
	strcpy(s1.first_name,"John");
	printf("%s\n",s1.first_name);	
	strcpy(s1.first_name,"Deer");
	printf("%s\n",s1.last_name);	
	s1.grade = 19.0;
	printf("%.2f\n",s1.grade);
	// Memory addresses of struct members (continuous memory addresses).
	printf("Address of s1: %p\n", (void*)&s1);
	printf("Address of s1.first_name: %p\n", (void*)&s1.first_name);
	printf("Address of s1.last_name: %p\n", (void*)&s1.last_name);
	printf("Address of s1.year: %p\n", (void*)&s1.year);
	printf("Address of s1.grade:  %p\n\n", (void*)&s1.grade);
	// Part as typedef
	Part part1,part2;
	part1.a = 1;
	printf("%d\n\n\n",part1.a);

	// Section 2
	struct point p1 = {3,4};
	printf("%d , %d \n",p1.x,p1.y);
	struct point p2;
	printf("%d , %d \n",p2.x,p2.y); // prints garbage
	p2 = p1;
	printf("%d , %d \n",p2.x,p2.y); // now?
	Mystr str1 = {100,200.234};
	printf("%d , %.4f \n",str1.a,str1.d); // now?

	// Section 3
	// Structures as arguments
	prt1.k = 19.34;
	prt1.j = 2022;
	print_part(prt1);
	// Structures as return types
	prt2 = build_part(10.3,34);	
	print_part(prt2);

	// Section 4
	// Nested structures
	struct my_struct st;
	strcpy(st.name.first_name,"george");
	st.w = 2025;
	printf("%s , %d \n\n",st.name.first_name,st.w); 

	// Section 5
	// Arrays as structs
	struct part inventory[5];
	inventory[0].k = 10.23;
	inventory[0].j = 12;
	print_part(inventory[0]);

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// Prints the struct part members values 
void print_part (struct part p) {
	printf("part k is %.4f\n",p.k);
	printf("part j is %d\n",p.j);
}

// Returns a part struct and full from arguments
struct part build_part(double number,int z){
	struct part p3;
	p3.k = number;
	p3.j = z;
 	return p3;
}



