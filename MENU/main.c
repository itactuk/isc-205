#include <stdio.h>
#include <stdlib.h>
/*
Calcule Indice acumulado
entrar materia
Quitar materia
1 solo estudiante
*/
void calcInd(){}
 void agregarMate(){}
 void quitarMate(){}

int main()
{
    int opcion;
    printf("Hello world!\n");
    do{
            printf("Menu:\n1.Calcular indice\n2.Entrar Materia\n3.Quitar Materia\n4.Salir\nSeleccione opcion: ");
            scanf("%d",&opcion);
            switch(opcion){
            case 1:
                calcInd();
                break;
            case 2:
                agregarMate();
                break;
            case 3:
                quitarMate();
                break;
            case 4:
                break;
            default:
                printf("Opcion invalida\n");
            }
    }while(opcion!=4);
    return 0;
}






