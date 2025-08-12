#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void foobar();

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









































	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

void foobar(){
	printf("foobar, %p\n",(void*)globalheader);// Stored at the same address at String Literal Pool
	char *s = "Chapter";
	printf("foobar, %p\n",(void*)s);// String Literal Pool address
	char local[] = "Chapter";
	printf("foobar, %p",(void*)local);// stored at foobar stack frame as local array
}





