#include"crypto.h"

int elliptic_curve::totalbits(ZZ n){
    int count = 0;
    while(n > 0){
        n = n >> 1;
        count++;
    }
    return count;
}


int* elliptic_curve::bit_array(ZZ n,int size){
    int* array = (int*)malloc(sizeof(int)*size);
    int i = 0;
    while(n > 1){
        array[size - 1] = n % 2;
        n = n >> 1;
        size--;
    }
    return array;
}


bool elliptic_curve::check_exist(ZZ_p x){
    return (power(x,((this -> prime)-1)/2)==1)?true:false;
}


point* elliptic_curve::ell_curve_point(int number){
    ZZ_p y,y1;
    int count;
    count = 0;
    point *pnt = (point*)malloc(sizeof(point)*number);
    for (ZZ x = ZZ(0); x < this -> prime && count != number; x++){
        y1 = power(to_ZZ_p(x),3) +this -> a *to_ZZ_p(x)+ this -> b;
        if(this -> check_exist(y1)){
            y = power(y1,((this -> prime+1))/4);
            pnt[count].x = to_ZZ_p(x); 
            pnt[count].y = y;
            pnt[count+1].x = to_ZZ_p(x);
            pnt[count+1].y = (-1)*y;
            count += 2;
        }
    }
    return pnt;
}


point elliptic_curve::point_addition(point pt1,point pt2){
    ZZ_p lambda;
    point pt3;
    if (pt1.x == 0 && pt1.y == 1)
        return pt2;
    if (pt2.x == 0 && pt2.y == 1)
        return pt1;
    if (pt1.x != pt2.x || pt1.y != pt2.y){
        if(pt1.x == pt2.x){
            pt3.x = 0;
            pt3.y = 1;
            return pt3;
        }
        lambda = (pt2.y - pt1.y)* inv(pt2.x - pt1.x);
    }
    else 
        lambda = ((to_ZZ_p(3)*power(pt1.x,2))+ this->a)*inv(to_ZZ_p(2)*pt1.y);
    
    pt3.x = power(lambda,2)- pt1.x -pt2.x;
    pt3.y = (lambda *(pt1.x - pt3.x))-pt1.y;
    return pt3;
}


point elliptic_curve::scalar_multiplication(point pt,ZZ m){
    int size = this -> totalbits(m)-1;
    int* arr = this -> bit_array(m,size);
    point pnt;
    pnt = pt;
    for (int i = 0; i < size; i++){
        if(arr[i] == 1){
            pnt = this -> point_addition(pnt,pnt);
            pnt = this -> point_addition(pt,pnt);
        }
        else {
            pnt = this -> point_addition(pnt,pnt);
        }
    }
    return pnt;
}


ZZ_p elliptic_curve::square_and_multiply(point pt){
    ZZ y1 =conv<ZZ>(pt.y);
    int size = this -> totalbits(y1)-1;
    int* arr = this -> bit_array(y1,size);
    ZZ_p result;
    result = pt.x;
    for (int i = 0; i < size; i++){
        if(arr[i] == 1){
            result = result * result;
            result = pt.x * result;
        }
        else{
            result = result * result;
        }
    }
    return result;
}


two_pnt elliptic_curve::el_gamal_encrypt(point pt1,point m){
    two_pnt result;
    ZZ y = RandomBnd(this -> prime -1);  
    cout <<"randx: " <<this -> secretkey <<endl;
    cout <<"randy: " <<y <<endl;
    point pt2 = this -> build_Q(pt1);
    result.a = this -> scalar_multiplication(pt1,y);
    result.b = this -> point_addition(m,this -> scalar_multiplication(pt2,y));
    return result;
}

point elliptic_curve::el_gamal_decrypt(point c1,point c2){
  c1.y = -c1.y;
  c1 = this -> scalar_multiplication(c1,this -> secretkey);
  return this -> point_addition(c2,c1); 
}




