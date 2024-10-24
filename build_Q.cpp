#include"crypto.h"

point elliptic_curve::build_Q(point pt){
    return this -> scalar_multiplication(pt,this -> secretkey);
}
