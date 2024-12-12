#include"crypto.h"

struct ZZ_pComparator{
    bool operator()(const NTL::ZZ_p& a,const NTL::ZZ_p& b) const{
        return NTL::rep(a) < NTL::rep(b);   
    }
};


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
    ZZ_p r =to_ZZ_p(83);//(RandomBnd(this -> p));
      cout<<"r choosen "<<r<<endl;
    ZZ_p a = to_ZZ_p(0);
    ZZ_p b = to_ZZ_p(0);
    map<ZZ_p,std::tuple<ZZ_p,ZZ_p>,ZZ_pComparator>myMap;
    myMap[r] = make_tuple(a,b);
    bool found = 0;
    tuple<ZZ_p,ZZ_p,ZZ_p>temp;
    while(found == 0){
        temp = this -> dlp_func(r,a,b);
  cout<<"r = "<<get<0>(temp)<<"a = "<<get<1>(temp)<<"b = "<<get<2>(temp)<<endl;
        if(myMap.count(get<0>(temp)) == 0){
            r = get<0>(temp);
            a = get<1>(temp);
            b = get<2>(temp);
            myMap[r] = make_tuple(a,b);                      
        }
        else{ 
      cout<<"here"<<endl;
            found = 1;
        }
    }
    ZZ_p::init((this -> p) -ZZ(1));
    a = get<0>(myMap[get<0>(temp)]) - get<1>(temp);
      cout<<"a"<<a<<endl;
    b = get<2>(temp)-get<1>(myMap[get<0>(temp)]);
      cout<<"b"<<b<<endl;
    ZZ gcd = GCD(rep(b),(this -> p)-ZZ(1));
      cout<<"gcd"<<gcd<<endl;
    if(gcd != ZZ(1)){
      cout<<"true"<<endl;
        b = to_ZZ_p(rep(b)/gcd);
      cout<<"b"<<b<<endl;
        a = to_ZZ_p(rep(a)/gcd);
      cout<<"a"<<a<<endl;
        ZZ pr = ((this -> p) -ZZ(1))/gcd;
        ZZ_p::init(pr);
        ZZ_p s = a*inv(b);
        ZZ_p::init((this -> p) -ZZ(1));
        for (ZZ j = ZZ(0); j <= gcd; j++){
            r = s + to_ZZ_p(j)*to_ZZ_p(((this -> p)-ZZ(1))/gcd);
            ZZ_p::init(this -> p);
            a = power(this -> g,rep(r));
      cout<<"power "<<a<<endl;
      cout<<" h "<<this -> h<<endl;
            ZZ_p::init(this -> p);
            if(power(this -> g,rep(r)) == this -> h)
                break;
            ZZ_p::init((this -> p) -ZZ(1));
        }
        return r;
    }
    else{
        r = a*inv(b);
            ZZ_p::init(this -> p);
        cout << "power -> "<<power(this -> g,rep(r))<<endl;
        return r;
  }
}
