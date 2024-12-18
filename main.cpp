#include"iostream"
#include"crypto.h"

int main(){

//pollard_rho_factorization-----------------------------------------------------------------------
 // /*   
    ZZ p = ZZ(97);
    p =conv<ZZ>(p);
    ZZ f = power(ZZ(5),34);
    ZZ_p ::init(p);
    AttackAlgo *a = new AttackAlgo(p,to_ZZ_p(5),to_ZZ_p(18));
  cout << "gcd " <<GCD(77,96)<<endl;
    ZZ_p x;
    x = a -> pollard_rho_dlp();
    cout <<"x : "<< x <<endl;
    
  //*/    
//elliptic_curve_points---------------------------------------------------------------------------
/*
    p = 11;
    p =conv<ZZ>(p);
    ZZ_p ::init(p);
    ZZ_p a,b;
    a = 1;
    b = 6;
    point pt1,pt2;
    pt1.x = 2;
    pt1.y = 7;
    pt2.x = 7;
    pt2.y = 2;
    elliptic_curve *c = new elliptic_curve(p,a,b);
    int number,m;
    number = 18;
    point *pnt = c->ell_curve_point(number);
    for(int i = 0; i < number; i++)
       cout <<"x: "<< pnt[i].x <<" y: "<< pnt[i].y <<endl;
  */
//scalar multiplication------------------------------------------------------------------------
   // point resultant = c-> scalar_multiplication(pt1,ZZ(12));
     // cout <<"x: "<< resultant.x <<" y: "<< resultant.y <<endl;
    //point resultant = c-> point_addition(pt1,pt2);
     // cout <<"x: "<< resultant.x <<" y: "<< resultant.y <<endl;
//el gamal----------------------------------------------------------------------------------------
/*   point msg;
    msg.x = 3;
    msg.y = 6;
    two_pnt res = c -> el_gamal_encrypt(pt1,msg);
    //encryption
    cout <<"C1 -      > x: "<< res.a.x <<" C1-> y: "<< res.a.y <<endl;
    cout <<"C2 -> x: "<< res.b.x <<" C2 -> y: "<< res.b.y <<endl;
    //decryption
    msg = c -> el_gamal_decrypt(res.a,res.b);
     cout <<"x: "<< msg.x <<" y: "<< msg.y <<endl;
*/
//integrated scheme------------------------------------------------------------------------------
  //encryption
   /*
     ZZ msg = ZZ(12);
    enc_txt res = c -> integrated_encrypt(pt1,msg);
    cout <<"C1 -> x: "<< res.c1.x <<" C1-> y: "<< res.c1.y <<endl;
    cout <<"C2 : "<< res.c2 <<endl;
   //decryption
    ZZ_p result = c -> integrated_decrypt(res);
    cout << "res : "<<result<<endl;
  */
//digital signature------------------------------------------------------------------------------
 /*     
  // sign creation
    ZZ order = ZZ(13);
    ZZ_p m = to_ZZ_p(4);
    signature res = c -> digital_sign(pt1,order,m);
    cout <<"gamma: "<< res.gamma <<" delta: "<< res.delta <<endl;
    //verification
    cout << c -> digital_sign_verification(res,m,pt1)<<endl;
*/
//RSA---------------------------------------------------------------------------------------------
 /*
  //encryption
    ZZ p = ZZ(41);
    ZZ q = ZZ(19);
    RSA *c = new RSA(p,q);
    ZZ n = c -> given();
    ZZ_p ::init(n);
        cout <<"n -> "<<n<<endl;
    string message ;
    getline(cin,message);
    cout<< "enter message len: "<<message.length()<<endl;
    for(int i = 0; i < message.length(); i++){
        ZZ_p res = c -> RSA_encrypt(to_ZZ_p(int(message[i])));
        printf("%c\n", (char)c -> RSA_decrypt(res));
    }
*/
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
