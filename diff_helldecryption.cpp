#include"crypto.h"
ZZ_p cryptoAlgo::diff_helldecryption(ZZ p,ZZ skey,ZZ_p recievedkey){
  p = conv<ZZ>(p);
  ZZ_p ::init(p);
  return power(recievedkey,skey);
}
