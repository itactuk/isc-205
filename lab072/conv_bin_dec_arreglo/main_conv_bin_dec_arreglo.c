//
// Created by Ivan's PC on 6/13/2019.
//
#include <stdio.h>
#include "conv_bin_dec_con_arreglo.h"

int main(){
    int arreglo[] = {1,1,0,1};
    int n = sizeof(arreglo)/ sizeof(int);
    printf("%d", conv(arreglo, n));
}
