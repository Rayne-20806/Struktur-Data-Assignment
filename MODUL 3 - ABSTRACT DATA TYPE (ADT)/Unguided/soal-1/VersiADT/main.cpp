
#include <iostream>
#include "mahasiswa.h" // Sertakan ADT sebelumnya
using namespace std;

int main() {
    Mahasiswa mhs[MAX_MHS]; 
    int jumlahMhs = 0;           

  
    inputData(mhs, jumlahMhs);
    tampilkanData(mhs, jumlahMhs);

    return 0;
}
