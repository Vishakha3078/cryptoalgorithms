#include"crypto.h"
ZZ_p cryptoAlgo::diff_hellencryption(ZZ p,ZZ skey,ZZ_p g){
  p = conv<ZZ>(p);
  ZZ_p :: init(p);
  return = power(g,skey);
}
