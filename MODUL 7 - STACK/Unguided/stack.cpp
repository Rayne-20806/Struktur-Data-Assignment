#include "stack.h"
#include <iostream>
using namespace std;

// implementasi berbagai function or prosedur tadi
bool isEmpty(Stack S) {
    return S.top == -1;
};
bool isFull(Stack S) {
    return S.top == MAX_SLOTS -1;
};
infotype createItem(string nama, int id) {
    Item newItem;
    newItem.nama = nama;
    newItem.id = id;
    return newItem;
}

// implementasi 
void CreateStack(Stack &S) {
    S.top = -1; //terbentuk stack kosong dengan top = -1
}

void Push(Stack &S, infotype x) {
    //cek apakah sudah penuh atau belum 
    if (isFull(S)) {
        cout << "Tas penuh! tidak bisa menambah item" << endl;
    } else { // kondisi jika belum penuh
        S.top++;// naikan top 
        S.info[S.top] = x; // tambah item atau isi di posisi top baru
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Tas kosong, tidak ada yang bisa di ambil" << endl;
        return {"Error", -1};
    } else {
        infotype itemDiambil = S.info[S.top]; // ambil item di top atas
        S.top--; //kurangi top ke bawah
        return itemDiambil; // kembalikan item
    }
}

void printInfo(Stack S) {
    cout << "[TOP] -> ";
    if (isEmpty(S)) {
        cout << "Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) { // Mulai ambil dari top atas kemudian kurangi ke bawah hingga 0
            cout << "(" << S.info[i].id << ": " << S.info[i].nama << ") ->"; 
        }
        cout << "[BOTTOM]" << endl;
    }
}

void balikStack(Stack &S) {
    // butuh tas cadangan untuk membalik stack dari bawah ke top
    Stack tempStack;
    CreateStack(tempStack);

    // pindahkan item semua dari S ke tempstack, otomatis akan membalik urutan
    while (!isEmpty(S)) {
        Push(tempStack, pop(S));
    }
    S = tempStack;
}

// untuk soal no 2
void pushAscending(Stack &S, infotype x) {
    // buat tas sementara
    Stack Temp;
    CreateStack(Temp);

    // selama isi atau S tidak kosong dan TOP > ID item baru,, Logika pengurutan (Descending)
    while (!isEmpty(S) && S.info[S.top].id > x.id) {
        // Pindahkan item yg lebih besar ke stack sementara
        Push(Temp, pop(S));
    }
    
    // Masukkan item baru (x) di posisi yang tepat
    Push(S, x);
    
    // Kembalikan semua item dari stack sementara
    while (!isEmpty(Temp)) {
        Push(S, pop(Temp));
    }
}

// untuk soal 3
void getInputStream(Stack &S) {
    cout << "Masukkan ID Item (angka 0-9), tekan Enter jika selesai:" << endl;
    
    char c; // Penampung karakter
    
    // Loop ini akan terus jalan, mengambil 1 KARAKTER setiap kalinya  Sampai karakter yang diambil adalah '\n'
    while ( (c = cin.get()) != '\n' ) {
        
        // Cek apakah karakter itu adalah angka (bukan spasi/huruf)
        if (c >= '0' && c <= '9') {
            
            // 1. Ubah karakter '4' menjadi angka 4
            int id_num = c - '0'; 
            
            // 2. Buat nama item otomatis (biar kreatif)
            string item_name = "Rune Fragment " + to_string(id_num); 
            
            // 3. Push item ini ke stack
            Push(S, createItem(item_name, id_num));
            cout << "  -> Menambahkan (" << id_num << ": " << item_name << ") ke tas." << endl;
        }
        // Jika user ngetik spasi atau huruf, abaikan saja
    }
    cout << "[Input selesai!]" << endl;
}