//
// Created by Ivan's PC on 7/3/2019.
//

#include <stdio.h>

char calificacion_numerica_a_letra(float cal);
float calc_calificacion(float cals[], float pond[], int n);

int main() {
    int n;
    printf("Cantidad evaluaciones: ");
    scanf("%d", &n);
    float calificaciones[n];
    float ponderaciones[n];
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("Calificacion: ");
        scanf("%f", &calificaciones[i]);
        printf("\n");
        printf("Ponderacion: ");
        scanf("%f", &ponderaciones[i]);
        printf("\n");
    }
    printf("La calificacion es: %c",
            calificacion_numerica_a_letra(
                    calc_calificacion(calificaciones,ponderaciones,n)
                    )
            );
    return 0;
}

char calificacion_numerica_a_letra(float cal){
    if (cal>=89.5){
        return 'A';
    }else if (cal>=79.5){
        return 'B';
    }else if (cal>=69.5){
        return 'C';
    }else if (cal>=59.5){
        return 'D';
    }else{
        return 'F';
    }
}

float calc_calificacion(float cals[], float pond[], int n){
    float acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += cals[i] * pond[i];
    }
    return acc;
}












