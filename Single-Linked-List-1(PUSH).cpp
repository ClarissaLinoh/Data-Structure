//SINGLE LINKLIST --> PUSH & TRANSVERSAL

#include <stdio.h>
#include <stdlib.h>

//Template Node
typedef struct node{
	int val;
	struct node *next;
}Node;

//variabel head dan tail sebagai awal dan akhir dari linklist
Node* head = NULL;
Node* tail = NULL;

//fungsi untuk membuat Node baru
Node* createNewNode(int val){
	//membuat sebuah node baru
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	//mengkopi semua data ke node baru
	newNode->val = val;
	newNode->next = NULL;
	
	//me-return node yang sudah dibuat
	return newNode;
}

//Memasukkan Node dari depan / head
void pushHead(int val){
	//memanggil fungsi createNewNode untuk membuat node baru
	Node* newNode = createNewNode(val);
	
	//jika head tidak ada / linklist kosong
	//maka head dan tail adalah newNode
	if(head == NULL){ 
		head = newNode;
		tail = newNode;
	}
	
	else {
		//newNode menunjuk alamat head sebelumnya
		newNode->next = head;
		
		//newNode menjadi head baru
		head = newNode;
	}
}

//Menambah node dari paling belakang (tail)
void pushTail(int val){
	
	//membuat node baru
	Node* newNode = createNewNode(val);
	
	//Jika linkList kosong maka node baru adalah head dan tail
	if(tail == NULL){
		head = newNode;
		tail = newNode;
	}
	
	//Jika tidak kosong maka:
	else {
		//tail next adalah newNode
		tail->next = newNode;
		
		//newNode menjadi tail baru
		tail = newNode;
	}
}

//Meletakkan node baru di tengah-tengah
void pushMid(int val){
	
	//membuat node baru
	Node* newNode = createNewNode(val);
	
	//jika head dan tail kosong maka node baru adalah head dan tail
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	
	//menghitung jumlah dari node
	//curr mulai di head (node paling depan)
	Node* curr = head;
	
	//count diletakkan di 1 karena curr sudah berada di posisi 1 (head)
	int count = 1;
	while(curr != NULL){
		count++;
		curr = curr->next;
	}
	
	//mencari nilai tengah
	//asumsi ganjil genap diabaikan
	int mid = count / 2;
	
	//reset count ke 1
	count = 1;
	
	//reset curr ke head
	curr = head;
	
	//curr adalah node yang berada di tengah
	while(count < mid){
		curr = curr->next;
		count++;
	}
	
	//newNode next adalah nextnya current
	newNode->next = curr->next;
	
	//current next adalah newNode
	curr->next = newNode;
	
}


//function untuk melihat isi dari LinkList
void nodeTransversal(){
	
	//jika misalkan head adalah NULL otomatis linklist belum memiliki data
	if(head == NULL){
		printf("LinkList is empty\n");
		return;
	}
	
	//dibuat sebuah curr --> node temporary utk transversal
	//dimulai dari head
	Node* curr = head;
	
	//selama curr tidak NULL maka print isi dari node
	while(curr != NULL){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	
	printf("NULL\n");
}



int main(){
	nodeTransversal();

	pushHead(1);
	pushHead(2);
	pushHead(3);
	pushHead(4);
	pushHead(5);
	pushHead(6);
	pushMid(7);
	pushTail(8);
	pushTail(9);
	pushMid(10);
	
	nodeTransversal();

	return 0;
}

