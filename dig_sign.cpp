#include"crypto.h"
signature cryptoAlgo::dig_sign(ZZ p,ZZ_p g,ZZ_p skey,ZZ_p m){
  ZZ rand_number;
  ZZ_p randomy;
  
  do{
      rand_number = ZZ(RandomBnd(p - 1));
    }while(GCD(p-1,rand_number) != ZZ(1));
  conv(randomy,rand_number);
 
    signature output;
    ZZ_p gamma,delta;
    power(gamma,g,rep(randomy));
    p = p - 1;
    ZZ_p :: init(p);
  
    randomy = inv(randomy);
    delta = (m - (skey * gamma));
    delta = delta*randomy;
    output.gamma = gamma;
    output.delta = delta;

  return output; 
}

    
	
