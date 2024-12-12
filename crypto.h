#include<iostream>
#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<string>
#include<cmath>
#include<map>
#include<tuple>
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


typedef struct enc_txt{
  point c1;
  ZZ_p c2;
}enc_txt;


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
    bool check_exist(ZZ_p x); 
    int totalbits(ZZ n);
    int* bit_array(ZZ n,int size);
    point *ell_curve_point(int x);
    point point_addition(point a, point b);
    point scalar_multiplication(point a,ZZ m);
    ZZ_p square_and_multiply(point a);
    two_pnt el_gamal_encrypt(point pt,point m);
    point el_gamal_decrypt(point pt1,point pt2);
    enc_txt integrated_encrypt(point pt,ZZ m);
    ZZ_p integrated_decrypt(enc_txt text);
    signature digital_sign(point pt,ZZ order,ZZ_p m);
    bool digital_sign_verification(signature sign,ZZ_p m,point pt);
};

class RSA{
  private:
      ZZ p;
      ZZ q;
      ZZ_p d;
  public:
      ZZ n;
      ZZ_p e;
      RSA(ZZ p,ZZ q){
          this -> p = p;
          this -> q = q;
          this -> n = p * q;
          this -> e = createe();
          this -> d = inv(e);
          ZZ_p::init(this -> n);
      }
      ZZ given();
      ZZ_p createe();
      ZZ_p RSA_encrypt(ZZ_p m);
      long RSA_decrypt(ZZ_p res);
      ZZ_p dig_sign(ZZ_p m);
      bool dig_sign_verify(ZZ_p sign,ZZ_p m);
};

class AttackAlgo{
  private:
      ZZ p;
      ZZ constant;
      ZZ_p g;
      ZZ_p h;
  public:
      AttackAlgo(ZZ p,ZZ_p g,ZZ_p h){
          this -> p = p;
          ZZ_p::init(this ->p);
          this -> g = g;
          this -> h = h;
      }
      ZZ_p func(ZZ_p x);
      ZZ pollard_rho_factorization();
      ZZ pollard_rho_minus_factorization();
      tuple<ZZ_p,ZZ_p,ZZ_p> dlp_func(ZZ_p r,ZZ_p a,ZZ_p b);
      ZZ_p pollard_rho_dlp();
};
