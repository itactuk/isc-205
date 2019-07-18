//
// Created by Ivan's PC on 7/17/2019.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ANCHO 30
#define LARGO 30
#define TIEMPO_RENDER_SEGUNDOS 1.0

void tecla_presionada(char, char ** tablero);
void inicializar_tablero(char *** ptr_tablero);
void dibujar_tablero(char ** tablero);
void mover_x_a_dcha(char ** tablero);
void actualizar_bola();

int main()
{
    char ** mitablero;
    inicializar_tablero(&mitablero);
    char ch;
    double duracion;
    clock_t CPU_tiempo_1 = clock();
    while (1) {

        duracion = (double)(clock()-CPU_tiempo_1)/CLOCKS_PER_SEC;
        if (duracion>TIEMPO_RENDER_SEGUNDOS){
            actualizar_bola();
            CPU_tiempo_1=clock();
        }
        if (kbhit()) {

            // Almacena tecla presionada
            ch = getch();

            // Termina el bucle cuando escape es presionado
            if (ch == 27)
            break;
            tecla_presionada(ch, mitablero);
        }
    }
    return 0;
}

void actualizar_bola(){
    printf("*");
}

void dibujar_tablero(char ** tablero){
    system("CLS");
    for (int i = 0; i < LARGO; ++i) {
        for (int j = 0; j < ANCHO; ++j) {
            printf("%c", tablero[j][i]);
        }
        printf("\n");
    }
}
void tecla_presionada(char tecla, char ** tablero){
    //Aquí deben de mover el punto
    if (tecla=='d'){
        mover_x_a_dcha(tablero);
    }
    dibujar_tablero(tablero);
}

void mover_x_a_dcha(char ** pantalla){
    for (int i = 0; i < ANCHO; ++i) {
        for (int j = 0; j < LARGO; ++j) {
            if (pantalla[i][j]== 'x') {
                pantalla[i][j] = '0';
                pantalla[i+1][j] = 'x';
                return;
            }
        }
    }
}

void inicializar_tablero(char *** ptr_pantalla){
    char ** pantalla;
    pantalla = (char **) malloc(ANCHO* sizeof(char*));
    for (int i = 0; i < ANCHO; ++i) {
        pantalla[i] = (char *) malloc(LARGO* sizeof(char));
        for (int j = 0; j < LARGO; ++j) {
            if (i== ANCHO/2 && j== LARGO/2){
                pantalla[i][j] = 'x';
            } else{
                pantalla[i][j] = '0';
            }
        }
    }
    *ptr_pantalla = pantalla;
}