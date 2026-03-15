// PRIORITY QUEUE WITH SINGLE LINKLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[100];
	int pr;
	
	struct node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(char name[], int pr){
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	strcpy(newNode->name, name);
	newNode->pr = pr;
	newNode->next = NULL;
	
	return newNode;
}

void pushNode(char name[], int pr){
	Node* newNode = createNode(name, pr);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	Node* curr = head;
	
	while(curr->next != NULL && curr->next->pr <= newNode->pr){
		curr = curr->next;
	}
	
	newNode->next = curr->next;
	curr->next = newNode;
}

void seeNode(){
	if(head == NULL){
		printf("Priority Queue is Empty\n");
		return;
	}
	
	Node* curr = head;
	while(curr != NULL){
		printf("[ %s | %d ]-> ", curr->name, curr->pr);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

int main(){
	
	pushNode("Alpha", 1);
	pushNode("Beta", 4);
	pushNode("Charlie", 2);
	pushNode("Echo", 1);
	pushNode("Foxtron", 5);
	pushNode("Golf", 6);
	
	seeNode();
	
	
	return 0;
}
