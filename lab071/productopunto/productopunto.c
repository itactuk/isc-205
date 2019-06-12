//
// Created by Ivan's PC on 6/12/2019.
//

#include "productopunto.h"

float producto_punto(float a[], float b[], int n){
    float acc;
    for (int i = 0; i < n; ++i) {
        acc += a[i] * b[i];
    }
    return acc;
}