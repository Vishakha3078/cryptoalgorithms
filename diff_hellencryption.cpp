#include"crypto.h"
ZZ_p cryptoAlgo::diff_hellencryption(ZZ skey,ZZ_p g){
  return power(g,skey);
}
