#include"crypto.h"
ZZ cryptoAlgo::brutef_dlp(){
	ZZ_p pow;
	ZZ x;
       // h = power(g,x);
	for(x = 0; x < this -> prime ; x++){
            pow = power(this -> generator,x);
            if(pow == this -> h){
                return x;            
    }
        }
        return this -> prime;
}
