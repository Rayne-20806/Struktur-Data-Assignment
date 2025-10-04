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


### 1. Matriks Operator
<img width="756" height="68" alt="image" src="https://github.com/user-attachments/assets/9bed2960-e304-4104-9665-a30602e7ab2b" />

```c++
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
```

#### Output:
<img width="966" height="416" alt="image" src="https://github.com/user-attachments/assets/5fb9ad5b-7d97-4f06-a82e-8fa770e5b71b" />
Program ini dirancang sebagai operator aritmatika pada sebuah matriks dimana ada operasi seperti penjumlahan, pengurangan, dan perkalian <code>+, -, *</code>. Program ini menggunakan prosedur <code>tampilkanMatriks()</code> untuk menampilkan hasil matriks yang akan dipanggil di program main dan memiliki 2 tipe data matriks A dan B sebagai. Untuk Perjumlahan dan pengurangan sama-sama menggunakan for bersarang atau nested-loop. Namun ada perbedaan pada perkalian matriks karena pada dasarnya perkalian matriks baris pertama dikalikan dengan kolom pertama kemudian dijumlah dan itu merupakan hasil matriks baris satu kolom satu dan seterusnya.


#### Full code screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b0998b9b-b0fe-413a-83a9-05b0ad88ba26" />

### 2. Pointer dan Reference
<img width="775" height="67" alt="image" src="https://github.com/user-attachments/assets/0795d562-e5c3-4250-9ce5-70a8349f70d5" />

```c++
#include <iostream>
using namespace std;

// prosedur untuk menukar nilai menggunakan pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z ;
    *z = temp;
}
// prosedur untuk menukar nilai menggunakan reference
void tukarReference(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 1, b = 2, c = 3;
    cout << "Sebelum menukar (Pointer): a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "Setelah menukar (Pointer): a = " << a << ", b = " << b << ", c = " << c << endl;

    int a2 = 1, b2 = 2, c2 = 3;
    cout << "Sebelum menukar (Reference): a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;
    tukarReference(a2, b2, c2);
    cout << "Setelah menukar (Reference): a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    return 0;
}
```

### Output:
<img width="869" height="213" alt="image" src="https://github.com/user-attachments/assets/3f9683f5-c5cf-4101-af5d-e7ca88ef43f4" />
Program ini dibuat untuk membandingkan dua metode dalam menukar 3 variabel, yaitu dengan menggunakan pointer dan reference.
<ol>
     <li>
          Pointer, Fungsi <code>tukarPointer</code> akan menerima argumen berupa sebuah alamat memori dari variabel <code>(int *)</code>. Di dalam fungsi, nilai asli di akses dan dimodifikasi dengan menggunakan operator (*). Kemudian cara memanggil yaitu harus menggunakan operator &, contoh di atas <code>tukarPointer(&a, &b, &c)</code>
     </li>
     <li>
          Reference, sama seperti diatas yaitu memungkinkan mengubah nilai variabel asli secara langsung namun dengan sintaks yang lebih sederhana daripada pointer.
     </li>
     
</ol>
variabel temp pada setiap procedur pointer dan reference digunakan untuk menyimpan nilai awal agar tidak akan hilang saat ditimpa.

### Full Code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6b805e00-b8c0-42e4-b69e-719233a78e84" />

### 3. Program Array Menu
<img width="773" height="376" alt="image" src="https://github.com/user-attachments/assets/abf3b421-488b-43f8-a25f-b132e59d3c52" />

