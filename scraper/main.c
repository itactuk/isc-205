#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contenido_importante_inicio(char contenido []);
int substr(char s1[], char s2[], int poss2);

int main()
{
    char contenido []= "basfduijgda;ga<li class=\"esta\"><nombre>miguel</nombre>\n<nombre>juan</nombre></li>fsdhsdhgh";

    printf("Hello world!\n");
    printf("%d",contenido_importante_inicio(contenido));
    return 0;
}

int contenido_importante_inicio(char contenido []){
    int i = 0;
    char c;
    for(i=0;contenido[i]!='\0';i++){
        c = contenido[i];
        if(substr("<li class=\"esta\">",contenido,i)){
            return i + strlen("<li class=\"esta\">");
        }
    }
}

int substr(char s1[], char s2[], int poss2){
    int i = 0;
    for(i=0;s1[i]!='\0' && s2[i+poss2]!='\0';i++){
        if (s1[i]!=s2[i+poss2]){
            break;
        }
    }
    if (i==strlen(s1)){
        return 1;
    }else{
        return 0;
    }
}
