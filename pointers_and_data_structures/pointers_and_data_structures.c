#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Use typedef's before function declarations, because the compiler needs 
// to know first, if any function is using them.

// Global declaration function pointers
typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*,void*);

//linked list's data
typedef struct employee{
	char name[32];
	unsigned char age;
} Employee;

// linked list's node
typedef struct node {
	void *data;// generic pointer
	struct node *next;// pointer to the next node
} Node;

// hold's pointers to the haid and tail.
typedef struct linkedlist {
	Node *head;// pointer to Node struct at head
	Node *tail;// pointer to Node struct at tail
	Node *current;// pointer to Node struct at current
} LinkedList;

// functions declarations for function pointers
void foo(char* s);
int add(int a, int b);
int subtract(int a, int b);
void calc(int a, int b, int (*op)(int, int));
int sum(int x, int y);

// functions declarations for linked list
int compare_employee(Employee *e1, Employee *e2);
void display_employee(Employee* employee);
void initialize_list(LinkedList *list);
void add_head(LinkedList *list, void* data);
void add_tail(LinkedList *list, void* data);
Node *get_node(LinkedList *list, COMPARE compare , void* data);
void delete(LinkedList *list, Node *node);
void display_linked_list(LinkedList *list, DISPLAY display);



int main(){		
	// Section 0
	// Introduction Function Pointers	
	// Some function pointer examples, because we are going to use them.	
	void (*fptr)(char* s);// local function pointer fptr declaration
	//void (*fptr)(char*);// same as above
	printf("memory address of function pointer fptr points is %p\n",(void*)fptr);
	printf("memory address of function foo is %p\n",(void*)foo);// address is at Code/Text segment.
	// The memory address of a function is read-only memory.
	fptr = foo;// the name of a function acts as a pointer.
	//fptr = &foo;// same as the above.
	printf("memory address of function pointer fptr points is %p\n",(void*)fptr);
	fptr("Function pointer works!\n");// call function foo through fptr pointer

    // Passing different functions to function calc
    calc(10, 5, add);
  	calc(10, 5, subtract);

	// Assign function pointer, call function through function pointer
	int (*fn)(int,int);
	fn = sum;
	int x = fn(12,10);
	int y = (*fn)(12,11);// (*fn) same as fn.
	printf("%d\n",x);
	printf("%d\n",y);

	// Section 1
	// Pointers and Data structures
	// Data Structures are ways to organise and store data in memory.
	// Examples: array, Linked List, Queue, Stack,Tree.
	// 1.1: Linked List
	// A linked list consists of nodes connected to one another.
	// Each node will hold usersupplied data.
	// 1.1.1: Single Linked List
	// A linked list is a data structure that consists of a series of nodes interconnected with
	// links. Typically, one node is called the head node and subsequent nodes follow the head,
	// one after another. The last node is called the tail. The links connecting the nodes are
	// easily implemented using a pointer. Each node can be dynamically allocated as needed.
	// struct Employee is used for user's data, struct Node represents a Node,
	// struct LinkedList represents the linked list.
	
	// Before the linked list can be used it needs to be initialized.	
	// Creation of initialize_list function.
	// Creation of add_head function: add data at head of linked list
	// Creation add_tail function: add data at tail(end) of linked list.
	// add and delete functions are responsible for allocating and freeing memory from list.

	// create object linkedList inside main's stack frame
	LinkedList linkedList;

	//create objects type Employee and insert data to them:
	Employee *samuel = (Employee*) malloc(sizeof(Employee));
	strcpy(samuel->name,"Samuel");
	samuel->age = 32;

	Employee *sally = (Employee*) malloc(sizeof(Employee));
 	strcpy(sally->name, "Sally");
 	sally->age = 28;

 	Employee *susan = (Employee*) malloc(sizeof(Employee));
 	strcpy(susan->name, "Susan");
 	susan->age = 45;

	// initialize the linked list head, current, tail.Pass the object linkedList created before.
	initialize_list(&linkedList);

	// Create Nodes of linked list and add data to the head.
	add_head(&linkedList, samuel);
 	add_head(&linkedList, sally);
 	add_head(&linkedList, susan);
	// after the above we have: Susan -> Sally -> Samuel
	
	// display linked list
	display_linked_list(&linkedList, (DISPLAY)display_employee);

	// For adding data to the tail :
	// initializeList(&linkedList);
 	// addTail(&linkedList, susan);
 	// addTail(&linkedList, sally);
 	// addTail(&linkedList, samuel);
	// After the above we have: Susan -> Sally -> Samuel 
	
	// The delete function will remove a node from the linked list. To simplify this function,
	// a pointer to the node to be deleted is passed to it. The function’s user probably has a
	// pointer to the data but not to the node holding the data. To aid in identifying the node,
	// a helper function has been provided to return a pointer to the node: get_node.
	// The get_node function is passed three parameters:
	// A pointer to the linked list
	// A pointer to a comparison function
	// A pointer to the data to be foun 

	Node *node = get_node(&linkedList,(int (*)(void*, void*))compare_employee, sally);
 	delete(&linkedList, node);

	display_linked_list(&linkedList, (DISPLAY)display_employee);








	printf("\n\nThere are a lot more to discover at the previous sections...\n");
	return 0;
}

