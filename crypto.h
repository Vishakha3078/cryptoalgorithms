#include<iostream>
#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<string>
using namespace std;
using namespace NTL;
 
typedef struct signature{
	ZZ_p gamma;
	ZZ_p delta;
}signature;

class cryptoAlgo{
    public:
    ZZ p,x;
    ZZ_p g,h;
    ZZ brutef_dlp(ZZ p,ZZ_p g,ZZ_p h);
    ZZ_p diff_hell(ZZ p,ZZ_p g,ZZ akey,ZZ bkey);
    ZZ_p diff_hellencryption(ZZ skey,ZZ_p g);
    ZZ_p diff_helldecryption(ZZ skey,ZZ_p recievedkey);
    ZZ_p el_gamal(ZZ p,ZZ_p g, ZZ_p h,ZZ x,ZZ y);
    signature dig_sign(ZZ p, ZZ_p g, ZZ_p x, ZZ_p y, ZZ_p m,ZZ_p gamma, ZZ_p delta);
};
