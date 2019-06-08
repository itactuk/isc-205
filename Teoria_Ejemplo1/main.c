#include <stdio.h>

char conv_n_letra(float nota_numerica);

int main(){
    float n = 2.0;
    int nn = 2;

    char c;
    float nota_numerica = 3.0;
    c = conv_n_letra(nota_numerica);

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

