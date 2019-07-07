//
// Created by Ivan's PC on 7/4/2019.
//
#include <stdio.h>

#define GENERACION_Z 1
#define GENERACION_X 2

float promedio_edades(int edades[], int n);
int determinar_edad(int d, int m, int a);
int determinar_generacion(float edad);

int main() {
    int n;
    printf("Cantidad:");
    scanf("%d", &n);
    int d[n], m[n], a[n], e[n];
    float prom;
    for (int i = 0; i < n; ++i) {
        printf("a %d=", i);
        scanf("%d", &a[i]);
        printf("\n");
        printf("m %d=", i);
        scanf("%d", &m[i]);
        printf("\n");
        printf("d %d=", i);
        scanf("%d", &d[i]);
        printf("\n");
        e[i]=determinar_edad(d[i],m[i],a[i]);
    }
    prom = promedio_edades(e, n);
    int gen = determinar_generacion(prom);
    if (gen==GENERACION_X){
        printf("Generacion X es la promedio");
    } else if(gen==GENERACION_Z){
        printf("Generacion Z es la promedio");
    }
    return 0;
}

float promedio_edades(int edades[], int n){
    int a=0;
    for (int i = 0; i < n; ++i) {
        a+=edades[i];
    }
    return a/(float)n;
}
int determinar_edad(int d, int m, int a){
    int ed = 2019- a;
    if (d==31 && m==12){
        ed--;
    }
    return ed;
}
int determinar_generacion(float edad_promedio){
    float ano=2019-edad_promedio;
    if (ano>=1994&& ano<=2010){
        return GENERACION_Z;
    }else if (ano>=1981&& ano<=1993){
        return GENERACION_X;
    }
}