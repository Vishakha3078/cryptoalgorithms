#include"crypto.h"
bool cryptoAlgo::dig_signverification(ZZ_p g,ZZ_p skey,ZZ_p m,ZZ_p gamma,ZZ_p delta){
  ZZ_p h ;
  power(h,g,rep(skey));
	h = power(h,rep(gamma));
  gamma = power(gamma,rep(delta));
	gamma = h * gamma;
	//cout << gamma << endl;
	g = power(g,rep(m)); 
	//cout << g << endl;
	if (gamma == g){
		return true;
	}
	return false; 
}
