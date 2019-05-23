#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Rata			5 feb 1924	24 ene 1925
    Buey			25 ene 1925	12 feb 1926
    Tigre			13 feb 1926	1 feb 1927
    */
    int dia, mes, ano;
    printf("Digite dia: ");
    scanf("%d", &dia);
    printf("Digite mes: ");
    scanf("%d", &mes);
    printf("Digite a%co: ", 164);
    scanf("%d", &ano);

    if (
        (ano == 1924 &&(mes>2||(mes==2 && dia>=5)))
        ||
        (ano == 1925 &&(mes==1 && dia<=24))
    )
    {
        printf("Rata");
    }
    else if (
        (ano == 1925 &&(mes>1||(mes==1 && dia>=25)))
        ||
        (ano == 1926 &&(mes<2||mes==2 && dia<=12))
    )
    {
        printf("Buey");
    }
    else if (
        (ano == 1926 &&(mes>2||(mes==2 && dia>=13)))
        ||
        (ano == 1927 &&(mes<2||mes==2 && dia<=1))
    )
    {
        printf("Tigre");
    }
    else
    {
        printf("No ha sido implementado");
    }
    return 0;
}
