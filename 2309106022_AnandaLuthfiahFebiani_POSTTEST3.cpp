#include <iostream>
#include <string>
using namespace std;

#define MAX 100
string data1[MAX];
int pos = 0;

int HitungKarData(int index) {
    if (index == pos) return 0;
    return data1[index].length() + HitungKarData(index + 1);
}

void TampilKarData() {
    cout << "Jumlah karakater dalam data ATK/S: " << HitungKarData(0) << endl;
}
void Tampil() {
    if (pos > 0) {
        cout << "Data ATK/S Ditampilkan\n";
        for (int i = 0; i < pos; i++) {
            cout << i + 1 << ". " << data1[i] << endl;
        }
    } else {
        cout << "=== Data Masih Kosong ===\n";
    }
}
void Tambah() {
    if (pos < MAX) {
        cin.ignore();
        cout << "Tambah Data ATK/S yang di inginkan: ";
        getline (cin, data1[pos++]);
    } else {
        cout << "<-- GUDANG ATK/S TELAH PENUH -->\n";
    }
    Tampil();
}

void Ubah() {
    Tampil();
    cout << "Ubah Data Ke: ";
    int y;
    cin >> y;
    if (y > 0 && y <= pos) {
        cin.ignore();
        cout << "Ubah Menjadi: ";
        getline(cin, data1[y - 1]);
    }
    Tampil();
}

void Hapus() {
    Tampil();
    cout << "Hapus Data ke: ";
    int x;
    cin >> x;
    if (x > 0 && x <= pos) {
        for (int i = x; i < pos; i++) {
            data1[i - 1] = data1[i];
        }
        pos--;
    }
    Tampil();
}

void Cari() {
    if(pos == 0) {
        cout << "Data ATK/S masih kosong\n";
        return;
    }

    cin.ignore();
    string pencarian;
    cout << "Masukkan data ATK/S yang ingin dicari: ";
    getline(cin, pencarian);

    bool ketemu = false;
    for (int i = 0; i < pos; i++) {
        if (data1[i].find(pencarian) != string::npos) {
            if (!ketemu) {
                cout << "Hasil data pencarian ATK/S: \n";
                ketemu = true;
            }
            cout << i + 1 << ". " << data1[i] << endl;
        }
    }

    if (!ketemu) {
        cout << "Data ATK/S tidak ditemukan \n";
    }
}

void Urut() {
    Tampil();
    for (int i = 0; i < pos - 1; i++) {
        for(int j = 0; j < pos - i - 1; j++) {
            if (data1[j] > data1[j +1]) {
                string pengurutan = data1[j];
                data1[j] = data1[j + 1];
                data1[j + 1] = pengurutan;
            }
        }
    }
    Tampil();
    cout << "Data ATK/S telah diurutkan\n";
}

bool Login() {
    string Username, Password;
    cout << "=== Login ===\n";
    cout << "Username: ";
    getline(cin, Username);
    cout << "Password: ";
    getline(cin, Password);
    return Username == "nanda" && Password == "2309106022";
}

int main() {
    int percobaan = 0;
    while (percobaan < 3 && !Login()) {
        cout << "Login gagal. Kesempatan mencoba: " << 2 - percobaan << " kali\n";
        percobaan++;
    }

    if (percobaan == 3) {
        cout << "Percobaan Login telah melebihi batas, percobaan berhenti\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== GUDANG PENDATAAN ATK/S ===\n"
             << "1. Tambah Data ATK/S\n"
             << "2. Ubah Data ATK/S\n"
             << "3. Hapus Data ATK/S\n"
             << "4. Tampilkan Data ATK/S\n"
             << "5. Cari Data ATK/S\n"
             << "6. Urutkan Data ATK/S\n"
             << "7. Tampilan jumlah karakter Data ATK/S\n"
             << "8. Keluar\n"
             << "Pilih menu yang tertera diatas (1/2/3/4/5/6/7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                Tambah(); 
                break;
            case 2: 
                Ubah(); 
                break;
            case 3: 
                Hapus(); 
                break;
            case 4: 
                Tampil(); 
                break;
            case 5:
                Cari();
                break;
            case 6:
                Urut();
                break;
            case 7:
                TampilKarData();
                break;
            case 8: 
                cout << "Terima kasih telah mendata program ATK/S\n"; 
                return 0;
            default: 
                cout << "Pilihan Invalid\n";
        }
    } while (true);

    return 0;
}
