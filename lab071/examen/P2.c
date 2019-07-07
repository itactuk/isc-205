//
// Created by Ivan's PC on 7/3/2019.
//

#include <stdio.h>

int main() {

    return 0;
}

int h(int n){
    if (n==1){
        return 1;
    }
    return 2 * h(n-1) + 1;
}