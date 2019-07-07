//
// Created by Ivan's PC on 7/4/2019.
//

#include <stdio.h>

float  g(int n);

int main() {

    return 0;
}

float  g(int n){
    if (n==1) return 1.4;
    if (n<1) return -1;
    return g(n-1)-0.4;
}