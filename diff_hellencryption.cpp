#include"crypto.h"
ZZ_p cryptoAlgo::diff_hellencryption(ZZ skey){
  return power(this -> generator,skey);
}
