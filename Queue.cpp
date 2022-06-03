#include <iostream>
#define MAX 10 //maksimum data queue(antrian)
using namespace std;

struct Queue {
	int head; 
	int tail; 
	int data[MAX];
}
Q;

//antrian penuh
bool isFull() {
	return Q.tail == MAX;
}

//antrian kosong
bool isEmpty() {
	return Q.tail == 0;
}

//Menampilkan Queue(antrian)
void printQueue() {
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		cout << "QUEUE : ";
		for (int i = Q.head; i < Q.tail; i++)
			cout << Q.data[i] << ((Q.tail-1 == i) ? "" : ",");
		cout << endl;
  }
}

//manambahkan data ke antrian
void enqueue() {
	if (isFull())
	{
		cout << "Antrian penuh!"<<endl;
	}
	else {
		int data;
		cout << "Masukkan Data : ";cin >> data;
		Q.data[Q.tail] = data;
		Q.tail++;
		cout << "Data ditambahkan\n";
		printQueue();
	}
}

// mengambil data dari antrian
void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian masih kosong"<<endl;
	}
	else{
		cout << "Mengambil data \"" << Q.data[Q.head] << "\"..." << endl;
		for (int i = Q.head; i < Q.tail; i++)
			Q.data[i] = Q.data[i + 1];
		Q.tail--;
		printQueue();
	}
}

int main() {
	int choose;
	do
	{
		cout << "-------QUEUE (ANTRIAN)----------\n"
			<< "---------------------------------\n"
			<< " 1. Menambahkan Data Ke Antrian \n"
			<< " 2. Mengambil Data Dari Antrian \n"
			<< " 3. EXIT \n\n"
			<< "----------------------------------\n"
			<< "Masukkan pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose !=3);
	return 0;
}
