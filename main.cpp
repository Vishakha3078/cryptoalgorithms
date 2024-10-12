#include"iostream"
#include"crypto.h"
int main(){
    ZZ p;
//point addition---------------------------------------------------------------------------------
///*
    p = 11;
    ZZ_p a;
    a = 1;
    ZZ_p b;
    b = 6;
    elliptic_curve *c = new elliptic_curve(p,a,b);
    point **pt;
    int n,i;
    n = 2;
    pt = c->ell_curve_point(n);
    for(i = 0; i < n;   i++){
        cout << pt[i]->x <<endl;
        cout << pt[i]->y <<endl;
    }
  //   */ 
      
//bruteforce_dlp----------------------------------------------------------------------------------
/*
    cout << "Enter prime : " <<endl;
	  cin >> p;
	  p = conv<ZZ>(p);
    cryptoAlgo *a = new cryptoAlgo(p);
    cout << a->h << endl;
    cout << a->privatekey << endl;
    cout << a->brutef_dlp()<<endl; 
 */ 

//diff_hell---------------------------------------------------------------------------------------
  /*
  cout << "Enter prime : " <<endl;
	cin >> p;
  p = conv<ZZ>(p);
  cryptoAlgo *a = new cryptoAlgo(p);
  //diffhellencryption
    //alice
    ZZ alicekey;
    cout << "Enter secret key of alice: "<<endl;
    cin >> alicekey;
    ZZ_p A = a->diff_hellencryption(alicekey);
    //bob
    ZZ bobkey;
    cout << "Enter secret key of bob: "<<endl;
    cin >> bobkey;
    ZZ_p B = a->diff_hellencryption(bobkey);
  //diffhelldecryption
    //alice
    ZZ_p AA = a->diff_helldecryption(alicekey,B);
    cout << "Key recieved by alice: "<< AA << endl;
    //bob
    ZZ_p BB = a->diff_helldecryption(bobkey,A);
    cout << "Key recieved by bob: "<< BB << endl;
  */
  
//el_gamal----------------------------------------------------------------------------------------
 /*
    cout << "Enter prime : " <<endl;
	  cin >> p;
    p = conv<ZZ>(p);
    cryptoAlgo *a = new cryptoAlgo(p);
    string message; 
    cout << "Enter message :" << endl;
    cin >> message;
    encrypt received;
    ZZ_p msg;
    cout <<"Decrypted message"<<endl;
    for(int i = 0; i < message.length(); i++){
        ZZ y = ZZ(RandomBnd(p));
        conv(msg,int(message[i]));
        received = a->elgamal_encryption(msg,y);
        printf("%c",(char)a->elgamal_decryption(received.text1,received.text2));
    }
  */

//digital signature------------------------------------------------------------------------------
  /*
  //signature creation
  cout << "Enter prime : " <<endl;
	cin >> p;
	p = conv<ZZ>(p);
    cryptoAlgo *a = new cryptoAlgo(p);
	ZZ_p msg;
  string message ;
	cout<< "enter message: "<<endl;
	cin>>message;
  signature sig;
  for(int i = 0; i < message.length(); i++){
    conv(msg,int(message[i]));
	  sig =  a->dig_sign(msg);
	  cout <<"gamma: "<<sig.gamma<<" delta: "<<sig.delta<< endl;
  //signature verification
    ZZ_p ::init(p);
    cout << "//verification//"<<endl;
    if(a->dig_signverification(msg,sig.gamma,sig.delta) == 1) 
	    cout<<"digital signature verified"<<endl;
    else
      cout<<"signature not verified"<<endl;
  }
	*/
  return 0;
}           
