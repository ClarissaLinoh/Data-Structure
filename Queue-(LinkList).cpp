#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[80];
	int age;
	
	struct node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(char name[], int age){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->age = age;
	newNode->next = NULL;
	
	return newNode;
}

void enqueue(char name[], int age){
	Node* insert = createNode(name, age);
	
	if(head == NULL){
		head = insert;
		tail = insert;
	}
	
	else {
		Node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		
		curr->next = insert;
		tail = insert;
	}
}

void dequeue(){
	if(head == NULL){
		printf("The queue is empty");
	}
	else if (head == tail){
		head = NULL;
		tail = NULL;
	}
	else {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

void checkHead(){
	if(head == NULL){
		printf("The queue is empty\n");
		return;
	}
	printf("1st queue is %s age %d\n", head->name, head->age);
}

void queueLeng(){
	if(head == NULL){
		printf("The queue is empty\n");
		return;
	}
	
	Node* curr = head;
	int val = 1;
	while(curr->next != NULL){
		curr = curr->next;
		val++;
	}
	
	printf("The last queue is %s with age %d\n", curr->name, curr->age);
	printf("The queue leng is %d\n", val);
}

void viewQueue(){
	Node* curr = head;
	
	while(curr){
		printf("[ %s | %d ] -> ", curr->name, curr->age);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

int main(){
	enqueue("Cilly", 60);
	enqueue("Lucy", 20);
	enqueue("Anne", 20);
	enqueue("Amy", 20);
	enqueue("Alice", 20);
	viewQueue();
	
	dequeue();
	viewQueue();
	
	checkHead();
	queueLeng();
	return 0;
}
