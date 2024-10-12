#include"crypto.h"
 long cryptoAlgo::elgamal_decryption(ZZ_p text1,ZZ_p text2){
  text1 = inv(power(text1,this -> privatekey));
  text1 = text1 * text2;
  long val ;
  conv(val,text1);
  return val;
}

  
