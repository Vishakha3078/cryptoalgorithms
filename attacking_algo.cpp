#include"crypto.h"

ZZ_p AttackAlgo::func(ZZ_p x){
    return power(x,ZZ(2))+to_ZZ_p(this -> constant);
}  

ZZ AttackAlgo::pollard_rho_factorization(){
    ZZ_p x = to_ZZ_p(RandomBnd(this -> p));
    this -> constant = RandomBnd(this -> p);
    ZZ_p f = func(x);
    if(rep(x - f) == this -> p)
        pollard_rho_factorization();
    ZZ P = GCD(rep(x-f),this -> p);
    int cnt = 0;
    while(P == ZZ(1)){
        cnt++;
        x = f;
        f = func(func(x));
        P = GCD(rep(x-f),this -> p);
        if(P == this -> p || cnt > 20)
            P = pollard_rho_factorization();        
    }
    return P;
}


ZZ AttackAlgo::pollard_rho_minus_factorization(){
    ZZ B = RandomBnd(ZZ(20));
    ZZ_p a = to_ZZ_p(RandomBnd(this -> p));
    ZZ j = ZZ(2);
    a = power(a,j);
    ZZ d = GCD((rep(a)-ZZ(1)),this -> p);
    while( j < B && d == ZZ(1)){
        j++;
        a = power(a,j);
        ZZ d = GCD((rep(a)-ZZ(1)),this -> p);
    }
    if(d == ZZ(1))
        d = pollard_rho_minus_factorization();
      
      
    return d;
}

tuple<ZZ_p,ZZ_p,ZZ_p> AttackAlgo::dlp_func(ZZ_p r,ZZ_p a,ZZ_p b){
    if(rep(r) % 3 == 1)
        return make_tuple((this -> h)*r,a,b+to_ZZ_p(1));
    else if(rep(r) % 3 == 0)
        return make_tuple(power(r,ZZ(2)),to_ZZ_p(2)*a,to_ZZ_p(2)*b);
    else 
        return make_tuple((this -> g)* r,a+to_ZZ_p(1),b);
}


ZZ_p AttackAlgo::pollard_rho_dlp(){
    ZZ_p r = to_ZZ_p(RandomBnd(this -> p));
    ZZ_p a = to_ZZ_p(0);
    ZZ_p b = to_ZZ_p(0);
    map<ZZ_p,std::tuple<ZZ_p,ZZ_p>>myMap;
    myMap[r] = make_tuple(a,b);
    bool found = 0;
    tuple<ZZ_p,ZZ_p,ZZ_p>temp;
    while(found == 0){
        temp = this -> dlp_func(r,a,b);
        if(myMap.count(get<0>(temp)) == 0){
            r = get<0>(temp);
            a = get<1>(temp);
            b = get<2>(temp);
            myMap[r] = make_tuple(a,b);                      
        }
        else 
            found = 1;
    }
    ZZ_p::init((this -> p) -ZZ(1));
    return (get<0>(myMap[get<0>(temp)]) - get<1>(temp))* inv(get<2>(temp)-get<1>(myMap[get<0>(temp)]));
}
