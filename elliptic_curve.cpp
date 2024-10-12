#include"crypto.h"

point** elliptic_curve::ell_curve_point(int number){
    ZZ_p y,y1;
    int count =0;
    ZZ x;
    point **pnt = (point**)malloc(sizeof(point*)*number);
    for(x = 0; (x < this->prime) && (count < number); x++){
        cout<<count<<endl;
        y1 = power(to_ZZ_p(x),3) +this -> a *to_ZZ_p(x)+ this -> b;
        if(this -> check_exist(y1)){
            pnt[count] =(point*)malloc(sizeof(point));
            y = power(y1,(this -> prime+1)/4);
            pnt[count]->x = y; 
            pnt[count]->y = (-1)*y;
            count++;
        }
    }
    return pnt;
}

bool elliptic_curve::check_exist(ZZ_p x){
    return (power(x,(this -> prime+1)/2)==1)?true:false;
}
