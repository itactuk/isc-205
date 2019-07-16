//
// Created by Ivan's PC on 7/16/2019.
//

#include <stdio.h>
#include <stdlib.h>

char * leer();
char *** matriz_3d(int m, int n, int k);
typedef struct {
    char * nombre;
}perro;

typedef struct {
    char * nombre;
    int matricula;
    perro * mis_perros;
    int n_perros;
} estudiante;

perro *leer_perros(int n);
estudiante * leer_estudiantes_gregory_style(int n);


estudiante * leer_estudiantes(int n){
    estudiante * mis_estudiantes = (estudiante *) calloc(n, sizeof(estudiante));
    for (int i = 0; i < n; ++i) {
        printf("Digite nombre estudiante: ");
        mis_estudiantes[i].nombre = leer();
//        (mis_estudiantes+i)->nombre = leer();
//        ((*(mis_estudiantes+i)).nombre) = leer();
        printf("\n");
        printf("Digite matricula estudiante: ");
        scanf("%d", &mis_estudiantes[i].matricula);
        printf("\n");
        printf("Digite cantidad de perros: ");
        scanf("%d", &mis_estudiantes[i].n_perros);
        printf("\n");
        for (int j = 0; j < mis_estudiantes[i].n_perros; ++j) {
            mis_estudiantes[i].mis_perros = leer_perros(mis_estudiantes[i].n_perros);
        }
    }
}

estudiante * leer_estudiantes_gregory_style(int n){
    estudiante * mis_estudiantes = (estudiante *) calloc(n, sizeof(estudiante));
    for (int i = 0; i < n; ++i) {
        printf("Digite nombre estudiante: ");
        mis_estudiantes[i].nombre = leer();
//        (mis_estudiantes+i)->nombre = leer();
//        ((*(mis_estudiantes+i)).nombre) = leer();
        printf("\n");
        printf("Digite matricula estudiante: ");
        scanf("%d", &mis_estudiantes[i].matricula);
        printf("\n");
        printf("Digite cantidad de perros: ");
        scanf("%d", &mis_estudiantes[i].n_perros);
        printf("\n");
        for (int j = 0; j < mis_estudiantes[i].n_perros; ++j) {
            printf("Digite nombre:");
            mis_estudiantes[i].mis_perros[i].nombre = leer();
            (((mis_estudiantes+i)->mis_perros)+i)->nombre = leer();
            printf("\n");
        }
    }
}


perro *leer_perros(int n) {
    perro * p = (perro*) malloc(n* sizeof(perro));
    for (int i = 0; i < n; ++i) {
        printf("Digite nombre perro:");
        p[i].nombre = leer();
        printf("\n");
    }
    return p;
}

int main() {
    char ** matriz;
    int m,n;
    printf("Digite el tamano de la matriz(m,n):");
    scanf("%d,%d", &m, &n);

    matriz = (char **) malloc(m * sizeof(char *));

    for (int i = 0; i < m; ++i) {
        matriz[i] = (char *) malloc(n * sizeof(char));
//        *(matriz+i) = (char *) malloc(n * sizeof(char));
    }

    return 0;
}


char *** matriz_3d(int m, int n, int k){
    char *** matriz = (char ***) malloc(m* sizeof(char**));
    for (int i = 0; i < m; ++i) {
        matriz[i] = (char **) malloc(n* sizeof(char *));
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = (char *) malloc(k * sizeof(char));
        }
    }
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


