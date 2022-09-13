#include<bits/stdc++.h>

using namespace std;

string encrypt (string &input,int n,int key)
{
    int i;
    for(i=0;i<n;i++){
        if(input[i]>='a' && input[i]<='z')
            input[i]=(input[i]+key+i-'a')%26+'a';
        else if(input[i]>='A' && input[i]<='Z')
            input[i]=(input[i]+key+i-'A')%26+'A';

    }


return input;
}

string decrypt (string &input,int n,int key)
{
    int i;
    for(i=0;i<n;i++){
        if(input[i]>='a' && input[i]<='z')
            input[i]=(input[i]-key-i-'z')%26+'z';
        else if(input[i]>='A' && input[i]<='Z')
            input[i]=(input[i]-key-i-'Z')%26+'Z';

    }


return input;
}


int main()
{
    string plainText,cipherText,decrypted;
    int n,key;

    cout<<"Enter the string: ";
    getline(cin,plainText);

    n=plainText.length();

    cout<<"Enter the key: ";
    cin>>key;

    cipherText=encrypt(plainText,n,key);
    cout<<"Encrypted message: "<<cipherText<<endl;

    decrypted=decrypt(cipherText,n,key);
    cout<<"Decrypted message: "<<decrypted<<endl;

}
