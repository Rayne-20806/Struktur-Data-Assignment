# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
Modul kedua yang berjudul "Pengenalan Bahasa C++(Bagian Kedua) merupakan lanjutan dari modul 1. Pembahasan modul ini meliputi beberapa poin seperti Array dimensi, Memahami penggunaan pointer dan alamat memori, function serta procedur, dan call by reference.
<ol>
     <li><b>Array</b>, array merupakan struktur data di c++ yang digunakan untuk menyimpan kumpulan data atau nilai(dengan tipe data yang sama) dalam satu variabel. Array terbagi menjadi 3. Array satu domensi, array paling dasar dan cara mendeklarasikan cukup dengan <code>tipe_data nama_array[ukuran]</code>. Array 2 dimensi seperti tabel matriks dimana ukuran arraynya adalah baris dan kolom, contoh deklarasi <code>int data_nilai[4][3]</code>. Kemudian array 3 dimensi merupakan bentuk yang sangat kompleks diantara kedua array tersebut </li>
     <li><b>Pointer</b>, merupakan variabel khusus yang digunakan untuk mengambil atau menyimpan alamat memori dari variabel lainnya. Cara mendeklarasikannya dengan <code>tipe_data *ptr</code>(digunakan mendeklarasikan pointer dan mengakses nilai yang berada di alamat memori yang ditunjung) dan <code>&</code>(digunakan untuk mendapatkan alamat memori dari sebuah varabel </li>
     <li><b>Function dan prosedur</b>, sebuah kode yang digunakan untuk membuat program menjadi lebih terstruktur karena program semuanya tidak terletak pada func main saja, namun bisa bercabang. Perbedaan antara function dan procedur adalah function akan mengembalikan sebuah nilai(return value), sementara itu procedur fungsi yang tidak mengembalikan nilai. Cara mendeklarasikan function <code>tipe_data nama_variabel(parameter)</code> dan cara mendeklarasikan procedur gunakan <code>void nama_variabel(parameter)</code></li>
     <li>Cara melewatkan parameter ada tiga cara yaitu <b>Call by value, call by pointer, dan call by reference</b></li>
</ol>

## Guided 

### 1. ArrayC++

```C++
#include <iostream>
using namespace std;

int main() {
     // 1. array 1 dimensi 
     int arr1D[5] = {10, 20, 30, 40, 50};
     cout << "Array 1 Dimensi: " << endl;
     for (int i = 0; i < 5; i++) {
          cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
     }
     cout << endl;

     // 2. array 2 dimensi
     int arr2D[2][3] = {
          {1, 2, 3},
          {4, 5, 6}
     };
     cout << "Array 2 Dimensi: " << endl;
     for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
               cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << endl;
          }
     }
     cout << endl;

     // 3,  Array multidemensi (3d)
     int arr3D[2][2][3] = {
          {{1, 2, 3}, {4,5,6}},
          {{7,8,9}, {10,11,12}}
     };
     cout << "Array 3 Dimensi: " << endl;
     for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++){
               for (int k = 0; k < 3; k++) {
                    cout << "arr3D[" << i << "][" << j << "][" << k << "] = " << arr3D[i][j][k] << endl;
               }
          }
     }

     return 0;
}
}
```
Program ini diimplementasikan dengan menggunakan array yang dimana ada 3 jenis array:
<ol>
     <li>Array 1 dimensi, array yang dideklarasikan sebagai <code>int arr1D[5]</code> yang dimana array akan menyimpan 5 buah value dengan tipe data int. Program ini juga menggunakan <code>for</code> untuk menampilkan semua array sebagai outputnya.</li>
     <li>Array 2 dimensi, berbeda dengan 1 dimensi, array ini dideklarasika sebagai <code>int arr2D[2][3] </code> yang diartikan 2 baris dan 3 kolom. Masih sama menggunakan <code>for</code> untuk menampilkan nilai yang ada pada array tersebut.</li>
     <li>Array 3 dimensi, berbeda dengan 1 dan 2 dimensi, array  ini merupakan perkembangan dari array 2 dimensi. Dekarasi sebagai <code>int arr3D[2][2][3]</code>. Program juga masih menggunakan <code>for</code> sebagai perulangan untuk menampilkan array tersebut.</li>
</ol>


## 2. Procedur
```c++
#include <iostream>
using namespace std;

void tulis (int x) {
     for (int i = 0; i < x; i++) {
          cout << "Baris ke -: " << i+1 << endl;
     }
}

int main() {
     // 2, prosedur adalah void function, prosedur tidak mengembalikan nilai atau return value
     int jumlah;
     cout << "Masukkan jumlah baris: ";
     cin >> jumlah;
     tulis(jumlah);

     return 0;
}
```
Program ini dibuat untuk menjelaskan bagaimana konsep dari procedur itu sendiri. Prosedur merupakan sebuah fungsi/function namun ia tidak mengembalikan nilai return, biasanya prosedur dideklarasikan dengan  <code>void_namaVariabel(tipedata_namaVariabel)</code>.

Program ini memiliki sebuah prosedur bernama <code>tulis(int x)</code> yang bertugas mencetak baris sesuai input sebanyak x kali dari user. Pada program <code>int main()</code> berfungsi sebagai program utama yang akan menyuruh user melakukan input pada variabel jumlah yang kemudian akan memanggil prosedur <code>tulis(jumlah)</code>.

## 3. Pointer
```c++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
}

int main() {
     int a = 20, b = 30;
     int *ptr;
     ptr = &a;

     cout << "Value of a(nilai dari a): " << a << endl;
     cout << "Address of a(alamat dari a): " << &a << endl;
     cout << "Value stored in ptr (address of a): " << ptr << endl;
     cout << "Valuee pointed to by ptr (value of a): " << *ptr << endl;
     cout << endl;

     tukar(&a, &b);
     cout << "After swapping, value of a= " << a << " and value of b= " << b << endl;
     
     return 0;
}
```
Program ini dibuat untuk mengerti konsep dasar pointer dalam C++. Pointer sendiri merupaman variabel khusus yang berfungsi untuk menyimpan alamat/address memori dari variabel lain. Program ini menginisialisasi sebuah variabel pointer yaitu <code>*ptr</code> untuk menunjuk ke alamt memori variabel a dengan menggunakan <code>ptr = &a</code>. Kemudian Program akan menampilkan output seperti <code>a(nilai a), &a(alamat a terletak), ptr(akan menyimpan alamat a), *ptr(mengambil value a)</code>. Bagian akhir dari terdapat fungsi <code>tukar</code> yNg digunakan untuk menukar nilai. Saat funsi dipanggil maka akan langsung memodifikasi variabel asli a dan b tanpa perlu menggunakan syntax pointer.

## 4. Reference
``` c++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
     int temp;
     temp = x;
     x = y;
     y = temp;
}

int main() {
     int a = 20, b = 30;
     int& ref = a; // reference variable

     cout << "Nilai dari a: " << a << endl;
     cout << "Alamat dari a (&a): " << &a << endl;
     cout << "Nilai dari ref (reference variable): " << ref << endl;
     cout << "Alamat dari ref (&ref): " << &ref << endl;    

     // mengubah nila a melalui reference variable
     ref = 50;
     cout << "\nsetelah ref = 50;" << endl;
     cout << "Nilai dari a: " << a << endl;
     cout << "Nilai dari ref: " << ref << endl;

     tukar (a,b);
     cout << "Setelah menukar, nilai a = " << a << " dan nilai b= " << b << endl;

     return 0;
}
```
Program diatas menjelaskan konsep sebuah reference di C++, yaitu sebuah nama alias untuk variabel yang sudah ada. Reference berbeda dari pointer karena lebih sederhana dan aman digunakan. Cara meginisialisasikan sebuah reference adalah  ada tanda <code>&</code>


## Unguided 


### 1. ..............
<img width="422" height="189" alt="image" src="https://github.com/user-attachments/assets/087a2123-40e2-4ac0-b34d-4fed4b488895" />



```c++

```
#### Output:



#### Full code screenshot:






## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].
Setelah praktikum pertama dilaksanakan, saya dapat menyimpulkan bahwa praktikum ini telah membuat saya memahami dan mampu mengimplementasikan konsep-konsep basic dasar di C++ seperti deklarasi variabel, tipe data, konstanta, for loop, do-while, dan juga struktur. Selain itu juga bagaimana cara mengimport library di c++, cara running code, belajar syntax c++, menurut saya mengganti bahasa pemrograman tidak masalah karena pada dasarnya yang terpenting adalah memahami algoritma pemrograman dan juga cara kerjanya serta yang membedakan hanya syntax code nya saja, selebihnya algoritmanya menurut saya sama dan tidak ada bedanya

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.


