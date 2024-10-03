#include<iostream>
#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<string>
using namespace std;
using namespace NTL;

typedef struct encrypted_text{
  ZZ_p text1;
  ZZ_p text2;
}encrypt;
 
typedef struct dig_signature{
	ZZ_p gamma;
	ZZ_p delta;
}signature;

class cryptoAlgo{
    public:
    ZZ p,x;
    ZZ_p g,h;
    ZZ brutef_dlp(ZZ p,ZZ_p g,ZZ_p h);
    ZZ_p diff_hellencryption(ZZ skey,ZZ_p g);
    ZZ_p diff_helldecryption(ZZ skey,ZZ_p recievedkey);
    encrypt elgamal_encryption(ZZ_p g, ZZ_p m,ZZ skey,ZZ randomy);
    long elgamal_decryption(ZZ_p text1,ZZ_p text2,ZZ skey);
    signature dig_sign(ZZ p,ZZ_p g,ZZ_p x, ZZ_p m);
    bool dig_signverification(ZZ_p g ,ZZ_p x,ZZ_p m,ZZ_p gamma,ZZ_p delta);
};
