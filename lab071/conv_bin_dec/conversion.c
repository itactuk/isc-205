//
// Created by Ivan's PC on 6/12/2019.
//

#include "conversion.h"
#include <math.h>

int conv(int x){
    if (x==0 || x ==1){
        return x;
    }
    int n= cuenta_digitos(x);
    int resta = (x/pow(10,n-1));
    resta *= pow(10,n-1);
    int r = pow(2,n-1) + conv( x - resta );
    return r;
}

int cuenta_digitos(int x){
    int i = 0;
    while (x!=0){
        x/=10;
        i++;
    }
    return i;
}