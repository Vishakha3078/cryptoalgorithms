#include"iostream"
#include"crypto.h"
int main(){
	cryptoAlgo a;
	ZZ p;
  ZZ_p g; 
//bruteforce_dlp----------------------------------------------------------------------------------
/*
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
	ZZ_p::init(p);
  cout << "Enter generator : " <<endl;
  cin >> g;
  ZZ_p h;
  cout << "Enter h : "<<endl;
  cin >> h;
  //ZZ x = ZZ(99);
  //h = power(g,x);
 // cout << h << endl;
  cout << a.brutef_dlp(p,g,h)<<endl; 
 */ 

//diff_hell----------------------------------------------------------------------------------------
  /*
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
    ZZ_p A = a.diff_hellencryption(alicekey,g);
    //bob
    ZZ bobkey;
    cout << "Enter secret key of bob: "<<endl;
    cin >> bobkey;
    ZZ_p B = a.diff_hellencryption(bobkey,g);
  //diffhelldecryption
    //alice
    ZZ_p AA = a.diff_helldecryption(alicekey,B);
    cout << "Key recieved by alice: "<< AA << endl;
    //bob
    ZZ_p BB = a.diff_helldecryption(bobkey,A);
    cout << "Key recieved by bob: "<< BB << endl;
  */
  
//el_gamal----------------------------------------------------------------------------------------
  ///*
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
	ZZ_p::init(p);
  cout << "Enter generator : " <<endl;
  cin >> g;
  ZZ x;
  string message; 
  cout << "Enter secret key : "<<endl;
  cin >> x;
  cout << "Enter message :" << endl;
  cin >> message;
  encrypt received[message.length()];
  int i;
  long output;
  ZZ_p c;
  for(i = 0; i < message.length(); i++){
    ZZ y = ZZ(RandomBnd(p));
    conv(c,int(message[i]));
    received[i] = a.elgamal_encryption(g,c,x,y);
  }

  cout << "Decrypted message : "<< endl;
  for (i = 0; i < message.length();i++){
    output = a.elgamal_decryption(received[i].text1,received[i].text2,x);
    printf("%ld",output);
  } 
   //*/

  //digital signature------------------------------------------------------------------------------
    //signature creation
  /*
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
	ZZ_p::init(p);
  cout << "Enter generator : " <<endl;
  cin >> g;
	ZZ_p x,y,m;
	cout << "enter secret key(x): "<<endl;
	cin>>x;
	cout<< "enter message: "<<endl;
	cin>>m;
	cout <<"enter some number from group(y): "<<endl;
	cin>>y;
	signature sig =  a.dig_sign(p,g,x,y,m);
	cout <<"gamma: "<<sig.gamma<<" delta: "<<sig.delta<< endl;
    //signature verification
  ZZ_p ::init(p);
  cout << "//verification//"<<endl;
  if(a.dig_signverification(g,x,m,sig.gamma,sig.delta) == 1) 
	  cout<<"digital signature verified"<<endl;
  else
    cout<<"signature not verified"<<endl;
	*/
  return 0;
}           
