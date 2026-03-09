// STACK WITH ARRAY

#include <stdio.h>

//nilai maksimum panjang array
#define MAX 100

//inisiasi array stack
int stack_arr[MAX];
//sebagai indeks yang menandai puncak dari stack
//jika indeksnya -1 maka stack masih kosong
int top = -1; 


//Fungsi untuk mengecek apakah array kosong
int isEmpty(){
	if(top == -1) return 1; //return 1 (true)
	else return 0; //return 0 (false)
}

//Fungsi untuk mengecek apakah array penuh
int isFull(){
	if(top == MAX-1) return 1; //return 1 (true)
	else return 0; //return 0 (false)
}

//Fungsi untuk menampilkan keseluruhan array
void display(){
	//jika isEmpty() True maka stack kosong dan tidak ada yang bisa ditampilkan (return)
	if(isEmpty()){ 
		printf("Stack kosong\n");
		return;
	}
	
	//Looping mulai dari top hingga 0 untuk menampilkan semua data yang ada di stack
	for(int i = top; i >= 0;i--){
		printf("%d -> ", stack_arr[i]);
	}
	printf("NULL\n");
}

int size(){
	//jika isEmpty() True maka stack kosong dan tidak ada yang bisa ditampilkan (return)
	if(isEmpty()){
		printf("Stack kosong\n");
		return 0;
	}
	
	return top+1; //karena indeks dimulai dari 0 --> maka ukuran adalah Top + 1
}

void push(int val){
	//jika isFull() True maka stack tidak memiliki tempat yang bisa diisi lagi (return)
	if(isFull()){
		printf("Stack overflow\n");
		return;
	}
	
	//Pindah ke indeks selanjutnya
	top++;
	//masukkan data di indeks paling atas
	stack_arr[top] = val;
}

//Fungsi untuk melihat nilai yang berada di stack paling atas
int peek(){
	//jika isEmpty() True maka stack kosong dan tidak ada yang bisa ditampilkan (return)
	if(isEmpty()){
		printf("Stack kosong\n");
		return 0;
	}
	
	//print nilai yang berada di puncak stack
	return top;
}

int pop(){
	//jika isEmpty() True maka stack kosong dan tidak ada yang bisa ditampilkan (return)
	if(isEmpty()){
		printf("Stack kosong\n");
		return 0;
	}
	
	//nilai yang dihapus disimpan di deleted value
	int deletedValue = stack_arr[top];
	//posisi top - 1 sehingga indeks mundur dan indeks top sebelumnya dianggap kosong
	top--;
	
	//return deletedValue atau nilai yang baru saja dihapus
	return deletedValue;
}


int main(){
	push(7);
	push(8);
	push(9);
	push(10);
	
	display();
	
	printf("Topmost data: %d\n", stack_arr[peek()]);
	printf("Stack size: %d\n", size());
	printf("Deleted Value: %d\n", pop());
	
	display();
	
	return 0;
}
