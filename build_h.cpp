#include"crypto.h"

ZZ_p cryptoAlgo::build_h(){
  return power(this -> generator,this -> privatekey);
}
