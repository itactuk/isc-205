//
// Created by Ivan's PC on 7/4/2019.
//

#include <stdio.h>
#include <math.h>
float  des_v_v0_t(float v, float v0, float t);
float  des_v_a_t(float v, float a, float t);

int main() {
    float v, v0, t, a;
    int opcion;
    printf("1. vv0t\n");
    printf("2. av0t\n");
    printf("Opcion\n");
    scanf("%d", &opcion);
    switch (opcion){
        case 1:
            printf("v:");
            scanf("%f", &v);
            printf("\n");
            printf("v0:");
            scanf("%f", &v0);
            printf("\n");
            printf("t:");
            scanf("%f", &t);
            printf("\n");

            printf("x=%f", des_v_v0_t(v,v0,t));
        case 2:
            printf("a:");
            scanf("%f", &a);
            printf("\n");
            printf("v0:");
            scanf("%f", &v0);
            printf("\n");
            printf("t:");
            scanf("%f", &t);
            printf("\n");
            printf("x=%f", des_v_a_t(v,a,t));
    }
    return 0;
}

float  des_v_v0_t(float v, float v0, float t){
    return t*(v+v0)/2;
}
float  des_v_a_t(float v, float a, float t){
    return v*t+a*pow(t,2)/2;
}