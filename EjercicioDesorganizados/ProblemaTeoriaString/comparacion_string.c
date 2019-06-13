#include "../minunit_ProblemaTeoriaString/minunit.h"

int compara(char s1[], int n1, char s2[], int n2){
    int n, dif=0,i;
    n = n1>n2 ? n1 : n2;
    for(i=0; i<n; i++){
        if (s1[i]!=s2[i]){
            dif++;
        }
    }
    return dif;
}
