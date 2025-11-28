# <h1 align="center">Laporan Praktikum Modul TREE (BAGIAN PERTAMA) (10)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### 1. Konsep Rekursif
Rekursif adalah suatu proses pengulangan sesuatu dengan cara kesamaan diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek besar. Berikut manfaat dengan menggunakan sub program: 
<ol>
  <li>
    meningkatkan readibility, yaitu mempermudah pembacaan program
  </li>
  <li>
      Meningkatkan modularity, memecah sesuatu yang besar menjadi modul-modul yang lebih kecil
  </li>
  <li>
    Meningkatkan reusability, yaitu sub program dapat dipakai berulang kali dengan hanya memanggil sub program tersebut tanpa menuliskan perintah-perintah yang semestinya diulang-ulang
  </li>
</ol>

<img width="688" height="498" alt="image" src="https://github.com/user-attachments/assets/a240c402-ad79-4b9c-9639-2fd3dad318a9"/>


### 2. Kriteria Rekursif
Dengan melihat sifa sub program rekursif diatas, maka sub program rekursif harus memiliki: Kondisi yang menyebabkan pemanggilan dirinya berhenti (special condition) dan Pemanggilan diri sub program (jika special condition tidak terpenuhi.

Secara umum bentuk dari sub program rekursif memiliki statemen kondisional:
<ol>
  <li>
    If kondisi khusus tidak dipenuhi
  </li>
  <li>
    then panggil diri sendiri dengan parameter yang sesuai
  </li>
  <li>
    else lakukan instruksi yang akan dieksekusi bila kondisi khusus dipenuhi
  </li>
</ol>


### 3. Kekurangan Rekursif
Konsep penggunaan yang terlihat mudah karena fungsi rekursif dapat menyederhanakan solusi dari
suatu permasalahan, sehingga sering kali menghasilkan bentuk algoritma dan program yang lebih
singkat dan lebih mudah dimengerti.
Kendati demikian, penggunaan rekursif memiliki beberapa kekurangan antara lain:
<ol>
  <li>
    Memerlukan memori yang lebih banyak untuk menyimpan activation record dan variabel lokal.
  </li>

  <li>
    Memerlukan waktu yang lebih banyak untuk menangani activation record.
  </li>
</ol>

Secara umum gunakan penyelesaian rekursif hanya jika: Penyelesaian sulit dilaksanakan secara iteratif, efisiennsi dengan cara rekursif sudah memadai, efisiensi bukan masalah dibandingkan dengan kejelasan logika program.

### 4. Tree dan Pengertian dari Tree
Pada modul sebelumnya kita sudah belajar dan mengenal jenis struktur data yang linear, seperti : list, stack, dan queue. Adapun jenis struktur data yang kita pelajari adalah Tree (Struktur data non linear.

Berikut ini anatomi dari suatu Tree:
<img width="803" height="694" alt="image" src="https://github.com/user-attachments/assets/1bbccf7e-f90a-4755-a9cb-83b70934f24e" />

### 5. Jenis Jenis Tree.
#### 1. Orderen Tree
Yaitu pohon yang urutan anak-anaknya penting.

<img width="424" height="310" alt="image" src="https://github.com/user-attachments/assets/85098a3b-6143-410f-b9cd-2263c15c2027" />

#### 2. Binary Tree
Setiap node di Binary Tree hanya dapat mempunyai maksimum 2 children tanpa pengecualian.
<img width="592" height="742" alt="image" src="https://github.com/user-attachments/assets/009e7b82-7fc4-426f-a3b4-89e6410741e3" />

### 6. Operasi-Operasi dalam Binary Search Tree
<ol>
  <li>
    Insert, jika node yang akan diinsert lebih kecil, maka diinser pada left subtree, jika lebih besar maka insert pada Right Subtree.
  </li>
  <li>
    Update, Jika setelah diupdate posisi/lokasi node yang bersangkutan tidak sesuai dengan ketentuan, maka
harus dilakukan dengan proses REGENERASI agar tetap memenuhi kriteria Binary Search Tree.
  </li>
  <li>
    Search, Proses pencarian elemen pada binary tree dapat menggunakan algoritma rekursif binary search.
  </li>
  <li>
    delete
  </li>
  <li>
    most-left, Most-left node adalah node yang berada paling kiri dalam tree. Dalam konteks binary search tree
(BST), most-left node adalah node dengan nilai terkecil, yang dapat ditemukan dengan mengikuti
anak kiri (left child) dari root hingga mencapai node yang tidak memiliki anak kiri lagi
  </li>
  <img width="281" height="299" alt="image" src="https://github.com/user-attachments/assets/1e75792f-2998-4c98-b2a8-c19fd6d33009" />

  <li>
    most-right, Most-right node adalah node yang berada paling kanan dalam tree. Dalam konteks binary search
tree (BST), most-right node adalah node dengan nilai terbesar, yang dapat ditemukan dengan
mengikuti anak kanan (right child) dari root hingga mencapai node yang tidak memiliki anak kanan
lagi.
  </li>
  <img width="220" height="273" alt="image" src="https://github.com/user-attachments/assets/abd5e43b-22d5-4d83-a72e-250c35ed877e" />

</ol>





## Guided 


## 1. Binary Search Tree
## 1.1 bst.h
```h

```

## 1.2 bst.cpp
```cpp

```


## 1.3 main.cpp
```cpp

```

[PENJELASAN KODE]


## Unguided 

### 1. Soal Pertama



### 1.1 .h
```h

```

### 1.2 .cpp
```cpp

```

### 1.3 main.cpp
```cpp


```






#### Output:




#### Full code screenshot:

#### Code .h


#### code .cpp


#### code main.cpp















## Kesimpulan




## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.












