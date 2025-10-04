#include <iostream>
using namespace std;

// prosedur untuk menampilkan matriks
void tampilkanHasil(int matriks[3][3]) {
    for (int i= 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //buat matriks 3x3
    int matriksA[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };
    int matriksB[3][3] = {
        {3, 3, 3},
        {2, 2, 2},
        {1, 1, 1}
    };
    int hasilMatriks[3][3];
    // Matriks awal
    cout << "Matriks A: " << endl;
    tampilkanHasil(matriksA);
    cout << "Matriks B: " << endl;
    tampilkanHasil(matriksB);
    cout << endl;


    // operasi jumlah
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            hasilMatriks[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    };
    cout << "Hasil penjumlahan matrik A dan B: " << endl;
    tampilkanHasil(hasilMatriks);

    // operasi kurang
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilMatriks[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    };
     cout << "Hasil pengurangan matrik A dan B: " << endl;
    tampilkanHasil(hasilMatriks);


    // operasi kali
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilMatriks[i][j] = 0; // inisialisasi elemen hasilMatriks
            for (int k = 0; k < 3; k++) {
                hasilMatriks[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    };
    cout << "Hasil perkalian matrik A dan B: " << endl;
    tampilkanHasil(hasilMatriks);

    return 0;
}