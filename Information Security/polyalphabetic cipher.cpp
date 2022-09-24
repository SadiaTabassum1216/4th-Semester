#include<bits/stdc++.h>

using namespace std;

string encrypt (string &input,int n)
{
    int i;

     for(i=0;i<n;i++){
        if(input[i]>='a' && input[i]<='z')
            input[i]=(input[i]+i+1-'a')%26+'a';
        else if(input[i]>='A' && input[i]<='Z')
            input[i]=(input[i]+i+1-'A')%26+'A';

    }

return input;
}

string decrypt (string &input,int n)
{
    int i;
    for(i=0;i<n;i++){
        if(input[i]>='a' && input[i]<='z')
            input[i]=(input[i]-i-1-'z')%26+'z';
        else if(input[i]>='A' && input[i]<='Z')
            input[i]=(input[i]-i-1-'Z')%26+'Z';

    }


return input;
}


int main()
{
    string plainText,cipherText,decrypted;
    int n;

    cout<<"Enter the string: ";
    getline(cin,plainText);

    n=plainText.length();


    cipherText=encrypt(plainText,n);
    cout<<"Encrypted message: "<<cipherText<<endl;

    decrypted=decrypt(cipherText,n);
    cout<<"Decrypted message: "<<decrypted<<endl;

}
