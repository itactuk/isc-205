//
// Created by Ivan's PC on 6/13/2019.
//

#ifndef ISC205_BUSQUEDA_H
#define ISC205_BUSQUEDA_H
int busqueda_secuencial(int e, int arr[], int n);
int busqueda_binaria(int e, int arr[], int n);
typedef struct perros{
    char nombre[30];
    char raza[20];
    int edad;
    char sexo;
} mi_perro;

int busqueda_perro(int e, mi_perro arr[], int n);
int ordenamiento_perro(int e, mi_perro arr[], int n);
#endif //ISC205_BUSQUEDA_H
