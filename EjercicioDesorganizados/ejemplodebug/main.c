#include <stdio.h>

char conv_n_letra(float nota_numerica);

int factorial(int n);

int main(){

    float nota_numerica = 3.0;
    int res = factorial(4);
    printf("%d", res);
    return 0;
}

char conv_n_letra(float nota_numerica){
    if (nota_numerica<59.5){
        return 'F';
    }else if (nota_numerica<69.5){
        return 'D';
    }else if (nota_numerica<79.5){
        return 'C';
    }else if (nota_numerica<89.5){
        return 'B';
    }else{
        return 'A';
    }
}

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n*factorial(n-1);
}
