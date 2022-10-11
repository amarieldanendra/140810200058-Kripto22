/*
Nama        : Amariel Danendra Dagna
NPM         : 140810200058
Kelas       : B 
Deskripsi   : Program Vigenere Cipher dengan C++
*/

#include <iostream>
#include <string>
using namespace std;
 
class Vigenere{
    public:
        string key;
 
        Vigenere(string key){
            for (int i = 0; i < key.size(); ++i){
                if (key[i] >= 'A' && key[i] <= 'Z')
                    this->key += key[i];
                else if (key[i] >= 'a' && key[i] <= 'z')
                    this->key += key[i] + 'A' - 'a';
            }
        }
 
        string enkripsi(string teks){
            string hasil;
 
            for (int i = 0, j = 0; i < teks.length(); ++i){
                char temp = teks[i];
 
                if (temp >= 'a' && temp <= 'z')
                    temp += 'A' - 'a';
                else if (temp < 'A' || temp > 'Z')
                    continue;
 
                hasil += (temp + key[j] - 2 * 'A') % 26 + 'A';
                j = (j + 1) % key.length();
            }
            return hasil;
        }
 
        string dekripsi(string teks){
            string hasil;
 
            for (int i = 0, j = 0; i < teks.length(); ++i){
                char temp = teks[i];
 
                if (temp >= 'a' && temp <= 'z')
                    temp += 'A' - 'a';
                else if (temp < 'A' || temp > 'Z')
                    continue;
 
                hasil += (temp - key[j] + 26) % 26 + 'A';
                j = (j + 1) % key.length();
            }
            return hasil;
        }
};
 
int main(){
    Vigenere cipher("OLA");
 
    string teks = "NAMA SAYA AMARIEL";
    string enkripsi = cipher.enkripsi(teks);
    string dekripsi = cipher.dekripsi(enkripsi);
 
    cout << "---------- Vigenere Cipher ----------\n";
    cout << "Teks     : "<< teks <<"\n";
    cout << "Key      : OLA\n";
    cout << "---------------- Hasil ---------------\n";
    cout << "Enkripsi : " << enkripsi << endl;
    cout << "Dekripsi : " << dekripsi << endl;
}