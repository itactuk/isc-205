//
// Created by Ivan's PC on 7/10/2019.
//

#include "funciones_archivos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * leer_archivo_texto(char * nombre_archivo){
    FILE * fp;
    char * texto = NULL;
    int i = 0;
    char c;
    fp = fopen("C:\\tmp\\mis_calculos.hola", "r");
    if (fp==NULL){
        fputs("Error abriendo el archivo", stderr);
        return NULL;
    }
    while ((c=fgetc(fp))!=EOF){
        if (texto==NULL){
            texto = (char*) calloc(i+2, sizeof(char));
        } else{
            texto = (char*) realloc(texto, (i+2)* sizeof(char));
        }
        if (texto==NULL){
            fputs("Error reservando memoria para el string", stderr);
            return NULL;
        }
        texto[i++]=c;
    }
    fclose(fp);
    texto[i]='\0';
    return texto;
}
int guardar_archivo_texto(char * nombre_archivo, char * contenido){
    FILE * p;
    p = fopen(contenido, "w");
    if (p==NULL){
        return 0;
    }
    fputs("Esto es un ejemplo", p);
    fclose(p);
    return 1;
}

ESTUDIANTE * leer_archivo_binario(char * nombre_archivo){
    int n_est;
    char buff[200];
    ESTUDIANTE* mis_estudiantes;
    FILE * p = fopen(nombre_archivo, "rb");
    if (p==NULL){
        return NULL;
    }
    fread(&n_est, sizeof(int), 1, p);
    mis_estudiantes = malloc(n_est* sizeof(ESTUDIANTE));
    fread(mis_estudiantes, sizeof(ESTUDIANTE), n_est, p);
    for (int i = 0; i < n_est; ++i) {
        mis_estudiantes[i].nombre = calloc(200, sizeof(char));
        fread(buff, sizeof(char), 200, p);
        strcpy(mis_estudiantes[i].nombre, buff);
    }
    fclose(p);
    return mis_estudiantes;
}
int leer_archivo_binario_cantidad_est(char * nombre_archivo){
    int n_est;
    FILE * p = fopen(nombre_archivo, "rb");
    if (p==NULL){
        return -1;
    }
    fread(&n_est, sizeof(int), 1, p);
    fclose(p);
    return n_est;
}
int guardar_archivo_binario(char * nombre_archivo, ESTUDIANTE * mis_estudiantes, int n_est){
    FILE * p = fopen(nombre_archivo, "wb");
    char buff[200];
    if (p==NULL){
        return 0;
    }
    fwrite(&n_est, sizeof(int), 1, p);
    fwrite(mis_estudiantes, sizeof(ESTUDIANTE), n_est, p);
    for (int i = 0; i < n_est; ++i) {
        strcpy(buff, mis_estudiantes[i].nombre);
        fwrite(buff, sizeof(char), 200, p);
    }
    fclose(p);
    return 1;
}

void imprimir_estudiantes(ESTUDIANTE * estudiantes, int n){
    printf("Imprimiendo %d estudiantes\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("\n");
    }
}

ESTUDIANTE leer_estudiante(){
    ESTUDIANTE e;
    char buff[200];
    printf("Nombre: ");
    scanf("%s", buff);
    e.nombre = malloc(strlen(buff)* sizeof(char));
    strcpy(e.nombre, buff);
    printf("\n");
    printf("Edad: ");
    scanf("%d", &e.edad);
    printf("\n");
    return e;
}

void free_estudiantes(ESTUDIANTE* estuds, int n){
    for (int i = 0; i < n; ++i) {
        free(estuds[i].nombre);
    }
    free(estuds);
}