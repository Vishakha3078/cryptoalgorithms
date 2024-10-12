#include"crypto.h"
encrypt cryptoAlgo::elgamal_encryption(ZZ_p m,ZZ randomy){
  encrypt msg;
  msg.text1 = power(this -> generator,randomy);
  msg.text2 = power(this -> h,randomy);
  msg.text2 = msg.text2 * m;
  return msg;
}
