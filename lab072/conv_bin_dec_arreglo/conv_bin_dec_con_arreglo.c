//
// Created by Ivan's PC on 6/13/2019.
//

#include "conv_bin_dec_con_arreglo.h"
#include "math.h"

int conv(int arr[], int n){
    return i_conv(arr, n, 0);
}

int i_conv(int arr[], int n, int i){
    if (i>=n){
        return 0;
    }
    int r = i_conv(arr, n, i+1);
    return arr[i] * pow(2, n-i-1) + r;
}
