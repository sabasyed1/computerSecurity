#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
class VigenereCipher {
   public:
      string k;
   VigenereCipher(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
//Encrypts string
   string encryptionData(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; 
         j = (j + 1) % k.length();
      }
      return output;
   }
//Decrypts string
   string decryptionData(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';
         j = (j + 1) % k.length();
      }
      return output;
   }
};
int main() {
   
   string ori;
  //Enter string
   cout<<"Enter string: ";
   getline (cin, ori);
   string key;
  //Enter keyword
   cout<<"Enter key: ";
   cin>>key;      
   VigenereCipher v(key);
  //Encrypts & decrypts
   string encrypt = v.encryptionData(ori);
   string decrypt = v.decryptionData(encrypt);
  //prints out results
   cout << "Original Message: "<<ori<< endl;
   cout << "Encrypted Message: " << encrypt << endl;
   cout << "Decrypted Message: " << decrypt << endl;
}
