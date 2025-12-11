<h1 align="center">Laporan Praktikum Modul GRAPH (14)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### Pengertian Graph
Graph merupakan hompunan yang tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda dan Common Lab merupakan node atau vertec. Jalan yang menghubungkan kedua node tersebut disebut sebagai edge, berikut contoh gambarnya agar jelas.

<img width="365" height="111" alt="image" src="https://github.com/user-attachments/assets/84b0cf19-a015-4d6a-b78f-e8175f05526e" />

### Jenis-Jenis Graph
Graph memiliki berbagai jenis seperti berikut ini:
### 1.  Graph Berarah (Directed Graph).
Merupakan graph dimana tiap node memiliki edge atau garis penghubung yang ada arahnya, dimana setiap node akan mengarah ke node yang dihubungkan.

<img width="429" height="140" alt="image" src="https://github.com/user-attachments/assets/f52be011-43a8-4cf7-aa3e-2d5b3c4c53d8" />

#### A. Representasi Graph
Pada dasarnya representasi dari graph berarah sama dengan graph tak berarah. Perbedaannya apabila graph tak-berarah terdapat node A dan node B yang terhubung, secara otomatis terbentuk panah bolak balik dari A ke B dan B ke A. Pada graph berarah node A terhubung dengan node B, belum tentu node B terhubung dengan node A. Pada graph berarah kita bisa merepresentasikan dalam multi linked list sebagai contoh berikut ini,

<img width="646" height="293" alt="image" src="https://github.com/user-attachments/assets/6086d651-6932-4055-a90f-36b88828e4c4" />

<img width="646" height="243" alt="image" src="https://github.com/user-attachments/assets/e44951c1-8582-4a52-a734-8e8ca5aaa04a" />

#### B. Topological Sort
Diberikan urutan partial dari elemen suatu himpunan, dikehendaki agar elemen yang terurut parsial tersebut mempunyai keterurutan linear. Contoh dari keturunan parsial banyak dijumpai dalam kehidupan sehari-hari, misalnya: 
<ol>
  <li>
    Dalam suatu kurikulum, suatu mata pelajaran mempunyai prerequisite mata pelajaran lain.
Urutan linear adalah urutan untuk seluruh mata pelajaran dalam kurikulum
  </li>
  <li>
     Dalam suatu proyek, suatu pekerjaan harus dikerjakan lebih dulu dari pekerjaan lain (misalnya
membuat fondasi harus sebelum dinding, membuat dinding harus sebelum pintu. Namun
pintu dapat dikerjakan bersamaan dengan jendela, dsb.
  </li>
  <li>
     Dalam sebuah program Pascal, pemanggilan prosedur harus sedemikian rupa, sehingga
peletakan prosedur pada teks program harus seuai dengan urutan (partial) pemanggilan.
  </li>
</ol>

<img width="588" height="424" alt="image" src="https://github.com/user-attachments/assets/f3f07b04-7db6-46f5-9c7a-6b14dd09ebf6" />

### Graph Tidak Berarah (Undirected Graph)
Merupakan graph yang dimana setiap node memiliki edge yang dihubungkan ke node lain tanpa adanya arah atau tanda panah, berikut contohnya.

<img width="353" height="95" alt="image" src="https://github.com/user-attachments/assets/2c55564d-6b98-4016-ba2f-8181cb299c30" />

Selain arah, beban atau nilai sering ditambahkan pada edge . Misalnya nilai yang merepresentasikan
panjang, atau biaya transportasi, dan lain-lain. Hal mendasar lain yang perlu diketahui adalah, suatu
node A dikatakan bertetangga dengan node B jika antara node A dan node B dihubungkan langsung
dengan sebuah edge.

Dari gambar contoh graph pada halaman sebelumnya dapat disimpulkan bahwa: A bertetangga
dengan B, B bertetangga dengan C, A tidak bertetangga dengan C, B tidak bertetangga dengan D.
Masalah ketetanggaan suatu node dengan node yang lain harus benar-benar
diperhatikan dalam implementasi pada program. Ketetanggaan dapat diartikan sebagai
keterhubungan antar node yang nantinya informasi ini dibutuhkan untuk melakukan beberapa proses
STRUKTUR DATA 107
seperti : mencari lintasan terpendek dari suatu node ke node yang lain, pengubahan graph menjadi
tree (untuk perancangan jaringan) dan lain-lain.

#### Representasi Graph.
Dari definisi graph dapat disimpulkan bahwa graph dapat direpresentasikan dengan matrik ketetanggaan (Adjacency Matrices), yaitu matrik yang menyatakan keterhubungan antar node dalam graph. Implementasi matrik ketetanggaan dalam bahasa pemrograman dapat berupa array 2 dimensi dan multi linked list.

<img width="629" height="179" alt="image" src="https://github.com/user-attachments/assets/03641b3c-38d7-47c5-80f3-dc4a88da29d7" />

<img width="629" height="327" alt="image" src="https://github.com/user-attachments/assets/c6544455-6203-4543-84ec-869de2c711ba" />

#### Metode Penelusuran Graph
Yang pertama ada Breadth First Search (BFS), cara kerja algoritma ini adalah dengan mengunjungi root (depth 0) kemudian ke depth 1, 2, dan seterusnya. Kunjungan pada masing-masing level dimulai dari kiri ke kanan. Selanjutnya ada Depth First Search (DFS), cara kerja algoritma ini adalah dengan mengunjungi root, kemudian rekursid ke subtree node tersebut.


  



## Guided 


## 1. GRAPH

## 1.1 graph.h
```h

```

## 1.2 graph.cpp
```cpp

```


## 1.3 main.cpp
```cpp

```


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





### 2. Soal dua



### 2.1 .h
```h

```

### 2.2 .cpp
```cpp

```

### 2.3 main.cpp
```cpp

```


#### Output:




#### Full code screenshot:

#### Code .h



#### code .cpp



#### code main.cpp




### 3. Soal ketiga




### 3.1 .h
```h

```

### 3.2 .cpp
```cpp

```

### 3.3 main.cpp
```cpp

```


#### Output:

[PENJELASAN]


#### Full code screenshot:

#### Code .h



#### code .cpp



#### code main.cpp




## Kesimpulan




## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.













