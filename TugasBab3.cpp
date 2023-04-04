#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void note(string note="Note : "){
    cout<<note;
}

const int MAX_MAHASISWA = 20;

struct Nilai {
    double abs, tugas, uts, uas, nilaiAkhir;
    char nilaiHuruf;
};

struct Mahasiswa {
    string npm, nama;
    Nilai nilai;
};

int cariMahasiswa(const Mahasiswa data[], int n, const string& npm) {
    for (int i = 0; i < n; i++) {
        if (data[i].npm == npm) {
            return i;
        }
    }
    return -1;
}

void inputDataMahasiswa(Mahasiswa data[], int& n) {
    if (n >= MAX_MAHASISWA) {
        cout << "Data mahasiswa sudah penuh." << endl;
        return;
    }
    
    Mahasiswa mhs;
    cout << "Masukkan data mahasiswa ke-" << n+1 << endl;
    cout << "NPM      : "; cin >> mhs.npm;
    cout << "Nama     : "; cin.ignore(); getline(cin, mhs.nama);
    cout << "Nilai Absen : "; cin >> mhs.nilai.abs;
    cout << "Nilai Tugas : "; cin >> mhs.nilai.tugas;
    cout << "Nilai UTS   : "; cin >> mhs.nilai.uts;
    cout << "Nilai UAS   : "; cin >> mhs.nilai.uas;
    mhs.nilai.nilaiAkhir = 0.1*mhs.nilai.abs + 0.2*mhs.nilai.tugas +
                           0.3*mhs.nilai.uts + 0.4*mhs.nilai.uas;
    if (mhs.nilai.nilaiAkhir > 80) {
        mhs.nilai.nilaiHuruf = 'A';
    } else if (mhs.nilai.nilaiAkhir > 70) {
        mhs.nilai.nilaiHuruf = 'B';
    } else if (mhs.nilai.nilaiAkhir > 60) {
        mhs.nilai.nilaiHuruf = 'C';
    } else {
        mhs.nilai.nilaiHuruf = 'D';
    }
    data[n] = mhs;
    n++;
}

void tampilDataMahasiswa(const Mahasiswa data[], int n) {
    if (n == 0) {
        cout << "Data mahasiswa kosong." << endl;
        return;
}
    
    cout << "Data Mahasiswa" << endl;
    cout << "=========================================================================" << endl;
    cout << "No  NPM                Nama      Absen  Tugas    UTS  UAS  Akhir  Huruf" << endl;
    cout << "=========================================================================" << endl;
    for (int i = 0; i < n; i++) {
        const Mahasiswa& mhs = data[i];
        cout << setw(2) << i+1 << "  ";
        cout << setw(2) << mhs.npm << "  ";
        cout << setw(10) << mhs.nama << "  ";
        cout << setw(7) << setprecision(2) << fixed << mhs.nilai.abs << "  ";
        cout << setw(5) << setprecision(2) << fixed << mhs.nilai.tugas << "  ";
        cout << setw(5) << setprecision(2) << fixed << mhs.nilai.uts << " ";
        cout << setw(3) << setprecision(2) << fixed << mhs.nilai.uas << " ";
        cout << setw(5) << setprecision(2) << fixed << mhs.nilai.nilaiAkhir << " ";
        cout << setw(2) << mhs.nilai.nilaiHuruf << endl;
}
cout << "======================================================================" << "\n\n\n";
}

void editDataMahasiswa(Mahasiswa data[], int n) {
if (n == 0) {
cout << "Data mahasiswa kosong." << endl;
return;
}
string npm;
cout << "Masukkan NPM mahasiswa yang ingin diubah datanya: ";
cin >> npm;

int idx = cariMahasiswa(data, n, npm);
if (idx == -1) {
    cout << "Data mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
    return;
}

Mahasiswa mhs = data[idx];
cout << "Data Mahasiswa dengan NPM " << npm << endl;
cout << "Nama        : " << mhs.nama << endl;
cout << "Nilai Absen : " << mhs.nilai.abs << endl;
cout << "Nilai Tugas : " << mhs.nilai.tugas << endl;
cout << "Nilai UTS   : " << mhs.nilai.uts << endl;
cout << "Nilai UAS   : " << mhs.nilai.uas << endl;
cout << endl;
cout << "Masukkan data baru" << endl;
cout << "Nama        : "; cin.ignore(); getline(cin, mhs.nama);
cout << "Nilai Absen : "; cin >> mhs.nilai.abs;
cout << "Nilai Tugas : "; cin >> mhs.nilai.tugas;
cout << "Nilai UTS   : "; cin >> mhs.nilai.uts;
cout << "Nilai UAS   : "; cin >> mhs.nilai.uas;
mhs.nilai.nilaiAkhir = 0.1*mhs.nilai.abs + 0.2*mhs.nilai.tugas +
                       0.3*mhs.nilai.uts + 0.4*mhs.nilai.uas;
if (mhs.nilai.nilaiAkhir > 80) {
    mhs.nilai.nilaiHuruf = 'A';
} else if (mhs.nilai.nilaiAkhir > 70) {
    mhs.nilai.nilaiHuruf = 'B';
} else if (mhs.nilai.nilaiAkhir > 60) {
    mhs.nilai.nilaiHuruf = 'C';
} else {
    mhs.nilai.nilaiHuruf = 'D';
}

data[idx] = mhs;
cout << "Data mahasiswa dengan NPM " << npm << " berhasil diubah." << endl;
}

void hapusDataMahasiswa(Mahasiswa data[], int& n) {
if (n == 0) {
cout << "Data mahasiswa kosong." << endl;
return;
}

string npm;
cout << "Masukkan NPM mahasiswa yang ingin dihapus datanya: ";
cin >> npm;

int idx = cariMahasiswa(data, n, npm);
if (idx == -1) {
    cout << "Data mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
return;
}

for (int i = idx; i < n-1; i++) {
    data[i] = data[i+1];
}
n--;
cout << "Data mahasiswa dengan NPM " << npm << " berhasil dihapus." << endl;
}

int main() {
Mahasiswa dataMahasiswa[MAX_MAHASISWA];
int n = 0;

while (true) {
    cout << "Menu Program" << endl;
    cout << "1. Input Data Mahasiswa" << endl;
    cout << "2. Tampil Data Mahasiswa" << endl;
    cout << "3. Edit Data Mahasiswa" << endl;
    cout << "4. Hapus Data Mahasiswa" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    int pilihan;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:

            inputDataMahasiswa(dataMahasiswa, n);
            break;
        case 2:

            tampilDataMahasiswa(dataMahasiswa, n);
            break;
        case 3:
            editDataMahasiswa(dataMahasiswa, n);
            break;
        case 4:
            hapusDataMahasiswa(dataMahasiswa, n);
            break;
        case 5:
            note();
            cout << "Terima kasih telah menggunakan program ini." << endl;
            exit(0);
        default:
            note();
            cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
            break;
    }
}
return 0;
}
