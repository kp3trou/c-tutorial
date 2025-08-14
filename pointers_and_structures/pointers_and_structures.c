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
	printf("%s\n",p1.firstname);
	printf("%s\n",p1.lastname);
	printf("%d\n\n",p1.age);

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


	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}