```c++
#include <iostream>
using namespace std;

// function cara maks
int cariMaksimum(int arr[], int ukuran) {
    int maks = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

// function cari min
int cariMinimum(int arr[], int ukuran) {
    int min = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    };
    return min;
}

// tampil isi array
void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// hitung rata2
void hitungRataRata(int arr[], int ukuran) {
    float total = 0;
    for (int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    cout << "Nilai rata-rata: " << total / ukuran << endl;
}

int main() {
    int arr[] = {11, 8, 7, 12, 26, 3, 53, 33, 55};
    // hitung ukuran array
    int ukuran = sizeof(arr) / sizeof(arr[0]);

    int pilihanMenu;
    do {
        cout << "\n---Menu Program Array ---" << endl;
        cout << "\n1. Tampilkan isi array" << endl;
        cout << "\n2. Cari nilai maksimum" << endl;
        cout << "\n3. Cari nilai minimum" << endl;
        cout << "\n4. Hitung nilai rata-rata" << endl;
        cout << "\n5. Keluar(tambah)" << endl;
        cout << "\nMasukkan pilihan Anda (1-5): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tampilkanArray(arr, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arr, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arr, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arr, ukuran);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
        // pause sebelum lanjut dan tekan enter saja
        if (pilihanMenu != 5) {
            cout << "Teken untuk melanjutkan..." << endl;
            cin.ignore();
            cin.get();
        } 
    }
    
    while (pilihanMenu != 5);

    return 0;
}
```

### Output:
<img width="902" height="299" alt="image" src="https://github.com/user-attachments/assets/eafc0e81-e5a0-4e47-bfca-5dec87db2fb2" />
<img width="308" height="75" alt="image" src="https://github.com/user-attachments/assets/e161c44b-e77b-4018-a1a2-3b650e1fb98d" />
<img width="312" height="76" alt="image" src="https://github.com/user-attachments/assets/fff0a602-5992-4bf5-a108-009a0a6ddebb" />
<img width="313" height="72" alt="image" src="https://github.com/user-attachments/assets/fa9fdb7c-8e37-40e9-964d-bb2b3f63e5fe" />
<img width="297" height="81" alt="image" src="https://github.com/user-attachments/assets/883e7b92-d9d5-49a1-a874-a9ca0df97fea" />
<p></p>
<img width="642" height="272" alt="image" src="https://github.com/user-attachments/assets/b6ed3920-3eaf-4586-b513-fdfdb55d8cb2" />


Program diatas dibuat seperti aplikasi sederhana berbasis menu yang memungkinkan untuk menganalisis array yang sudah ditentukan isinya. Program ini memiliki berbagai function dan prosedur yang dipuisah agar menjaga kode terstruktur dan tidak terlalu banyak di kode main(utama), seperti function <code>cariMaksimum() dan cariMinimum</code> yang akan digunakan untuk menghitung nilai maks dan min dari penjumlahan array. Kemudian itu ada procedur <code>tampilkanArray() dan hitungRataRata()</code> yang akan di panggil di fungsi utama untuk menampilkan hasil dari tampilkan array dan juga hasil rata-rata array. Program ini menggunakan swich-case


### Full code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/54edc589-5cc2-4cef-928c-b1f0f4a956a8" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/64f3197f-9267-46ea-a3d2-ae93a3cf2c3d" />





## Kesimpulan
Berdasarkan praktikum modul 2 ini, dapat saya simpulkan bahwa praktikum kali ini mampu memahami konsep konsep lanjutan dari pemrograman c++ untuk struktur data. Pada modul ini mampu memahami bagaimana macam-macam array seperti array 1 dimensi yang merupakan kumpulan data yang hanya memiliki 1 tipe data, array 2 dimensi terdiri dari baris dan kolom(bentuknya seperti matriks), kemudian array 3 dimensi merupakan bentuk lanjutan dari array 2 dimensi namun lebih kompleks. Selanjutnya di praktikum kali ini diajarkan bagaimana cara membedakan function dan procedur yang dimana function akan mengembalikan nilai return, sementara itu procedur tidak mengembalikan nilai return dan cara mendeklarasikannya menggunakan void. Selain itu juga di praktikum kali ini kita belajar mengenai pointer, value, alamat dari suatu variabel dan juga belajar berbagai cara melewatkan parameter dengan menggunakan call by value, call by pointer, call by reference

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.





