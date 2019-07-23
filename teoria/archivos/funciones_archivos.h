//
// Created by Ivan's PC on 7/10/2019.
//

#ifndef ISC205_FUNCIONES_ARCHIVOS_H
#define ISC205_FUNCIONES_ARCHIVOS_H

typedef struct estud{
    char * nombre;
    int edad;
}ESTUDIANTE;

char * leer_archivo_texto(char * nombre_archivo);
int guardar_archivo_texto(char * nombre_archivo, char * contenido);
ESTUDIANTE * leer_archivo_binario(char * nombre_archivo);
int guardar_archivo_binario(char * nombre_archivo, ESTUDIANTE * mis_estudiantes, int n_est);
int leer_archivo_binario_cantidad_est(char * nombre_archivo);
void imprimir_estudiantes(ESTUDIANTE * estudiantes, int n);
ESTUDIANTE leer_estudiante();

void free_estudiantes(ESTUDIANTE* estuds, int n);
#endif //ISC205_FUNCIONES_ARCHIVOS_H
