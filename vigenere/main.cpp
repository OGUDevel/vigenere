//
//  main.cpp
//  vigenere
//
//  Created by Mahmut Bulut on 10/2/12.
//  Copyright (c) 2012 Mahmut Bulut. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

string encrypt(string, string);
string decrypt(string, string);

int main(int argc, const char * argv[])
{
    cout << "Enter plain text: " << endl;
    string text;
    cin >> text;
    cout << "Enter Key: " << endl;
    string key;
    cin >> key;
    
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    
    text = text.c_str();
    key = key.c_str();
    if (text.length() > key.length()) {
        int fark = text.length() - key.length();
        for (int i=0; i<fark; i++) {
            key = key + key[i];
        }
    }
    
    string cipherd = encrypt(text, key);
    decrypt(cipherd, key);
    
    return 0;
}

string encrypt(string text, string key){
    cout  << text << "\t: Selected pre-encryption Plain Text (P)" <<endl;
    cout << key << "\t: Selected pre-encryption Key (K)" << endl;
    
    for (int i=0; i<=text.length();i++) {
        text[i]+=(key[i]-'A');
        if (text[i] > 'Z') {
            //Additional character for count data reset
            char fark = text[i] - '[';
            text[i] = fark + 'A';
        }
    }
    cout  << text<< "\t: Ciphered Text output (C)" <<endl;
    return text;
}

string decrypt(string ciphered, string key){
    cout  << ciphered  << "\t: Selected pre-decryption Ciphered Text (C)" << endl;
    transform(ciphered.begin(), ciphered.end(), ciphered.begin(), ::toupper);
    cout  << key << "\t: Selected pre-decryption Key (K)" << endl;
    
    for (int i=0; i<=ciphered.length(); i++) {
        if (ciphered[i] > key[i]) {
            ciphered[i]-=key[i];
            ciphered[i]+='A';
        }else{
            key[i]-='A';
            char constraint = ciphered[i];
            ciphered[i]-=key[i];
            if(ciphered[i] < 'A'){
                ciphered[i] = 'Z' - (key[i]-(constraint-'@'));
            }
        }
    }
    cout << ciphered << "\t: Plain Text output (P)" << endl;
    return ciphered;
}