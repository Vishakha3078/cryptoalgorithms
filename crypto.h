#include<iostream>
#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<string>
#include<cmath>
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
    private:
    ZZ prime;
    ZZ_p generator;
    ZZ privatekey;
    ZZ_p h;
    public:
    cryptoAlgo(ZZ prime){
        this -> prime = prime;
        this -> privatekey = RandomBnd(prime);
        ZZ_p::init(this ->prime);
        conv(this -> generator,RandomBnd(prime));
        this -> h = build_h(); 
  }
    ZZ_p build_h();
    ZZ brutef_dlp();
    ZZ_p diff_hellencryption(ZZ skey);
    ZZ_p diff_helldecryption(ZZ skey,ZZ_p recievedkey);
    encrypt elgamal_encryption( ZZ_p m,ZZ randomy);
    long elgamal_decryption(ZZ_p text1,ZZ_p text2);
    signature dig_sign(ZZ_p m);
    bool dig_signverification(ZZ_p m,ZZ_p gamma,ZZ_p delta);
};  

typedef struct point{
  ZZ_p x;
  ZZ_p y;
}point;

typedef struct two_pnt{
  point a;
  point b;
}two_pnt;

class elliptic_curve{
  private:
    ZZ prime;
    ZZ_p a;
    ZZ_p b;
    ZZ secretkey;
  public:
    elliptic_curve(ZZ prime,ZZ_p a,ZZ_p b){
        this -> prime = prime; 
        ZZ_p::init(this ->prime);
        this -> a = a;
        this -> b = b;
        this -> secretkey = RandomBnd(this->prime);
    } 
    point build_Q(point pt);
    two_pnt el_gamal_encrypt(point pt,point m);
    point el_gamal_decrypt(point pt1,point pt2);
    bool check_exist(ZZ_p x); 
    point *ell_curve_point(int x);
    point point_addition(point a, point b);
    int totalbits(ZZ n);
    int* bit_array(ZZ n,int size);
    point scalar_multiplication(point a,ZZ m);
    ZZ_p square_and_multiply(point a);

};






