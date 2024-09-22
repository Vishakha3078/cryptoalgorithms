#include"iostream"
#include"crypto.h"
int main(){
	cryptoAlgo a;
	ZZ p;
  ZZ_p g;
//diff_hell
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
	ZZ_p::init(p);
  cout << "Enter generator : " <<endl;
  cin >> g;
  //diffhellencryption
    //alice
    ZZ alicekey;
    cout << "Enter secret key of alice: "<<endl;
    cin >> alicekey;
    ZZ_p A = diff_hellencryption(p,alicekey,g);
    //bob
    ZZ bobkey;
    cout << "Enter secret key of bob: "<<endl;
    cin >> bobkey;
    ZZ_p B = diff_hellencryption(p,bobkey,g);
  //diffhelldecryption
    //alice
    ZZ_p AA = diff_helldecryption(p,alicekey,B);
    cout << "Key recieved by alice: "<< AA << endl;
    //bob
    ZZ_p BB = diff_helldecryption(p,bobkey,A);
    cout << "Key recieved by bob: "<< BB << endl;


  //digital signature
  /*
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
	ZZ_p::init(p);
	ZZ_p g,skey,randomy,m,gamma,delta;
	g = 3;
	skey = 5;
	randomy = 7;
	m = 5;
	signature sig =  a.dig_sign(p,g,skey,randomy,m,gamma,delta);
	cout <<"gamma: "<<sig.gamma<< "delta: "<<sig.delta<< endl;*/
	return 0;
}
