//
// Created by Ivan's PC on 6/13/2019.
//
#include <stdio.h>
#include "busqueda.h"

int main(){
//    int a[]={1,3,6,8,9,10,12,14};
    int y=4;
    int * x;
    x=&y;
    printf("%d\n",x);
    x+=1;
    printf("%d\n",x);
    int b[2][2]={{2,3},{3,3}};
    int a[]={1,3,6,8,9,10,12,14};
    int n = sizeof(a)/ sizeof(int);
    int i = busqueda_secuencial(7,a,n);
    int j = busqueda_binaria(7,a,n);
    printf("%d\n",i);
    printf("%d\n",j);

    mi_perro puky= {"puky","caniche", 3, 'M'};
    mi_perro jacob= {"jacob","chihuahua", 10, 'M'};
    mi_perro perros[2]={puky, jacob};
    ordenamiento_perro(perros, 2);

}