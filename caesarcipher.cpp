#include <iostream>
#include <string>



void enkripsi(){
    std::string text;
    int shift;
    std::string encryptedText;

    std::cout << "Masukkan Plain teks: ";
    std::cin.ignore(); 
    std::getline(std::cin, text);

    do {
    std::cout << "Masukkan Shift (0 - 25): ";
    std::cin >> shift;
    }  
     while (shift < 0 || shift > 25);
    
     for (char c : text) {
        if (isalpha(c)) {  
            char base = islower(c) ? 'a' : 'A';
            char encryptedChar = (c - base + shift) % 26 + base;
            encryptedText += encryptedChar;
        } else {
            encryptedText += c;  
        }
    }

    std::cout << encryptedText << "\n";
}

void dekripsi(){
    std::string text;
    int shift;
    std::string decryptedText;

    std::cout << "Masukkan cipher teks: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    do {
    std::cout << "Masukkan Shift (0 - 25): ";
    std::cin >> shift;
    }  
     while (shift < 0 || shift > 25);
    
     for (char c : text) {
        if (isalpha(c)) {  
            char base = islower(c) ? 'a' : 'A';
            char encryptedChar = (c - base - shift) % 26;
            if (encryptedChar < 0){
                encryptedChar = encryptedChar + 26;
            }

            decryptedText += (encryptedChar + base);
        } else {
            decryptedText += c;  
        }
    }

    std::cout << decryptedText << "\n";
}


void mainmenu(){
    int pilihan;
    do{
        std::cout << "SELAMAT DATANG DI CAESAR CIPHER\n";
        std::cout << "1. Enkripsi\n";
        std::cout << "2. Dekripsi\n";
        std::cout << "0. Exit\n";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
            enkripsi();
            break;

            case 2:
            dekripsi();
            break;

            case 0:
            exit;
            break;

            default:
            std::cout << "Input Tidak Valid";
            break;
        }
    } while (pilihan != 0);
}

int main() {
    
    mainmenu();

}
