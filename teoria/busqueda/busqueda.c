//
// Created by Ivan's PC on 6/13/2019.
//

#include "busqueda.h"

int busqueda_secuencial(int e, int arr[], int n){
    for (int i = 0; i < n; ++i) {
        if (arr[i]==e){
            return i;
        }
    }
    return -1;
}

int busqueda_binaria(int e, int arr[], int n){
    int dcha = n-1;
    int izq = 0;
    int m;

    while (izq<=dcha){
        m = izq + ((dcha-izq)/2);
        if (arr[m]>e){
            dcha = m-1;
        } else if (arr[m]<e){
            izq = m+1;
        } else{
            return m;
        }
    }
    return -1;
}

int busqueda_perro(int e, mi_perro arr[], int n){
    int dcha = n-1;
    int izq = 0;
    int m;

    while (izq<=dcha){
        m = izq + ((dcha-izq)/2);
        if (arr[m].edad>e){
            dcha = m-1;
        } else if (arr[m].edad<e){
            izq = m+1;
        } else{
            return m;
        }
    }
    return -1;
}

int ordenamiento_perro(int e, mi_perro arr[], int n){

}