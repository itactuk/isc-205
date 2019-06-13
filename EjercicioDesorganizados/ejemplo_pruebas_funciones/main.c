#include <stdio.h>
#include <stdlib.h>
#include "misfunciones.h"

int leeNumero(char mensaje[]);

int main()
{
    int opcion, a, b;
    printf("Hello world!%d\n", maximo(1,2));
    do{
        printf("\nMenu: \n");
        printf("1- Maximo \n");
        printf("2- Suma \n");
        printf("3- Salir \n");
        printf("Digite opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            a = leeNumero("Digite n1: ");
            b = leeNumero("\nDigite n2: ");
            printf("\nEl resultado es: %d", maximo(a, b));
            break;
        case 2:
            a = leeNumero("Digite n1: ");
            b = leeNumero("\nDigite n2: ");
            printf("\nEl resultado es: %d", suma(a, b));
            break;
        case 3:
        break;
        default:
            printf("Opcion invalida. elige orta opcion \n");
        }
    }while (opcion!=3);
    return 0;
}


int leeNumero(char mensaje[]){
    int n;
    printf("%s", mensaje);
    scanf("%d", &n);
    return n;
}
