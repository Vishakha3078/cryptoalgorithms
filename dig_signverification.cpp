#include"crypto.h"
bool cryptoAlgo::dig_signverification(ZZ_p m,ZZ_p gamma,ZZ_p delta){
	ZZ_p g;
    this -> h = power(this ->h,rep(gamma));
  gamma = power(gamma,rep(delta));
	gamma = this -> h * gamma;
	//cout << gamma << endl;
	g = power(this -> generator,rep(m)); 
	//cout << g << endl;
	if (gamma == g){
		return true;
	}
	return false; 
}
