//
// Created by Ivan's PC on 7/7/2019.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char * nombre;
    char * apellido;
    int nota;
} ESTUDIANTE;

int compara_ascendente(const void * pe1, const void * pe2);
int compara_descendente(const void * pe1, const void * pe2);

// Asumir lo siguiente:
// Asumir que la direccion del arreglo(estudiantes) es 6421952
// Asumir que la direccion de est_maria es 6422048
// Asumir que la direccion de est_miguel es 6422016
// Asumir que una estructura estudiante ocupa 32 bytes

int main() {
    int (*compara)(const void *,const void *);
    ESTUDIANTE est_maria;
    est_maria.matricula = 20171707;
    est_maria.nombre = "Maria";
    est_maria.apellido = "Castillo";
    est_maria.nota = 97;
    ESTUDIANTE est_miguel = {20180818, "Miguel", "Perez", 98};
    ESTUDIANTE estudiantes[2] = {est_maria, est_miguel};
    ESTUDIANTE * ptre = estudiantes;

    printf("%d\n", ptre);
    printf("%d\n", estudiantes);
    printf("%d\n", &est_maria);
    printf("%d\n", &est_miguel);
    printf("%d\n", sizeof(ESTUDIANTE));

    puts(ptre->nombre);
    puts((ptre+1)->nombre);
    puts(ptre[1].nombre);
    puts((*(ptre+1)).nombre);
    printf("%d\n", ptre + 1);

    ptre++;
    printf("%s\n", ptre->nombre);
    printf("%s\n", ptre[0].nombre);

    ptre = &est_miguel;
    printf("%s\n", ptre->nombre);
    printf("%d\n", ptre + 1);

    compara = compara_ascendente;
    qsort(estudiantes, sizeof(estudiantes)/ sizeof(ESTUDIANTE), sizeof(ESTUDIANTE),compara);

    printf("%s\n", estudiantes[0].nombre);

    compara = compara_descendente;
    qsort(estudiantes, sizeof(estudiantes)/ sizeof(ESTUDIANTE), sizeof(ESTUDIANTE),compara);

    printf("%s\n", estudiantes[0].nombre);

    return 0;
}

int compara_ascendente(const void * pe1, const void * pe2){
    ESTUDIANTE e1 = *((ESTUDIANTE*)pe1);
    ESTUDIANTE e2 = *((ESTUDIANTE*)pe2);
    return e1.matricula - e2.matricula;
}

int compara_descendente(const void * pe1, const void * pe2){
    ESTUDIANTE e1 = *((ESTUDIANTE*)pe1);
    ESTUDIANTE e2 = *((ESTUDIANTE*)pe2);
    return e2.matricula - e1.matricula;
}