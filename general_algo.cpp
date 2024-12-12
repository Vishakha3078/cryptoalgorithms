#include"crypto.h"

ZZ_p cryptoAlgo::build_h(){
  return power(this -> generator,this -> privatekey);
}

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


ZZ_p cryptoAlgo::diff_hellencryption(ZZ skey){
    return  power(this -> generator,skey);
}


ZZ_p cryptoAlgo::diff_helldecryption(ZZ skey,ZZ_p recievedkey){
  return power(recievedkey,skey);
}

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

encrypt cryptoAlgo::elgamal_encryption(ZZ_p m,ZZ randomy){
  encrypt msg;
  msg.text1 = power(this -> generator,randomy);
  msg.text2 = power(this -> h,randomy);
  msg.text2 = msg.text2 * m;
  return msg;
}

 long cryptoAlgo::elgamal_decryption(ZZ_p text1,ZZ_p text2){
  text1 = inv(power(text1,this -> privatekey));
  text1 = text1 * text2;
        cout <<text1<<endl;
  long val ;
  conv(val,text1);
  return val;
}
