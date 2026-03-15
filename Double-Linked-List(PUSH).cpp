#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	
	struct node* next;
	struct node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int val){
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void pushHead(int val){
	Node* newNode = createNode(val);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void pushTail(int val){
	Node* newNode = createNode(val);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

void seeNode(){
	if(head == NULL){
		printf("Linklist is empty\n");
		return;
	}
	
	Node* curr = head;
	
	while(curr != NULL){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

int main(){
	pushHead(1);
	pushHead(2);
	pushHead(3);
	pushHead(4);
	pushHead(5);
	pushHead(6);
	
	seeNode();
	
	pushTail(7);
	pushTail(8);
	pushTail(9);
	pushTail(10);
	pushTail(11);
	
	seeNode();
	
	return 0;
}
