// testing
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai = " << rata2(mhs) << endl;
    return 0;
}
