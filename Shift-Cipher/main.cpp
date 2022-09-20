/* 
Nama        : Amariel Danendra Dagna
NPM         : 140810200058
Kelas       : B
Deksripsi   : Program Shift Cipher dengan C++
*/

#include <iostream>
#include "shiftcipher.cpp"

int main() {
    bool programRunning=true;

    while(programRunning) {
        std::string plaintext="";
        int key=1;
        int pilihan=1;

        printf("*------------------------------------------------------*\n");
        printf("|                           MENU                       |\n");
        printf("*------------------------------------------------------*\n");
        printf("| 1. Enkripsi                                          |\n");
        printf("| 2. Dekripsi                                          |\n");
        printf("| 3. Keluar                                            |\n");
        printf("*------------------------------------------------------*\n");

        std::cout << "Pilihan: "; std::cin >> pilihan;
        std::cin.ignore();

        switch(pilihan) {
            case 1:
                std::cout << "Masukkan teks yang ingin dienkripsi: "; std::getline(std::cin,plaintext);
                std::cout << "Masukkan key: "; std::cin >> key;
                std::cout << "Hasil enkripsi = " << ShiftCipher::encrypt(plaintext,key) << "\n";
                break;

            case 2:
                std::cout << "Masukkan teks yang ingin didekripsi: "; std::getline(std::cin,plaintext);
                std::cout << "Masukkan key: "; std::cin >> key;
                std::cout << "Hasil dekripsi = " << ShiftCipher::decrypt(plaintext,key) << "\n";
                break;

            case 3:
                programRunning=false;
                break;

            default: 
                printf("Ada kesalahan dalam memilih, silahkan coba lagi!\n");
                system("pause");
                break;
        }
    }
}