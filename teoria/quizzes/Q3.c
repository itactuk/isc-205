//
// Created by Ivan's PC on 7/10/2019.
//

#include <stdio.h>

int main() {
    int x = 2, p = 1, k = 1;
    printf("P1:\n");
    for (int i = 0; i < 3; i++) { printf("%o\n", i); }
    printf("P2:\n");
    for (int i = 0; i < 3; i++) { printf("%o\n", x); }
    printf("P3:\n");
    for (int i = 0; i < 3; i++) { printf("%x\n", i++); }
    printf("P4:\n");
    for (int j = 1; j < 5; j += 2) { printf("%d\n", j); }
    printf("P5:\n");
    do { printf("ok\n"); } while (k < 1);
    printf("P6:\n");
    while (k < 1) { printf("ok\n"); }
    printf("P7:\n");
    while (k < 3) {
        printf("ok\n");
        k++;
    }
    printf("P8:\n");
    do {
        printf("%d\n", k);
        k += 2;
    } while (k < 7);
    printf("P9:\n");
    do {
        printf("%d\n", k);
        k--;
    } while (k >= 5);
    printf("P10:\n");
    if (x >= 1 && x <= 3) { printf("Si\n"); }
    else {
        printf("No\n");
    }
    //Continua arriba a la derecha 
    printf("P11:\n");
    if (x < 1 || x > 3) { printf("Si\n"); } else { printf("No\n"); }
    printf("P12:\n");
    if (x < 1 || x > 3) { printf("if\n"); }
    else if (3) {
        printf("else if\n");
        printf("ok\n");
    } else if (4) { printf("if4\n"); } else { printf("else\n"); }
    printf("P13:\n");
    if (x < 1 || x > 3) { printf("if\n"); }
    else if (3) {
        printf("else if\n");
        printf("ok\n");
    }
    if (4) { printf("if4\n"); } else { printf("else\n"); }
    printf("P14:\n");
    for (int i = 0; i < 4; i++) { if (i % 2 == 0) { printf("%d\n", i); }}
    printf("P15:\n");
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) { continue; }
        printf("%d\n", i);
    }
    printf("P16:\n");
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 1) { break; }
        printf("%d\n", i);
    } //Continua arriba a la derecha
    printf("P17:\n");
    k = 1;
    while (k < 4) {
        printf("%d\n", k);
        if (k > 2) { break; }
        k++;
    }
    printf("P18:\n");
    k = 1;
    while (k < 4) {
        printf("%d\n", k);
        if (k == 2) {
            k += 2;
            continue;
        }
        k++;
    }
    return 0;
}