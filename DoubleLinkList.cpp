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
	
	head->prev = newNode;
	newNode->next = head;
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

void pushMid(int val, int pos){
	Node* newNode = createNode(val);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	Node* curr = head;
	int flag = 1;
	while(curr->next != NULL && flag != pos-1){
		curr = curr->next;
		flag++;
	}
	
	if(flag < pos-1){
		printf("Position non-exist\n");
		return;
	}
	
	newNode->next = curr->next;
	curr->next->prev = newNode;
	newNode->prev = curr;
	curr->next = newNode;
	
}

void deleteHead(){
	if(head == NULL){
		printf("Linklist is empty");
		return;
	}
	
	head = head->next;
	free(head->prev);
	head->prev = NULL;
}

void deleteTail(){
	if(head == NULL){
		printf("Linklist is empty");
		return;
	}
	
	tail = tail->prev;
	free(tail->next);
	tail->next = NULL;
}

void seeNode(){
	if(head == NULL){
		printf("linklist is empty");
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
	
	seeNode();
	
	pushTail(5);	
	pushTail(6);	
	pushTail(7);	
	pushTail(8);	
	
	seeNode();
	
	deleteHead();
	seeNode();
	
	pushHead(9);
	seeNode();
	
	deleteTail();
	seeNode();
	
	pushTail(10);
	seeNode();
	
	pushMid(11, 4);
	seeNode();
	
	pushMid(12, 12);
	seeNode();
	
	return 0;
}
