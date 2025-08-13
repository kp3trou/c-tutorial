#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void foobar();
void foo(char *a,int print);
size_t strlength(char* string);

// global variables
char* globalheader = "Chapter";

int main(){
	// Section 1
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof('a'));
	char c = 'a';
	printf("%d\n\n",sizeof(c));
	// String declarations are supported in one of three ways:
	// as a literal,
	// as an array of characters,
	// using a pointer to a character
	// String literal is a sequence of characters enclosed in double quotes: "hello"
	
	// array of characters
	// Remember that the array of chars, must have and '\0' at the end
	char header_1[32];// here we can use only the 31 elements of the array
	// pointer to a character	
	char *header_2;
	// String Literal Pool
	// When literals are defined they are frequently assigned to a literal pool
	// This area of memory holds the character sequences making up a string.
	// This area is read-only memory
	char *tabheader = "Sound";// good practice is use: const char *tabheader.
	//*tabheader = 'L';// Segmentation fault when try to change the string
	printf("%s\n",tabheader);

	// Section 2
	// String Initialization
	// 2.1: initializing an array of char
	char header[] = "Media Player";// 12 characters lenght and '\0', total lenght 13 bytes.
	printf("%d\n",sizeof("Media Player"));
	printf("%d\n\n",sizeof(header));
	char header_3[13];
	strcpy(header_3,"Media Player");
	printf("%s\n\n",header_3);
	char header_4[4];
	header_4[0] = 'M';
	header_4[1] = 'e';
	header_4[2] = 'd';
	header_4[3] = '\0';
	printf("%s\n\n",header_4);
	// using pointer arithmetic
	char header_5[4];
	*(header_5) = 'M';
	*(header_5+1) = 'e';
	*(header_5+2) = 'd';
	*(header_5+3) = '\0';
	printf("%s\n\n",header_5);
	// 2.2: initializing a poinetr to char
	char *pheader = (char*)malloc(strlen("Media Player")+1);// same as: (char*) malloc(13)
	strcpy(pheader,"Media Player");
	printf("%s\n\n",pheader);
	free(pheader);
	// using pointer arithmetic
	char *pheader_2 = (char*)malloc(4);
	*(pheader_2) = 'M';
	*(pheader_2+1) = 'e';
	*(pheader_2+2) = 'd';
	*(pheader_2+3) = '\0';
	printf("%s\n",pheader_2);
	free(pheader_2);
	
	// String Literal "Media Player" is stored String Literal Pool, outside Stack frame
	// and have it's own memory address.
	// When use same string literals, they share the same memory address.
	char *s = "Media Player";
	printf("%p\n",(void*)s);
	printf("%p\n",(void*)"Media Player");

	// char *p = 'a';// Compiler error
	char *p = (char*)malloc(2);
	*p = 'a';
	*(p+1) = '\0';// same as *(p+1) = 0;
	printf("%s\n\n",p);
	free(p);
	
	// The problem here is we have not assigned memory to command variable.Wrong.
	//char* command;
	//printf("Enter a Command : ");
	//scanf("%s",command);

	char* lheader = "Chapter";// Stored at String Literal Pool
	char llheader[] = "Chapter";// Stored at stack memory
	printf("%p\n",(void*)lheader);
	printf("%p\n",llheader);
	printf("%p\n",(void*)globalheader);// Stored at the same address at String Literal Pool
	foobar();
	printf("\n------------------\n");

	// Section 3
	// Standard String Operations: comparing, copying, concatenating
	// Comparing Strings
	// prototype: int strcmp(const char *s1, const char *s2);
	// returns: negative if s1 precedes s2 lexicographically (alphabetically),
	// 0 if the two strings are equal,
	// positive if s1 follows s2 lexicographically
	char command[16] = "Quity";// memory allocation, 16 bytes
 	if (strcmp(command, "Quit") == 0){ 
 		printf("The command was Quit\n");
	}
   	else { 
 		printf("The command was not Quit\n");
		printf("%d\n",strcmp(command, "Qui"));// 't' (116) - '\0' (0) = 116
	}
	// if (command == "Quit"){...}, Wrong because command stores memory address of the array.

	// Copying Strings
	// prototype: char* strcpy(char *s1, const char *s2);
	// Returns a char* pointer of the first argument
	char *names[3];// create an array of char* names pointers, 3 pointers
	char name_1[5] = "John";
	char name_2[5] = "Paul";
	char name_3[7] = "George";
	size_t count = 0;// size_t is unsigned integer
	names[count] = (char*)malloc(strlen(name_1)+1);
 	strcpy(names[count],name_1);
 	count++;
	names[count] = (char*)malloc(strlen(name_2)+1);
 	strcpy(names[count],name_2);
 	count++;
	names[count] = (char*)malloc(strlen(name_3)+1);
	strcpy(names[count],name_3);
 	for(int i=0;i<=count;i++){
		printf("%s\n",(names[i]));
		free(names[i]);
	}
	printf("\n\n");	

	// Concatenating Strings
	// prototype: char *strcat(char *s1, const char *s2);
	// returns a pointer to the concatenated results(pointer to the first string)
	// The function concatenates the second string s2 to the end of the first string s1.	
	char *error = "ERROR: ";
	char *errormsg = "Not enough memory";
	char* buffer = (char*)malloc(strlen(error)+strlen(errormsg)+1);
	strcpy(buffer,error);
	strcat(buffer, errormsg);
	printf("%s\n", buffer);
	printf("%s\n", error);
	printf("%s\n", errormsg);
	printf("%d\n", strlen(buffer));
	printf("%d\n", strlen(error));
	printf("%d\n\n", strlen(errormsg));
	free(buffer);
	// the '\0' from error replaced when use strcat(buffer, errormsg),
	// with the first character of errormsg 'N',
	// and after put a single '\0' at the end of string buffer.
	char* c2 = "John ";
	char* d = "Deer";
	char* b = (char*)malloc(strlen(c2) + strlen(d) + 1);
	strcpy(b,c2);
	strcat(b,d);
	for (int i=0;i<strlen(b);i++){// if use i<=strlen(b),the last 2 printfs are not at sdtout.
		printf("%c\n",b[i]);
		printf("%c\n",*(b+i));
	}
	printf("full string: %s\n",b);
	printf("string lenght: %d\n",strlen(b));
	free(b);
	// same logic as above,	using arrays of strings
	char c3[] = "John ";
	char d2[] = "Deer";
	char* b2 = (char*)malloc(strlen(c3) + strlen(d2) + 1);
	strcpy(b2,c3);
	strcat(b2,d2);
	// strlen works both for char* and char ar[].
	for (int i=0;i<strlen(b2);i++){// if use i<=strlen(b),the last 2 printfs are not at sdtout.
		printf("%c\n",b2[i]);
		printf("%c\n",*(b2+i));
	}
	printf("full string: %s\n",b2);
	printf("string lenght: %d\n\n",strlen(b2));
	free(b2);
	printf("\n------------------\n");
	// simple second way to print a string, need for next.
	char *f = "hello";
	while(*f){
		printf("%c\n",*f);
		f++;
	}
	printf("\n------------------\n");
	// Section 4
	// Passing Strings to a function
	// 4.1: Passing a simple string
	char simplearray[] = "simple string";
	char *simarr = "hello";	
	foo(simplearray,0);// turn 0 to 1, if you want to see the chars of that string
	foo(simarr,0);
	printf("%d\n",strlength(simplearray));
	printf("%d\n",strlength(&simplearray[0]));
	char *simpleptr = (char*)malloc(strlen("simple string")+1);
	strcpy(simpleptr, "simple string");
	printf("%d\n",strlength(simpleptr));
	free(simpleptr);

















	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// Only printing
void foobar(){
	printf("foobar, %p\n",(void*)globalheader);// Stored at the same address at String Literal Pool
	char *s = "Chapter";
	printf("foobar, %p\n",(void*)s);// String Literal Pool address
	char local[] = "Chapter";
	printf("foobar, %p",(void*)local);// stored at foobar stack frame as local array
}

// print a simple string-optional print the chars of the string
void foo(char *a,int print){
	printf("%s\n\n",a);
	if(print){
		for(int i =0;i<strlen(a);i++){
			printf("%c\n",a[i]);
		}
	}
}

// return the lenght of the string that pass as argument, arg is char*
size_t strlength(char* string){// char* string same as: char string[]
	size_t length = 0;
	//printf("function, %s\n",string);
	while(*(string++)){
		length++;
	}
	//printf("function, %d\n",length);
	return length;
}












