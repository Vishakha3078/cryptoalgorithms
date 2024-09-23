#include"crypto.h"
encrypt cryptoAlgo::elgamal_encryption(ZZ_p g,ZZ_p m,ZZ skeyx,ZZ randomy){
  ZZ_p h;
  encrypt msg;
  h = power(g,skeyx);
  msg.text1 = power(g,randomy);
  msg.text2 = power(h,randomy);
  msg.text2 = msg.text2 * m;
  return msg;
}
