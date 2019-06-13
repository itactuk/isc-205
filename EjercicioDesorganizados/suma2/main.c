#include <stdio.h>
#include <stdlib.h>
#include "mis_acciones.h"

int main()
{
    int x, y;
    printf("%cDigita 2 #s: ", 130);
    scanf("%d", &x);
    scanf("%d", &y);
    printf("La suma es: %d\n", x + y);
    mi_accion();
    return 0;
}
