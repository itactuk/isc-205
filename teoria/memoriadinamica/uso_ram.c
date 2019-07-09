//
// Created by Ivan's PC on 7/7/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int kbytes=0;
    long incrementos = 100000;
    void * ptr;
    while (1){
        for (int i = 0; i < 1000; ++i) {
            kbytes+=incrementos;
            printf(" - %x\n",calloc(incrementos*1000, sizeof(char)));
        }
        sleep(1);
    }
    return 0;
}