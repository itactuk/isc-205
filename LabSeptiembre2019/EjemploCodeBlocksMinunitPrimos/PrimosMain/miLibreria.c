//
// Created by Ivan's PC on 10/3/2019.
//

#include <math.h>
#include "miLibreria.h"

int esprimo(int numero)
{
    int fact,topefact = (int)sqrt(numero);

    for ( fact = 2; fact <= topefact; fact ++ )
        if ( numero % fact == 0 )
            return 0;

    // si el número no tiene factores en el rango [2,topefac].
    return 1;
}

double calc_promedio_numeros_primos(int inicio, int fin){

}
