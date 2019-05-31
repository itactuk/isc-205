#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(char l1='Z'; l1>='A'; l1--){
        for(char l=l1; l>='A'; l--){
            printf("%c",l);
        }
        printf("\n");
    }
    return 0;
}
