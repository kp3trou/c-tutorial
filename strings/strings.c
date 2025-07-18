#include <stdio.h>
#include <string.h>

// Function declaration
int foobar (char s[]);

int main(){

	// Section 1
	// String literals
	
	char* str = "abc"; // Strings stored in memory as array of characters.
	printf("the string is '%s'\n",str);
	printf("size of 'abc' is %d\n",sizeof("abc")); // add character \0 at the end(null terminator).
	char* p = "abc";
	printf("%c\n",p[0]);
	printf("%c\n",p[1]);
	printf("%c\n",p[2]);
	printf("%d\n",p[3]);// number of \0 in ascii table
	//printf("%c\n",p[3]); // uncomment me and see what happens !!!
	char s[] = "hello";
	printf("%s\n",s);
	char s2[] = {'h','e','l','l','o','\0'};
	printf("%s\n",s2);
	char* t = "string";
	for(int i = 0; i < 6 ; i++)
		printf("%c\n",t[i]);
	puts(t);
	puts(s);
	char string[] = "I love Linux";
	printf("the string has %d spaces\n",foobar(string));
	char* g = "I love Linux and C";
	printf("the string has %d spaces\n",foobar(g));

	//Section 2
	// Standard C library
	// Prototype of strcpy : char *strcpy(char *s1, const char *s2);
	// Copies the string tha s2 points in array that s1 points.
	char str_2[] = "Deer";
	char str_1[5]; // the lenght must be minimum 5
	strcpy(str_1,str_2);
	printf("the copied string is '%s'\n",str_1);
	// Prototype of strlen : size_t strlen(const char *str);
	// Returns sum of characters exist in string without the last \0
	char* st = "world";
	printf("number of characters are %d",strlen(st));

	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

// Count spaces
int foobar (char s[]) {
	int count = 0;
	for(int i = 0; s[i] != '\0' ; i++)
		if (s[i] == ' ')
		count += 1;
	return count;
}

