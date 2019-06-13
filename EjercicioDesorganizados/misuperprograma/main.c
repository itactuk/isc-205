#include <stdio.h>
#include <stdlib.h>
#include "milibreria.h"

int leerEntero(char mensaje[]);

int main()
{
    int opcion, a, b;
    do{
        printf("Menu:\n");
        printf("1- Mayor\n");
        printf("2- Suma\n");
        printf("3- Salir\n");
        printf("Digite opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
        case 1:
            a = leerEntero("Digite un numero: ");
            b = leerEntero("\nDigite otro numero: ");
            printf("El resultado es %d\n", maximo(a, b));
            break;
        case 2:
            a = leerEntero("Digite un numero: ");
            b = leerEntero("\nDigite otro numero: ");
            printf("El resultado es %d\n", suma(a, b));
            break;
        case 3:
            break;
        default:
            printf("Opcion no valida. Por favor, digite otra.\n");
        }

    }while(opcion!=3);
    return 0;
}

int leerEntero(char mensaje[]){
    int res;
    printf("%s", mensaje);
    scanf("%d", &res);
    return res;
}
