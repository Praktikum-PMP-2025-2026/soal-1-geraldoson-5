/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 03 Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Geraldo Son Luther Silalahi (13224018)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program membaca data artefak yang terdiri atas nama, kategori, 
 * tahun penemuan, dan nilai penting artefak ke dalam dynamic array bertipe struct. Kemudian, seluruh data 
 * diurutkan secara alfabet naik, tahun secara naik, nilai secara turun, dan nama secara alfabet naik. 
 * Setelah proses pengurutan selesai, program menampilkan seluruh artefak sesuai urutan yang diminta soal. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[200]; // elemen nama artefak
    char kategori[200]; // elemen kategori artefk
    int tahun; // tahun penemuan artefak
    int nilai; // nilai artefak
} Artefak;

int urutanDepan(Artefak a, Artefak b) {
    if (strcmp(a.kategori, b.kategori) != 0) {
        return (strcmp(a.kategori, b.kategori) < 0);
    }
    if (a.tahun != b.tahun) {
        return (a.tahun < b.tahun);
    }
    if (a.nilai != b.nilai) {
        return (a.nilai > b.nilai);
    }
    return (strcmp(a.nama, b.nama) < 0);
}

int main() {
    int n; // jumlah artefak
    Artefak *data; // array dinamis artefak
    Artefak temp; // penukar data sementara
    int i;
    int j; 

    scanf("%d", &n);

    data = (Artefak *) malloc(n * sizeof(Artefak));
    if (data == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (!urutanDepan(data[j], data[j + 1])) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }
    free(data);
    return 0;
}
