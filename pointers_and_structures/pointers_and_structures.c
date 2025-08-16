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

typedef struct alternatePerson {
	char* firstname;
	char* lastname;
	char* title;
	short age; 
} AlternatePerson;

// function declaration
void initialize_person(Person *person, const char* fn,const char* ln, const char* title, uint age);
void process_person();
void deallocate_person(Person *person);
void print_object (Person *person);

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

	printf("\n-----------------\n");
	// Section 2
	// How memory allocates for a structure
	Person person2;
	printf("%d\n",sizeof(person2)); // Displays 32
	AlternatePerson otherperson;
	printf("%d\n",sizeof(otherperson)); // Displays 32,why? same as above, because of padding.
	printf("%p\n",(void*)&otherperson);
	printf("%p\n",(void*)&otherperson.firstname);
	printf("%p\n",(void*)&otherperson.lastname);
	printf("%p\n",(void*)&otherperson.title);
	printf("%p\n\n",(void*)&otherperson.age);
	
	// dynamic allocate memory inside a struct
	struct person p2;// memory of p2 deallocates from stack inside main automatically
	p2.firstname = (char*)malloc(strlen("Emily")+1);
	strcpy(p2.firstname,"Emily");
	printf("%s\n\n",p2.firstname);
	free(p2.firstname);// must deallocate the memory because is at heap

	// create a struct at dynamic allocate memory -> heap
	struct person *p3 = (struct person*)malloc(sizeof(struct person));
	printf("%d\n",sizeof(struct person));// size of the struct	
	printf("%d\n",sizeof(p3));// size of the pointer
	p3->firstname = (char*)malloc(strlen("Emily")+1);
	strcpy(p3->firstname,"Emily");
	printf("%s\n\n",p3->firstname);
	free(p3->firstname);// first deallocate nested dynamic memory
	free(p3);// at the end deallocate the struct's dynamic memory

	Person *p4 = malloc(sizeof(Person));// p4 is in stack and points at struct.
										// Struct is in heap.
	//Person *p4 = (Person*)malloc(sizeof(Person));// same as above.
	initialize_person(p4,"Peter","Underwood","Manager",36);
	printf("%s\n",p4->firstname);
	printf("%s\n",p4->lastname);
	printf("%s\n",p4->title);
	printf("%d\n\n",p4->age);
	free(p4->firstname);
	free(p4->lastname);
	free(p4->title);
	free(p4);

	Person p5;// p5 and struct are in main stack frame,no need for free.Only for members of struct.
	initialize_person(&p5,"Peter","Underwood","Manager",36);
	printf("%s\n",p5.firstname);
	printf("%s\n",p5.lastname);
	printf("%s\n",p5.title);
	printf("%d\n\n",p5.age);
	free(p5.firstname);
	free(p5.lastname);
	free(p5.title);
	
	printf("\n-----------------\n");

	// Static objects -> structs are in stack memory
	process_person();// creates a struct object at process_person stack frame.No dynamic memory.
					 // Deallocation from stack memory the struct.Automatically.
					 // Only members of the struct deallocation dynamically using free().

	/*********** Be careful :
	
	Person p6;// creates a struct Person at the stack.
	Person *p7;// creates a pointer that points to struct Person.Mo members, nothing.
	Person *p8 = malloc(sizeof(Person));// creates a struct at heap and pointer at stack.
	free(p8); // needs free.

	***********/

	// Dynamic objects -> structs are in heap memory



	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}



// function for initiallization of a struct
void initialize_person(Person *person, const char* fn,const char* ln, const char* title, uint age) {
	person->firstname = (char*) malloc(strlen(fn) + 1);
	strcpy(person->firstname, fn);
	person->lastname = (char*) malloc(strlen(ln) + 1);
	strcpy(person->lastname, ln);
	person->title = (char*) malloc(strlen(title) + 1);
	strcpy(person->title, title);
	person->age = age;
}

void process_person(){
	Person person;
	initialize_person(&person, "John", "Deer", "Manager", 40);
	print_object(&person);
	deallocate_person(&person);
}

// deallocation from stack.Arg1 is a pointer to an object type Person.
void deallocate_person(Person *person) {
	free(person->firstname);
	free(person->lastname);
	free(person->title);
}

// only for print object members.Arg1 is a pointer to an object type Person.
void print_object (Person *person){
	printf("%s\n",person->firstname);
	printf("%s\n",person->lastname);
	printf("%s\n",person->title);
	printf("%d\n",person->age);
}














