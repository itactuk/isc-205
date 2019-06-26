//
// Created by Ivan's PC on 6/25/2019.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int muestra(int matriz[90][90], int n, int m);
int inicializa(int matriz[90][90], int n, int m);
int gano(int matriz[90][90], int n, int m, int bombas);
int termino(int matriz[90][90], int n, int m, int bombas);
int click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j);
void explosion(int matriz[90][90], int n, int m, int i, int j);
int generar_bombas(int matriz[90][90], int n, int m, int bomba);

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int matriz_valores[90][90];
    int matriz_visual[90][90];
    int col, filas, bombas,i,j;
//    scanf("%d %d %d", &col, &filas, &bombas);
col=6;
filas=6;
bombas=2;
    inicializa(matriz_valores, col, filas);
    inicializa(matriz_visual, col, filas);
    generar_bombas(matriz_valores,col,filas,bombas);
    do{
        system("CLS");
        muestra(matriz_visual,col,filas);
        scanf("%d %d", &i, &j);
        click(matriz_visual,matriz_valores, col,filas, i,j);
    }while (termino(matriz_visual, col, filas, bombas));
    return 0;
}

int generar_bombas(int matriz[90][90], int n, int m, int bomba){
    int aleatorio_i, aleatorio_j;
    while (bomba==0){
        aleatorio_i = rand() % n;
        aleatorio_j = rand() % m;
        if (matriz[aleatorio_i][aleatorio_j]!='b'){
            matriz[aleatorio_i][aleatorio_j]='b';
            bomba--;
        }
    }
}

int muestra(int matriz[90][90], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}

int inicializa(int matriz[90][90], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matriz[i][j]='#';
        }
    }
}

int termino(int matriz[90][90], int n, int m, int bombas){

}
int click(int matriz_visual[90][90], int matriz_valores[90][90], int n, int m, int i, int j){

}