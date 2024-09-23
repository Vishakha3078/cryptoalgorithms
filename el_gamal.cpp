#include"crypto.h"
ZZ_p cryptoAlgo::el_gamal(ZZ p,ZZ_p g,ZZ_p m,ZZ skeyx,ZZ randomy){
    p = conv<ZZ>(p);
    ZZ_p::init(p);
    //ZZ x,y;
    ZZ_p C1,C2,message;
    /*cout << "enter secret key(x): "<<endl;
    cin>>x;
    cout<< "enter message: "<<endl;
    cin>>m;
    cout <<"enter some number from group(y): "<<endl;
    cin>>y;*/
    h = power(g,skeyx);
    
    // encryption
    C1 = power(g,randomy);
    C2 = power(h,randomy);
    C2 = C2 * m; 

  //decryption
    C1 = inv(power(C1,skeyx));
    message = C1 * C2;
    return message;
 }

