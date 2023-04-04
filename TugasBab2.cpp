#include <iostream>
using namespace std;

int main() {
    // Tentukan nilai n
    int Thanos = 3;

    // Buat array 2D dengan nilai awal 0
    int array[Thanos][Thanos] = {0};

    // Isi array dengan nilai dari 1 sampai n^2
    int count = 1;
    for (int i = 0; i < Thanos; i++) {
        for (int j = 0; j < Thanos; j++) {
            array[i][j] = count;
            count++;
        }
    }

    // Cetak array sebelum diputar
    cout << "Array sebelum diputar:" << endl;
    for (int i = 0; i < Thanos; i++) {
        for (int j = 0; j < Thanos; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Lakukan rotasi array 90 derajat searah jarum jam
    for (int i = 0; i < Thanos/2; i++) {
        for (int j = i; j < Thanos-i-1; j++) {
            int temp = array[i][j];
            array[i][j] = array[Thanos-j-1][i];
            array[Thanos-j-1][i] = array[Thanos-i-1][Thanos-j-1];
            array[Thanos-i-1][Thanos-j-1] = array[j][Thanos-i-1];
            array[j][Thanos-i-1] = temp;
        }
    }

    // Cetak array setelah diputar
    cout << "Array setelah diputar:" << endl;
    for (int i = 0; i < Thanos; i++) {
        for (int j = 0; j < Thanos; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}