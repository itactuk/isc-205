//
// Created by Ivan's PC on 7/3/2019.
//

#include <stdio.h>
#include <string.h>
#define NULL 0

int strtamano(char s1[]);
int intercambiar(int * v1, int * v2);

int main() {
//    char s1[100] = "Angel";
//    char s2[] = " ,";
//    char s3[] = " como estas?";
//    printf("%s\n", s1);
//    strcat(s1, s2);
//    printf("%s\n", s1);
//    strncat(s1, &s3[3], 3);
//    printf("%s\n", s1);
    int x = 3;
    int y = 4;
    intercambiar(&x, &y);
    printf("%d, %d", x, y);
    return 0;
}

int strtamano(char s1[]){
    int c = 0;
    while (s1[c]!='\0'){
        c++;
    }
    return c;
}

int intercambiar(int * v1, int * v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}



