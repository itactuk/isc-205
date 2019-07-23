#include "funciones_calculadora.h"

int calcula(int a, int b, char o){
    switch (o){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return -1;
}