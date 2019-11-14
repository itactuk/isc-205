//
// Created by Ivan's PC on 11/14/2019.
//

#ifndef ISC205_ESTUDIANTES_H
#define ISC205_ESTUDIANTES_H

typedef struct evaluacion
{
    char nombre[20];
    int ponderacion;
    int calificacion_obtenida;

} EVALUACION;
typedef struct asignatura
{
    char nombre[20];
    int n_eva;
    evaluacion eva[10];
    int creditos;
} ASIGNATURA;
typedef struct estudiante
{
    char matricula[9];
    int edad;
    char * nombre;
    float promedio;
    asignatura mat[10];
    int n_mats;
} ESTUDIANTE;

int existeEstudiante(ESTUDIANTE *,int n, char *mat);
ESTUDIANTE * eliminarEstudiante(ESTUDIANTE *, int n, int ind);
ESTUDIANTE * agregarEstudiante(ESTUDIANTE *, int n, int ind);
ESTUDIANTE * guardarEstudiantes(ESTUDIANTE *, int n, char * nombre_archivo);
ESTUDIANTE * cargarEstudiantes(char * nombre_archivo);
int calcular_indice(ESTUDIANTE est);

#endif //ISC205_ESTUDIANTES_H
