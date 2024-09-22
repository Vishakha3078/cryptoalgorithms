#include"crypto.h"
ZZ cryptoAlgo::brutef_dlp(ZZ p,ZZ_p g,ZZ_p h){
  p = conv<ZZ>(p);
  ZZ_p::init(p);
	ZZ_p pow;
	ZZ x;
       // h = power(g,x);
	for(x = 0; x < p ; x++){
            pow = power(g,x);
            if(pow == h){
                return x;            
    }
        }
        return p;
}
