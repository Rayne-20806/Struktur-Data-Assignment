#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) { //baris
        for (int j = 0; j < 3; j++) { // kolom 
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemenArray(int arrSatu[3][3], int arrDua[3][3], int baris, int kolom) {
    int temp = arrSatu[baris][kolom];
    arrSatu[baris][kolom] = arrDua[baris][kolom];
    arrDua[baris][kolom] = temp;
}

void tukarViaPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arraySatu2D[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrayDua2D[3][3] = {
        {10,15,20},
        {25,30,35},
        {40,45,50}
    };

    cout << "--Isi Array Awal Sebelum ubah--" << endl;
    cout << "Isi Array Pertama: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nIsi Array Kedua: " << endl;
    tampilkanArray(arrayDua2D);

    //Tukar elemen dengan indeks arr
    tukarElemenArray(arraySatu2D, arrayDua2D, 1, 1); // note ini bukan baris 1 kolom satu tapi baris 2 kolom 2, array mulai dari 0
    cout << "\n--Setelah menukar elemen di [1][1]--" <<endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "Array Dua" << endl;
    tampilkanArray(arrayDua2D);

    // bagian pointeer 
    int *ptrA;
    int *ptrB;

    ptrA = &arraySatu2D[0][0]; // simpan alamat 1 (baris 1 kolom 1)
    ptrB = &arrayDua2D[2][2]; // simpan alamat 50 (baris 3 kolom 3)

    cout << "\n--Menukar nilai via pointer--" << endl;
    cout << "Nilai yang ditunjuk pointerA(sebelum): " << *ptrA << endl;
    cout << "Nilai yang ditunjuk pointerB(sebelum): " << *ptrB << endl;

     tukarViaPointer(ptrA, ptrB);

    cout << "\nNilai yang ditunjuk pointerA (setelah): " << *ptrA << endl; // Akan menampilkan 50
    cout << "Nilai yang ditunjuk pointerB (setelah): " << *ptrB << endl; // Akan menampilkan 1

    cout << "\nIsi Array Final Setelah Semua Penukaran " << endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nArray Dua: " << endl;
    tampilkanArray(arrayDua2D);

}
