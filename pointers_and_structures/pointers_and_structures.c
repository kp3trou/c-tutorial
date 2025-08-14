#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** structs definition: ***/

// define struct data type: struct person is the data type
struct person{
	char* firstname;
	char* lastname;
	char* title;
	unsigned int age;
};

// define a struct using typedef
typedef struct person_2{
	char* firstname;
	char* lastname;
	char* title;
	unsigned int age;
}Person;


int main(){
	// Section 1
	// struct declaration usually made in two steps:
	// define struct data type,
	// creation variable of the struct data type
	struct person p1;// creation of a variable p1, that has struct person as data type.
	p1.firstname = "John";
	p1.lastname = "Deer";
	p1.age = 23;
	p1.title = "Operating Systems";
	printf("%s\n",p1.firstname);
	printf("%s\n",p1.lastname);
	printf("%d\n",p1.age);
	printf("%s\n",p1.title);
	printf("address of pointer is %p\n",(void*)&p1);
	printf("address of pointer %p\n",(void*)&p1.firstname);// 8 bytes of pointer char* size
	printf("address of pointer %p\n",(void*)&p1.lastname);// 8 bytes of pointer char* size
	printf("address of pointer %p\n",(void*)&p1.title);// 8 bytes of of pointer char* size
	printf("address of pointer %p\n\n",(void*)&p1.age);// 4 bytes of integer size
	printf("struct members are in continuous memory addresses in stack frame.\n\n");
	printf("the size of the struct is %d bytes\n",sizeof(p1));
	printf("4 bytes extra memory for padding inside the struct\n");

	//the following memory addresses is outside stack frame, at String Literal Pool.
	printf("address that pointer points is %p\n",(void*)p1.firstname);// read-only memomory
	printf("address that pointer points is  %p\n",(void*)p1.lastname);// read-only memomory
	printf("address that pointer points is %p\n",(void*)p1.title);// read-only memory

	// Also we can use typedef for struct declaration
	Person person;// variable person creation, create an instance of a Person
	person.firstname = (char*)malloc(strlen("Emily")+1);
	strcpy(person.firstname,"Emily");
	person.age = 23;
	printf("%s\n",person.firstname);
	printf("%d\n\n",person.age);
	free(person.firstname);

	Person *ptrperson;// pointer creation that points to struct Person 
	ptrperson = (Person*)malloc(sizeof(Person));
	ptrperson->firstname = (char*)malloc(strlen("Emily")+1);
	strcpy(ptrperson->firstname,"Emily");
	ptrperson->age = 23;
	printf("%s\n",ptrperson->firstname);
	printf("%d\n\n",ptrperson->age);
	free(ptrperson->firstname);// first deallocate the nested dynamic memory allocation
	free(ptrperson);// at the end deallocate the struct's dynamic allocated memory

	// The following example with pointer struct declaration and usage is more awkward:
	Person *ptrperson2;
	ptrperson2 = (Person*)malloc(sizeof(Person));
	(*ptrperson2).firstname = (char*)malloc(strlen("Emily")+1);
	strcpy((*ptrperson2).firstname,"Emily");
	(*ptrperson2).age = 23;
	printf("%s\n",ptrperson2->firstname);
	free((*ptrperson2).firstname);
	free(ptrperson2);

	// Section 2
	// How memory allocates for a structure






	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}


