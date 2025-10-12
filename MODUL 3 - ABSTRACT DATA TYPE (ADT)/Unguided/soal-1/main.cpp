#include <iostream>
#include <limits> // digunakan untuk numeric_limits
using namespace std;


struct mahasiswaArray {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float rata2NilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
};

const int MAX_MHS = 10;

int main() {
    mahasiswaArray mhs[MAX_MHS];
    int jumlahMhs = 0;
    
    cout << "||Program Menghitung Rata-rata Nilai Akhir Mahasiswa||" << endl;
    cout << "Masukkan jumlah Mahasiswa (maksimal 10); ";
    cin >> jumlahMhs;
    
    if (jumlahMhs > MAX_MHS) {
        cout << "Jumlah Mahasiswa melebihi batas maksimal: " << MAX_MHS << endl;
        return 1;
    }

    cout << endl;
    cout <<  "-- Input Data Mahasiswa -- ";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: "; 
        // membersihkan newline character dari input sebelumnya
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, mhs[i].nama); // untuk menangkap spasi pada nama
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = rata2NilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << endl;
    cout << "-- Data Mahasiswa --" << endl;
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "==========================" << endl;
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    cout << "==========================" << endl;
    return 0;
}

