//
// Created by Ivan's PC on 7/9/2019.
//

/*
 Dada la declaración del array de punteros:
    #define N 4
    char *[N] ;
    Escriba las sentencias de código para leer
    N lineas de caracteres y asignar cada línea a
    un elemento del array


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

char * leer();

int main() {
    char *arr[N] ;
    int j=0;
    for (int i = 0; i < N; ++i) {
        arr[j++] = leer();
        if (strlen(arr[i])<20){
            free(arr[i]);
            j--;
        }
    }
    return 0;
}

char * leer(){
    char c, *prt;
    int i=0;
    prt = (char *) malloc(1 * sizeof(char));
    *prt = '\0';
    while ((c=getchar())!='\n') {
        prt = (char *) realloc(prt, (i + 2) * sizeof(char));
        prt[i++] = c;
        prt[i] = '\0';
    }
    return prt;
}
