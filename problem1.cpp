#include <iostream>

using namespace std;

int main() {
    int N, K;
    
    // Input jumlah astronot (N) dan langkah perputaran (K)
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan langkah eliminasi (K): ";
    cin >> K;
    
    // Inisialisasi array untuk menyimpan astronot (1 sampai N)
    int astronauts[1000]; // Membuat array cukup besar untuk menampung astronot
    for (int i = 0; i < N; i++) {
        astronauts[i] = i + 1;
    }
    
    int index = 0;
    int eliminated_count = 0;
    
    // Perulangan hingga tersisa tepat 1 astronot
    while (eliminated_count < N - 1) {
        int count = 0;
        
        // Cari astronot aktif ke-K
        while (count < K) {
            if (astronauts[index] != 0) {
                count++;
            }
            
            // Geser index hanya jika belum mencapai hitungan ke-K
            if (count < K) {
                index = (index + 1) % N; // Modulo N agar melingkar kembali ke depan
            }
        }
        
        // Eliminasi astronot dengan mengubah nilainya jadi 0
        astronauts[index] = 0;
        eliminated_count++;
        
        // Geser ke posisi berikutnya untuk siklus selanjutnya
        index = (index + 1) % N;
    }
    
    // Cari dan tampilkan astronot terakhir yang nilainya bukan 0
    for (int i = 0; i < N; i++) {
        if (astronauts[i] != 0) {
            cout << "Astronot Terakhir: " << astronauts[i] << endl;
            break;
        }
    }
    
    return 0;
}