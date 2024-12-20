#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encryptVigenere(string plaintext, string key) {
    string ciphertext = "";
    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char k = toupper(key[j++ % key.length()]);
            c = (((c - 'A') + (k - 'A')) % 26) + 'A';
        }
        ciphertext += c;
    }
    return ciphertext;
}

string decryptVigenere(string ciphertext, string key) {
    string plaintext = "";
    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char k = toupper(key[j++ % key.length()]);
            c = (((c - 'A') + 26 - (k - 'A')) % 26) + 'A';
        }
        plaintext += c;
    }
    return plaintext;
}

string encryptAutokey(string plaintext, string key) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char k = toupper(key[i % key.length()]);
            c = (((c - 'A') + (k - 'A')) % 26) + 'A';
            key += c;
        }
        ciphertext += c;
    }
    return ciphertext;
}

string decryptAutokey(string ciphertext, string key) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char k = toupper(key[i % key.length()]);
            c = (((c - 'A') + 26 - (k - 'A')) % 26) + 'A';
            key += c;
        }
        plaintext += c;
    }
    return plaintext;
}

int main() {
    while (true) {
        cout << "Selamat Datang di Aplikasi Enkriptod\n";
        cout << "Silahkan Pilih Service\n";
        cout << "1. Vigenere Cipher\n";
        cout << "2. Autokey Cipher\n";
        cout << "3. Exit\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 3) {
            break;
        }

        string text, key;
        cout << "Masukkan teks: ";
        cin.ignore();
        getline(cin, text);
        cout << "Masukkan kunci: ";
        getline(cin, key);

        switch (pilihan) {
            case 1: {
                cout << "Pilih operasi \n ";
                cout << "e untuk Enkripsi \n ";
                cout << "d untuk Dekripsi \n ";
                char operasi;
                cin >> operasi;
                if (operasi == 'e') {
                    cout << "Ciphertext: " << encryptVigenere(text, key) << endl;
                } else if (operasi == 'd') {
                    cout << "Plaintext: " << decryptVigenere(text, key) << endl;
                } else {
                    cout << "Operasi tidak valid.\n";
                }
                break;
            }
            case 2: {
                cout << "Pilih operasi \n ";
                cout << "e untuk Enkripsi \n ";
                cout << "d untuk Dekripsi \n ";
                char operasi;
                cin >> operasi;
                if (operasi == 'e') {
                    cout << "Ciphertext: " << encryptAutokey(text, key) << endl;
                } else if (operasi == 'd') {
                    cout << "Plaintext: " << decryptAutokey(text, key) << endl;
                } else {
                    cout << "Operasi tidak valid.\n";
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

}