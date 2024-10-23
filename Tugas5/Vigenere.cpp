#include <iostream>
#include <string>
using namespace std;


string encryptVigenere(string plaintext, string key) {
    string encryptedText;
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];

        
        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            int keyCharIndex = key[i % keyLength] - base;

            
            char encryptedChar = (plainChar - base + keyCharIndex) % 26 + base; // enkripsi = (plaintext + key) mod 26
            encryptedText += encryptedChar;
        } else {
            encryptedText += plainChar;
        }
    }
    return encryptedText;
}


string decryptVigenere(string ciphertext, string key) {
    string decryptedText;
    int keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];

       
        if (isalpha(cipherChar)) {
            char base = isupper(cipherChar) ? 'A' : 'a';
            int keyCharIndex = key[i % keyLength] - base;

         
            char decryptedChar = (cipherChar - base - keyCharIndex + 26) % 26 + base; // dekripsi = (enkriptedtext - key) mod 26
            decryptedText += decryptedChar;
        } else {
           
            decryptedText += cipherChar;
        }
    }
    return decryptedText;
}

int main() {
    string plaintext, key;


    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);

    string encryptedText = encryptVigenere(plaintext, key);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decryptVigenere(encryptedText, key);
    cout << "Decrypted text: " << decryptedText << endl;

}
