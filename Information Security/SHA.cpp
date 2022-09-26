#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int int64;
int64 Message[80];

const int64 Constants[80]=
        {0x428a2f98d728ae22, 0x7137449123ef65cd,
        0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019,
        0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe,
        0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
        0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
        0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
        0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210,
        0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725,
        0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926,
        0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8,
        0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001,
        0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910,
        0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
        0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
        0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60,
        0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9,
        0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207,
        0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6,
        0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493,
        0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
        0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };

int64 HashBuffer[8]={0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
                    0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
                    0x510e527fade682d1, 0x9b05688c2b3e6c1f,
                    0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};

int64 h[8];

int64 rotate_right(int64 x, int n)  {return (x >> n) | (x << (64 - n));}
int64 shift_right(int64 x, int n)   {return (x >> n);}
int64 maj(int64 a, int64 b, int64 c) {return (a & b) ^ (b & c) ^ (c & a);}
int64 Ch(int64 e, int64 f, int64 g)  {return (e & f) ^ (~e & g);}
int64 sigmaA(int64 a)   {return rotate_right(a, 28)^ rotate_right(a, 34)^ rotate_right(a, 39);}
int64 sigmaE(int64 e)   {return rotate_right(e, 14)^ rotate_right(e, 18)^ rotate_right(e, 41);}
int64 BintoDec(string bin) {return bitset<64>(bin).to_ullong();}    // Convert a binary string to decimal value


void Func(int K)
{
	// Find the Hash Code
	int64 T1 = h[7] + Ch(h[4], h[5], h[6]) + sigmaE(h[4]) + Message[K] + Constants[K];
	int64 T2 = sigmaA(h[0]) + maj(h[0], h[1], h[2]);

            h[7]=h[6];
			h[6]=h[5];
			h[5]=h[4];
			h[4]=h[3]+T1;
			h[3]=h[2];
			h[2]=h[1];
			h[1]=h[0];
			h[0]=T1+T2;
}

void separator(string getBlock)
{
    int i,j=0;

    //copy first 16 words
    for(i=0;i < getBlock.length();j++,i+=64){
        Message[j] = BintoDec(getBlock.substr(i, 64));
    }

    // Iterate over the range [16, 80]
    for (int g = 16; g < 80; ++g) {
        int64 WordA = rotate_right(Message[g - 2], 19)^ rotate_right(Message[g - 2], 61)^ shift_right(Message[g - 2], 6);
        int64 WordB = Message[g - 7];
        int64 WordC = rotate_right(Message[g - 15], 1)^ rotate_right(Message[g - 15], 8)^ shift_right(Message[g - 15], 7);
        int64 WordD = Message[g - 16];

        int64 T = WordA + WordB + WordC + WordD;

        Message[g] = T;
    }
//    for(i=0;i<80;i++){
//        cout<<Message[i]<<" ";
//    }
//    cout<<endl;
}

void SHA(string str)
{
    int len=str.length();

    int block_num=ceil((float)(len+16+1)/128);
    int mod=128-(len+16)%16;

    cout<<"\nLength (before padding): "<<str.length()<<" bytes\t"<<len*8<<" bits"<<endl;
    cout<<"Block number:\t"<<block_num<<endl;
    cout<<"Needed bit for padding:\t"<<mod<<" bytes\t"<<mod*8<<" bits"<<endl;

    //initial padding
    stringstream fixedstream;
	for (int i = 0;i < str.size(); ++i) {
		fixedstream << bitset<8>(str[i]);
	}
    str = fixedstream.str();

    str+="1";
    for(int i=0;i<(mod*8-129);i++)
        str+="0";

    cout<<"Length (after padding):\t"<<str.length()/8<<" bytes\t"<<str.length()<<" bits"<<endl;

    //length
    string lengthbits= std::bitset<128>(len*8).to_string();
    str += lengthbits;
    cout<<"Length (adding length): "<<str.length()/8<<" bytes\t"<<str.length()<<" bits\n"<<endl;

    string Blocks[block_num];
    int k=0;
	for (int i = 0; i < str.length();i += 1024, ++k) {
		Blocks[k] = str.substr(i, 1024);
	}

    for(int k=0;k<block_num;++k){
        separator(Blocks[k]);

        for(int i=0;i<8;i++)
            h[i]=HashBuffer[i];

        for(int i=0;i<80;i++){
            Func(i);
        }
        //addition
        for (int j = 0; j < 8; j++){
                HashBuffer[j] += h[j];
            }
    }

    for (int i = 0; i < 8; i++)
	{
		cout<<hex<<HashBuffer[i];
	}

}


int main()
{
    string str;
    cout<<"Enter text: ";
    cin>>str;

    SHA(str);
}
