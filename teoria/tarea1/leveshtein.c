//
// Created by Ivan's PC on 6/25/2019.
//


#include "leveshtein.h"
int lev(char a[], char b[], int i, int j){
    if (min(i+1,j+1)==0){
        return max(i+1,j+1);
    }
    int s = a[i] != b[j];
    int v1, v2, v3;
    v1 = lev(a,b,i-1,j) + 1;
    v2 = lev(a,b,i,j-1) + 1;
    v3 = lev(a,b,i-1,j-1) + s;
    return min3(v1, v2, v3);
}


int min( int i, int j){
    if (i<j){
        return i;
    }
    return j;
}
int min3( int i, int j, int k){
    return (min(i, min(j, k)));
}

int max( int i, int j){
    if (i>j){
        return i;
    }
    return j;
}