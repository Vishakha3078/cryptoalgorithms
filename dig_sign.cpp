#include"crypto.h"
signature cryptoAlgo::dig_sign(ZZ_p m){
  ZZ rand_number;
  ZZ_p randomy;
  
  do{
      rand_number = ZZ(RandomBnd(this -> prime - 1));
    }while(GCD(this ->prime-1,rand_number) != ZZ(1));
  conv(randomy,rand_number);
 
    signature output;
    ZZ_p gamma,delta;
    power(gamma,this ->generator,rep(randomy));
    ZZ_p :: init(this ->prime - 1);
  
    randomy = inv(randomy);
    delta = (m - (to_ZZ_p(this -> privatekey) * gamma));
    delta = delta*randomy;
    output.gamma = gamma;
    output.delta = delta;

  return output; 
}

	
