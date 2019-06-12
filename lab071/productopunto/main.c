//
// Created by Ivan's PC on 6/12/2019.
//
#include <stdio.h>
#include "productopunto.h"

int main(){
    float a[] = {3.0, 34.0, 12.0, 2.0};
    float b[] = {1.0, 23.0, 11.0, 1.0};
    int n = sizeof(a)/ sizeof(float);
    printf("El tamano es: %d\n", n);
    printf("El producto punto es: %f", producto_punto(a,b, n));

}
