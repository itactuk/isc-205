//
// Created by Ivan's PC on 7/11/2019.
//

#include <stdio.h>

typedef struct {
    int matricula;
    char * nombre;
    char * apellido;
    int nota;
} ESTUDIANTE;

void intercambia_nota(ESTUDIANTE * es1, ESTUDIANTE * es2){
    int aux;
    aux = es1->nota;
    es1->nota =es2->nota;
    es2->nota=aux;
}

#include <string.h>
int comparar(ESTUDIANTE a, ESTUDIANTE b){
    if (strcmp(a.nombre,b.nombre)==0){
        return 0;
    }
    return 1;
}

char * nombre_apellido(char * buff, ESTUDIANTE es){
    strcpy(buff,es.nombre);
    strcat(buff, " ");
    strcat(buff, es.apellido);
    return buff;
}

int main() {

    return 0;
}