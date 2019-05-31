#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcion_con_lib(float x, int n);
float funcion_sin_lib(float x, int n);
float potencia(float x, int n);

int main()
{
    printf("%f\n", funcion_con_lib(3.0,2));
    printf("%f\n", funcion_sin_lib(3.0,2));
    return 0;
}

float funcion_con_lib(float x, int n){
    float res;
    if (x>=0){
        res = x;
        res += (pow(x,n)/n);
        res -= (pow(x,(n+1))/(n+2));
        return res;
    }else{
        res = x + (pow(x,(n+1))/(n+1)) - (pow(x,(n-1))/(n-1));
        return res;
    }
}

float funcion_sin_lib(float x, int n){
    float res;
    if (x>=0){
        res = x + (potencia(x,n)/n) - (potencia(x,(n+1))/(n+2));
        return res;
    }else{
        res = x + (potencia(x,(n+1))/(n+1)) - (potencia(x,(n-1))/(n-1));
        return res;
    }
}

float potencia(float x, int n){
    float res = 1;
    if (n==0) return 1;
    if (n<0) return 1.0/potencia(x, -n);
    for(int i=0; i<n; i++){
        res *= x;
    }
    return res;
}
