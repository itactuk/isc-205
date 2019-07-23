//
// Created by Ivan's PC on 7/10/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "funciones_archivos.h"
#include "funciones_calculadora.h"
#include <string.h>

void ejemplo_ftell_rewind();
void crea_archivo_y_sobreescribe_si_existe(char *nombre);
void ejemplo_binario();
void imprime_menu();

ESTUDIANTE *agregar_estudiante(ESTUDIANTE *pEstudiante, int i);

int main(int n, char ** args) {
    ejemplo_binario();
    ejemplo_ftell_rewind();
    int i=0;
    char * texto, c;
    int operando1, operando2;
    char operador;

    printf("Cantidad de parametros: %d\n",n);
    puts("COMIENZO PARAMETROS");
    for (int j = 0; j < n; ++j) {
        puts(args[j]);
    }
    puts("FIN PARAMETROS");

    texto = leer_archivo_texto("C:\\tmp\\mis_calculos.hola");

    for (int i = 0; i < texto[i]!='\0'; i+=4) {
        operando1 = texto[i] - '0' ;
        operador = texto[i+1];
        operando2 = texto[i+2] - '0' ;
        printf(
                "%d%c%d=%d\n",
                operando1,
                operador,
                operando2,
                calcula(operando1, operando2, operador)
                );
    }
    free(texto);
    fputs("Puedo usar fputs para escribir en archivo y en stdout\n", stdout);
    char s[100];
    fgets(s, 100, stdin) ;
    fscanf(stdin, "%s", s);
    system("PAUSE");
    return 0;
}

void ejemplo_ftell_rewind(){
    char * nombre = "prueba_rewind.txt";
    crea_archivo_y_sobreescribe_si_existe(nombre);
    FILE * ptr = fopen(nombre, "r");
    char s[100];

    fscanf(ptr, "%s", s);
    printf("%s\n",s );
    printf("%d\n", ftell(ptr));

    fscanf(ptr, "%s", s);
    printf("%s\n",s );
    printf("%d\n", ftell(ptr));

    rewind(ptr); // fseek(ptr, 0, SEEK_SET);
    printf("%d\n", ftell(ptr));
    fscanf(ptr, "%s", s);
    printf("%s\n",s );
    printf("%d\n", ftell(ptr));

    fclose(ptr);
}

void crea_archivo_y_sobreescribe_si_existe(char *nombre){
    if (!guardar_archivo_texto(nombre,"Esto es un ejemplo")){
        char texto_error[200];
        fgets(texto_error, 200, stderr);
        puts("Error leyendo archivo: ");
        puts(texto_error);
    }
}

ESTUDIANTE * get_default_estudiantes(){
    int n = 2;
    ESTUDIANTE * estudiantes = malloc(n* sizeof(ESTUDIANTE));

    estudiantes[0].nombre = malloc(20 * sizeof(char));
    strcpy(estudiantes[0].nombre, "Ivan1");
    estudiantes[0].edad = 22;

    estudiantes[1].nombre = malloc(20 * sizeof(char));
    strcpy(estudiantes[1].nombre, "Josue1");
    estudiantes[1].edad = 23;

    return estudiantes;
}

void ejemplo_binario(){
    ESTUDIANTE * mis_estudiantes = NULL;
    ESTUDIANTE * eTmp;
    int n = 0;
    char archivo[100] = "estudiantes.bin";
    int x, tmp;

    mis_estudiantes = get_default_estudiantes();
    n = 2;

    puts("Mis estudiantes son los mejores\n");
    do {
        imprime_menu();
        scanf("%d", &x);
        printf("\n");
        switch (x){
            case 1:
                mis_estudiantes = agregar_estudiante(mis_estudiantes, n);
                n++;
                break;
            case 2:
                imprimir_estudiantes(mis_estudiantes, n);
                break;
            case 3:
                guardar_archivo_binario(archivo, mis_estudiantes, n);
                break;
            case 4:
                eTmp = mis_estudiantes;
                tmp = n;
                mis_estudiantes = leer_archivo_binario(archivo);
                n = leer_archivo_binario_cantidad_est(archivo);
                free_estudiantes(eTmp, tmp);
                break;
            case 5:
                printf("Nuevo archivo: ");
                scanf("%s", archivo);
                printf("\n");
        }
    }while (x!=6);
}

ESTUDIANTE *agregar_estudiante(ESTUDIANTE *pEstudiante, int i) {
    if (pEstudiante==NULL){
        pEstudiante = (ESTUDIANTE*) calloc(1, sizeof(ESTUDIANTE));
    } else{
        pEstudiante = (ESTUDIANTE*) realloc(pEstudiante, (i+1)* sizeof(ESTUDIANTE));
    }
    pEstudiante[i] = leer_estudiante();
    return pEstudiante;
}

void imprime_menu(){
    printf("Menu: \n");
    printf("1. Agregar estudiante\n");
    printf("2. Imprime listado\n");
    printf("3. Guardar en archivo\n");
    printf("4. Cargar\n");
    printf("5. Cambiar archivo\n");
    printf("6. Salir\n");
    printf("Opcion: ");
}
