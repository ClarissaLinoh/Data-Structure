//SINGLE LINKLIST --> POP / DELETE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Template node
typedef struct node{
	char name[50];
	int val;
	
	struct node* next;
}Node;

Node *head = NULL;
Node *tail = NULL;

Node* createNode(char name[], int val){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->val = val;
	newNode->next = NULL;
	
	return newNode;
}

//function pushHead untuk memasukkan node dari head (depan)
void pushHead(char name[], int val){
	
	//membuat node baru
	Node *newNode = createNode(name, val);
	
	//jika LinkList kosong node baru menjadi head & tail
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	//newNode next adalah head sebelumnya
	newNode->next = head;
	
	//newNode menjadi head baru
	head = newNode;
}

//menampilkan semua node
void nodeTransversal(){
	if(head == NULL){
		printf("LinkList is empty\n");
		return;
	}
	
	Node *curr = head;
	
	while(curr != NULL){
		printf("[%s | %d ] -> ", curr->name, curr->val);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

//fungsi menghapus dari depan
void popHead(){
	//jika head == NULL atau linklist kosong
	if(head == NULL){
		printf("Linklist is empty\n");
		return;
	} 
	
	//jika head adalah tail
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
		
	//temporary digunakan agar ketika pointer head menunjuk ke node berbeda
	//head sebelumnya masih bisa dihapus / free
	Node *temp = head;
	head = temp->next;
	free(temp);
}

//fungsi menghapus dari belakang
void popTail(){
	
	//jika misalkan linklist kosong
	if(head == NULL){
		printf("Linklist is empty\n");
		return;
	} 
	
	//jika misalkan head adalah tail / hanya 1 node yang ada
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	
	//node curr untuk berjalan hingga satu node sebelum tail
	Node *curr = head;
	
	while(curr->next != tail){
		curr = curr->next;
	}
	
	//hapus curr->next (curr->next seharusnya merupakan tail saat ini)
	free(curr->next);
	
	//assign curr sebagai value baru tail
	tail = curr;
	
	//tail next adalah NULL
	tail->next = NULL;
}


int main(){
	pushHead("Alpha", 1);
	pushHead("Bravo", 2);
	pushHead("Charlie", 3);
	pushHead("Delta", 4);
	pushHead("Echo", 5);
	pushHead("Foxtrot", 6);
	
	//Data full
	nodeTransversal();
	
	printf("\nPop Head\n");
	popHead();
	nodeTransversal();
	
	printf("\nPop Tail\n");	
	popTail();
	nodeTransversal();
	
	printf("\nPop Head\n");
	popHead();
	nodeTransversal();
		
	printf("\nPop Tail\n");	
	popTail();
	nodeTransversal();	
	
	return 0;
}

