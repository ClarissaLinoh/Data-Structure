//SINGLE LINKLIST --> PUSH BY QUEUE / DELETE BY QUEUE / BY DATA

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

//memasukkan node baru berdasarkan urutan baris yang diinginkan
void pushByQue(char name[], int val, int que){
	
	//verifikasi apakah linklist memiliki isi
	if(head == NULL){
		printf("LinkList is empty\n");
		return;
	}
	
	//sebuah node temporary
	Node *curr = head;
	int count = 1;
	
	//jika misalkan que lebih dari satu atau que (urutan) yang diinginkan bukan di depan
	//maka que dikurang 1, sehingga nantinya node baru berada di posisi yang diinginkan
	if(que > 1) que -= 1;
	else{
		//jika misalkan que kurang dari atau sama dengan 1 maka dipanggil fungsi pushHead
		pushHead(name, val);
		return;
	}
	
	//dicari posisi yang diinginkan
	while(curr->next != NULL){
		if(count == que){
			break;
		}
		curr = curr->next;
		count++;
	}
	
	//dibuat node baru
	Node *newNode = createNode(name, val);
	
	newNode->next = curr->next;
	curr->next = newNode;
}

void deleteByQue(int que){
	
	//verifikasi apakah linklist memiliki isi
	if(head == NULL){
		printf("LinkList is empty\n");
		return;
	}
	
	//diatur que - 1 sehingga didapat satu node sebelum node yang ingin dihapus
	if(que > 1) que -= 1;
	else{
		//jika misalkan que kurang dari atau sama dengan 1 maka dipanggil fungsi pushHead
		popHead();
		return;
	}
		
	//sebuah node temporary
	Node *curr = head;
	int count = 1;
	int flag = -1;
	
	//dicari posisi yang diinginkan
	while(curr->next != NULL){
		if(count == que){
			flag = 8;
			break;
		}
		curr = curr->next;
		count++;
	}
	
	if(flag == -1){
		printf("Node doesn't exist\n");
		return;
	}
	
	Node *temp = curr->next;
	curr->next = temp->next;
	free(temp);
}

void deleteByVal(int val){
	
	//verifikasi apakah linklist memiliki isi
	if(head == NULL){
		printf("LinkList is empty\n");
		return;
	}
		
	//sebuah node temporary
	Node *curr = head;
	int count = 1;
	int flag = -1;
	
	//dicari posisi yang diinginkan
	while(curr->next != NULL){
		if(curr->val == val){
			flag = 8;
			break;
		}
		curr = curr->next;
		count++;
	}
	
	//jika flag -1 berarti node yang dicari tidak ada
	if(flag == -1){
		printf("Node doesn't exist\n");
		return;
	}
	
	//diatur count - 1 sehingga didapat satu node sebelum node yang ingin dihapus
	if(count > 1) count -= 1;
	else{
		//jika misalkan count sama dengan 1 maka dipanggil fungsi popHead
		popHead();
		return;
	}
	
	//reset posisi current	
	curr = head;
	int idx = 1;
	while(curr->next != NULL){
		if(idx == count){
			break;
		}
		curr = curr->next;
		idx++;
	}
	
	Node *temp = curr->next;
	curr->next = temp->next;
	free(temp);
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
	
	printf("\nPUSH BY QUEUE\n");
	printf("------------------------------------------------\n");
	
	pushByQue("Golf", 7, 4);
	//akan berada di posisi ke-4 --> mendorong node posisi ke-4 sebelumnya ke posisi ke-5
	nodeTransversal();
	
	//node diletakkan di posisi 1 atau terdepan
	pushByQue("Hotel", 8, 1);
	nodeTransversal();
	
	//node diletakkan di posisi 9 atau paling akhir
	pushByQue("India", 9, 9);
	nodeTransversal();
	
	//que yang diinginkan tidak terdata (jumlah node baru 10) maka otomatis diletakkan di akhir
	pushByQue("Juliet", 10, 20);
	nodeTransversal();
	
	printf("\nDELETE BY QUEUE\n");
	printf("------------------------------------------------\n");
	
	//Golf | 7 yang berada di posisi 5 dihapus
	deleteByQue(5);
	nodeTransversal();
	
	//Hotel | 8 yang berada di posisi paling depan / 1 dihapus
	deleteByQue(1);
	nodeTransversal();	
	
	//posisi 44 tidak ada
	deleteByQue(44);
	nodeTransversal();	
	
	printf("\nDELETE BY VALUE\n");
	printf("------------------------------------------------\n");	
	deleteByVal(5);
	nodeTransversal();	
	
	deleteByVal(0);
	nodeTransversal();	
	
	deleteByVal(89);
	nodeTransversal();	
	
	deleteByVal(6);
	nodeTransversal();	

	return 0;
}

