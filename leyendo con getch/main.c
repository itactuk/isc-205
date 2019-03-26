#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    char c;
    char * texto;
    texto= malloc( 1 * sizeof(char) );
    int i = 0;
    while( (c = getch())!='\r'){
        texto = realloc( texto, (i+2) * sizeof(char) );
        texto[i]=c;
        printf("%c",c);
        i++;
    }
    //texto[i]='\0';
    printf("Este es mi caracter: %c\n",c);
    printf("%s\n",texto);
    free(texto);
    return 0;
}
