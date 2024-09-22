#include"crypto.h"
signature cryptoAlgo::dig_sign(ZZ p,ZZ_p g,ZZ_p skey,ZZ_p randomy,ZZ_p m,ZZ_p gamma,ZZ_p delta){
	p = conv<ZZ>(p);
	ZZ_p::init(p);
	//ZZ x;
	/*ZZ_p x,y,m;
	ZZ_p gamma,delta;
	cout << "enter secret key(x): "<<endl;
	cin>>x;
	cout<< "enter message: "<<endl;
	cin>>m;
	cout <<"enter some number from group(y): "<<endl;
	cin>>y;*/
  signature output;
	//signature creation
	power(h,g,rep(skey));
	power(gamma,g,rep(randomy));
	p = p - 1;
	ZZ_p :: init(p);
	randomy = inv(randomy);
	delta = (m - (skey * gamma));
	delta = delta*randomy;
	output.gamma = gamma;
	output.delta = delta;
//	cout << "Signature(gamma,delta)-> "<< gamma<<","<<delta<<endl;
	return output;
	/*//verification
	p = p+1;
	ZZ_p ::init(p);
	cout <<"Verification"<<endl;
	h = power(h,rep(gamma));
	gamma = power(gamma,rep(delta));
	gamma = h * gamma;
	cout << gamma << endl;
	g = power(g,rep(m)); 
	cout << g << endl;
	if (gamma == g){
		cout<<"digital signature verified"<<endl;
		return true;
	}
	return false; */
}
	


	
