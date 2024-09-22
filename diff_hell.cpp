
#include"crypto.h"
ZZ_p cryptoAlgo::diff_hell(ZZ p,ZZ_p g,ZZ alice_skey,ZZ bob_skey){
    //ZZ a,b;
    ZZ_p A,B;
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    A = power(g,alice_skey);
    B = power(g,bob_skey);
    //cout << "alice's key : "<<power(B,alice_skey)<<endl;
    //cout << "bob's key : " << power(A,bob_skey)<<endl;
    return power(B,alice_skey) ;
}
