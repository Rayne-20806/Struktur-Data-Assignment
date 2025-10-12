#include <iostream>
using namespace std;
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel; // var struct sementara
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "NamA pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.kodeMapel << endl;
}