#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//SIZE untuk ukuran array & LENGHT untuk panjang maks dari nama
#define SIZE 10
#define LENGTH 50

typedef struct node{
	char name[LENGTH];
	int price;
}Node;

//array untuk menyimpan data --> hash table
Node* arr[SIZE];

//variable jumlah isi dari array
int count = 0;

//untuk variable iterasi
int i = 0;

//membuat komponen hash table
Node* createNode(char name[], int price){
	Node* newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->price = price;
	
	return newNode;
}

//untuk menghitung nilai hashkey
int hash(char name[]){
	int key = 0;

	//mentotalkan nilai ascii	
	for(i = 0; i < strlen(name); i++){
		key += name[i];
	}
	
	//return value adalah jumlah ascii dari nama di modulo dengan ukuran array
	//sehingga nilainya masih dalam range array
	return key % SIZE;
}

//mencari nama
Node* search(char name[]){
	
	//start value di hashKey dari elemen yang dicari
	int hashKey = hash(name);
	int pos = hashKey;
	
	//menggunakan do while supaya jika pencarian sudah kembali ke posisi awal maka akan diakhiri
	do{
		//jika array pos tidak NULL/kosong dan isi dari array ke pos sama dengan yang dicari 
		//maka return array pos
		if(arr[pos] && strcmp(arr[pos]->name, name) == 0){
			return arr[pos];
		}
		
		//jika if tidak dijalankan maka:
		//nilai pos ditambah 1 kemudian di modulo dengan ukuran
		//sehingga berjalan ke posisi selanjutnya dan TETAP dalam range
		pos = (pos + 1) % SIZE;
		
	}while(pos != hashKey); //jika pos kembali sama dengan hashKey maka pencarian dihentikan
	
	//return NULL jika tidak ditemukan yang dicari
	return NULL;
}


//memasukkan value ke hash table
void insert(char name[], int price){
	int hashKey = hash(name);
	int pos = hashKey;
	
	//semua posisi penuh
	if(count == SIZE){
		printf("Full\n");
		return;
	}
	
	//ada collision --> komponen yang ingin dimasukkan memiliki hashKey yang sama dengan komponen yang sudah dimasukkan
	while(arr[pos] != NULL){
		pos = (pos+1) % SIZE; // mencari indeks yang tidak terisi / masih NULL
	}

	
	//posisi kosong
	arr[pos] = createNode(name, price);
	count++; //menghitung jumlah posisi yang terisi
}

//menghapus sebuah elemen
//prinsip +- dengan search
void removeChar(char name[]){
	int hashKey = hash(name);
	int pos = hashKey;
	
	do{
		if(arr[pos] && strcmp(arr[pos]->name, name) == 0){
			//jika sudah ditemukan free
			free(arr[pos]);
			//buat posisi kembali NULL sehingga bisa diisi lagi
			arr[pos] = NULL;
			return;
		}
		
		pos = (pos + 1) % SIZE;
		
	}while(pos != hashKey);
	
	return;
}

//untuk melihat isi dari hash table
void view(){
	for(i = 0; i < SIZE; i++){
		if(arr[i]){
			printf("[ %s : %d | hashKey = %d ]\n", arr[i]->name, arr[i]->price, hash(arr[i]->name));
		}
		else printf("[-]\n");
	}
}

int main(){
	
	insert("Alpha", 1); 
	insert("Beta", 2);
	insert("Charlie", 3);
	insert("Delta", 4);
	insert("Echo", 5);
	insert("Foxtron", 6);
	//Alpha & Charlie punya hashkey yang sama
	//Beta & Delta punya hashkey yang sama
	
	view();
	
	//hasil Exist karena Charlie memang ada di hash table
	if(search("Charlie")){
		printf("\nSearch Result = Exist\n\n");
	} else printf("\nSearch Result = Not exist\n\n");
	
	removeChar("Charlie");
	view();
	
	//hasil Not exist karena Charlie sudah dihapus dari hash table
	if(search("Charlie")){
		printf("\nSearch Result = Exist\n\n");
	} else printf("\nSearch Result = Not exist\n\n");
	
	//Charline bisa dimasukkan kembali ke hash table
	insert("Charlie", 3);
	view();
	return 0;
}
