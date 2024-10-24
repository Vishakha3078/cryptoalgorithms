#include"iostream"
#include"crypto.h"

int main(){
    ZZ p;
//elliptic_curve_points---------------------------------------------------------------------------
///*
    p = 11;
    p =conv<ZZ>(p);
    ZZ_p ::init(p);
    ZZ_p a,b;
    a = 1;
    b = 6;
    elliptic_curve *c = new elliptic_curve(p,a,b);
    point *pnt;
    int number,m;
    number = 12;
    pnt = c->ell_curve_point(number);
   // for(int i = 0; i < n; i++)
   //     cout <<"x: "<< pnt[i].x <<" y: "<< pnt[i].y <<endl;
    point pt1,pt2;
    pt1.x = 2;
    pt1.y = 7;
//scalar multiplication------------------------------------------------------------------------
   // point resultant = c-> scalar_multiplication(pt1,ZZ(4));
    //cout <<"x: "<< resultant.x <<" y: "<< resultant.y <<endl;
//el gamal----------------------------------------------------------------------------------------
    point msg;
    msg.x = 3;
    msg.y = 6;
    two_pnt res = c -> el_gamal_encrypt(pt1,msg);
    //encryption
    cout <<"C1 -> x: "<< res.a.x <<" C1-> y: "<< res.a.y <<endl;
    cout <<"C2 -> x: "<< res.b.x <<" C2 -> y: "<< res.b.y <<endl;
    //decryption
    
    msg = c -> el_gamal_decrypt(res.a,res.b);
     cout <<"x: "<< msg.x <<" y: "<< msg.y <<endl;
//*/
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
