#include"crypto.h"
ZZ_p cryptoAlgo::diff_helldecryption(ZZ skey,ZZ_p recievedkey){
  return power(recievedkey,skey);
}
