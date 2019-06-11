#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

// ENTRADAS:
// s1 = "Hola"
// SALIDA: "aloH"

void invierte(char s[]){
    int n = cant_chars(s);
    int tmp;
    for(int i=0; i<n/2; i++){
        int i_final = n-1-i;
        tmp = s[i];
        s[i] = s[i_final];
        s[i_final] = tmp;
    }
}

int palidromo(char s[]){
    int n = cant_chars(s);
    for(int i=0; i<n; i++){
        int i_final = n-1-i;
        if (s[i]!= s[i_final]){
            return 0;
        }
    }
    return 1;
}


int cant_chars(char s[]){
    int c = 0;
    while(s[c]!='\0'){
        c++;
    }
    return c;
}
