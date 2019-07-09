//
// Created by Ivan's PC on 7/7/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double * d_menor(double * arr, int n);

struct carpeta {
    char nombre[20];
    int fecha_modificacion;
    char usuario[20];
    struct carpeta * carpetas;
    int n_carpetas;
};
typedef struct carpeta CARPETA;


int compara_carpetas(const void *, const void *);

int main() {
    CARPETA arreglo[50];
    int (*prt_compara_carpetas)(const void *, const void *);
    prt_compara_carpetas = compara_carpetas;
    qsort(arreglo, 50, sizeof(CARPETA), prt_compara_carpetas);

    double arr[3] = {5,2,4};
    int n =3;
    printf("%f", *d_menor(arr, n));

    return 0;
}

int compara_carpetas(const void * p1, const void * p2){
    CARPETA * c1 = (CARPETA *) p1;
    CARPETA * c2 = (CARPETA *) p2;
    return strcmp(c1->nombre, c2->nombre);
}

CARPETA * busqueda(char * nombre, CARPETA carpeta_actual){
    if (strcmp(nombre,carpeta_actual.nombre)){
        return &carpeta_actual;
    }
    if (carpeta_actual.n_carpetas==0){
        return NULL;
    }
    for (int i = 0; i < carpeta_actual.n_carpetas; ++i) {
        CARPETA * resultado_carpeta = busqueda(nombre, carpeta_actual.carpetas[i]);
        if (resultado_carpeta!=NULL){
            return resultado_carpeta;
        }
    }
    return NULL;
}

struct boton{
    char * rotulo;
    int codigo;
};
void imprime_boton(struct boton * btn){
    printf("%s\n", btn->rotulo);
    printf("%s\n", (*btn).rotulo);
    printf("%s\n", btn[0].rotulo);
    printf("%d\n", btn->codigo);
}

double * d_menor(double * arr, int n){
    double * aux = arr;
    for (int i = 0; i < n; ++i) {
        if (*(arr+i)<*aux){
            aux= arr + i;
        }
    }
    return aux;
}