/***  functions definition  ***/

void foo(char* s){
	printf("%s\n",s);
}

// A simple addition function
int add(int a, int b) {
    return a + b;
}

// A simple subtraction function
int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(int, int)) {
    printf("%d\n", op(a, b));
}

// A simple another subtraction for educational issues, to see which addition is called.
int sum(int x, int y){
	return x+y;
}

// Returns 0,-1,1.Arguments are pointers to struct Employee.
int compare_employee(Employee *e1, Employee *e2) {
	return strcmp(e1->name, e2->name);
}

// Display a single employee.Argument is a pointer to struct Employee.
void display_employee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}

// function to initialize first the linked list(the members of the struct LinkedList)
// Takes arg a pointer to struct LinkedList
void initialize_list(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

// In the add_head function listed below, memory is first allocated for the node and the data
// passed to the function is assigned to the structure’s data field. By passing the data as a
// pointer to void, the linked list is able to hold any type of data the user wants to use.
// Next, we check to see whether the linked list is empty. If so, we assign the tail pointer to
// the node and assign NULL to the node’s next field. If not, the node’s next pointer is
// assigned to the list’s head. Regardless, the list’s head is assigned to the node:

void add_head(LinkedList *list, void* data) {
	Node *node = (Node*) malloc(sizeof(Node));// allocate memory for the node
	node->data = data;
	if (list->head == NULL) {
		list->tail = node;
		node->next = NULL;
	} 
	else {
		node->next = list->head;
	}
	list->head = node;
}

// The add_tail function is shown below. It starts by allocating memory for a new node
// and assigning the data to the data field. Since the node will always be added to the tail,
// the node’s next field is assigned to NULL. If the linked list is empty, then the head pointer
// will be NULL and head can be assigned to the new node. If it is not NULL, then the tail’s
// next pointer is assigned to the new node. Regardless, the linked list’s tail pointer is
// assigned to the node:

void add_tail(LinkedList *list, void* data) {
 	Node *node = (Node*) malloc(sizeof(Node));
 	node->data = data;
 	node->next = NULL;
 	if (list->head == NULL) {
 		list->head = node;
 	} 
	else {
 		list->tail->next = node;
 	}
 	list->tail = node;
}

// The code for the get_node function follows. The variable node initially points to the list’s
// head and traverses the list until either a match is found or the linked list’s end is en‐
// countered. The compare function is invoked to determine whether a match is found.
// When the two data items are equal, it returns a zero.

Node *get_node(LinkedList *list, COMPARE compare , void* data) {
 	Node *node = list->head;
 	while (node != NULL) {
 		if (compare(node->data, data) == 0) {
 			return node;
 		}
 		node = node->next;
 	}
 	return NULL;
}

// The delete function follows. To keep the function simple, it does not always check for
// null values in the linked list or the node passed. The first if statement handles a node
// to be deleted from the head. If the head node is the only node, then the head and tail
// are assigned null values. Otherwise, the head is assigned to the node following the head.
// The else statement traverses the list from head to tail using a tmp pointer. The while
// loop will terminate if either tmp is assigned NULL, indicating the node does not exist in
// the list, or the node following tmp is the node we are looking for.
// Since this is a singlelinked list, we need to know which node precedes the
// target node to be deleted.
// This knowledge is needed to assign the node following the target node to the preceding node’s
// next field. At the end of the delete function, the node is freed. The user is responsible
// for deleting the data pointed to by this node before the delete function is called.

void delete(LinkedList *list, Node *node) {
 	if (node == list->head) {
		if (list->head->next == NULL) {
 			list->head = list->tail = NULL;
 		} 
		else {
 			list->head = list->head->next;
 		}
 	}
   	else {
 		Node *tmp = list->head;
 		while (tmp != NULL && tmp->next != node) {
 			tmp = tmp->next;
 		}
 		if (tmp != NULL) {
 			tmp->next = node->next;
 		}
 	}
	free(node);
}

// The display_linked_list function illustrates how to traverse a linked list as shown be‐
// low. It starts at the head and displays each element using the function passed as the
// second argument. The node pointer is assigned the next field’s value and will terminate
// when the last node is displayed:

void display_linked_list(LinkedList *list, DISPLAY display) {
 	printf("\nLinked List\n");
 	Node *current = list->head;
 	while (current != NULL) {
 		display(current->data);
 		current = current->next;
	}
}























