#include"crypto.h"

ZZ RSA::given(){
    return this -> p * this -> q;
}


ZZ_p RSA::createe(){
    ZZ tot_func = (this -> p - 1) * (this -> q - 1);
        cout <<"tot  -> "<<tot_func<<endl;
    ZZ_p::init(tot_func);
    ZZ_p e;
    do{
          e = to_ZZ_p(RandomBnd(tot_func));
    }while(GCD(tot_func,rep(e)) != ZZ(1));
    return e;
}


ZZ_p RSA::RSA_encrypt(ZZ_p m){
    printf("inencr\n");
        ZZ_p res = power(m,rep(this -> e));
        return res;
}

long RSA::RSA_decrypt(ZZ_p res){
    printf("indencr\n");
    ZZ_p temp = power(res,rep(this -> d));
    long val;
    conv(val,temp);
    return val;
}


ZZ_p RSA::dig_sign(ZZ_p m){
    return power(m,rep(this -> d));
}


bool RSA::dig_sign_verify(ZZ_p sign,ZZ_p m){
    if(power(sign,rep(this -> e)) == m )
        return 1;
    else 
        return 0;
}
