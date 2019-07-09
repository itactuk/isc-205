//
// Created by Ivan's PC on 7/9/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char c, *prt;
    int i=0;
    prt = (char *) malloc(1 * sizeof(char));
    *prt = '\0';
    while ((c=getch())!='\r'){
        printf("%c",'*');
        prt = (char*) realloc(prt, (i+2)*sizeof(char));
        prt[i++] = c;
        prt[i]='\0';
    }
    puts(prt);
    system("PAUSE");
    return 0;
}