//
// Created by Ivan's PC on 7/3/2019.
//

#include <stdio.h>
float calc_serie(float r1, float r2);
float calc_paralelo(float r1, float r2);

int main() {
    int opcion;
    float res, r1, r2;
    do{
        printf("1. Serie\n");
        printf("2. Paralelo\n");
        printf("3. Salir\n");
        printf("Opcion:");
        scanf("%d", &opcion);
        printf("\n");
        if (opcion==1 || opcion==2){
            printf("R1:");
            scanf("%d", &r1);
            printf("R2:");
            scanf("%d", &r2);
        }
        if (opcion==1){
            res=calc_serie(r1, r2);
        } else if (opcion==2){
            res=calc_paralelo(r1, r2);
        }
        if (opcion==1 || opcion==2){
            printf("Req es: %f", res);
        }
    }while (opcion!=3);
    return 0;
}

float calc_serie(float r1, float r2){
    return r1 + r2;
}
float calc_paralelo(float r1, float r2){
    return (r1*r2)/(r1 + r2);
}