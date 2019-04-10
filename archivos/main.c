#include <stdio.h>
#include <stdlib.h>

void guardar(int x);

struct estudiante{
    int matricula;
    char nombre[10];
};
typedef struct estudiante ESTU;

void guardar_estu(ESTU es){
    FILE *file;
    file = fopen("miarchivoestud.bin", "wb");
    if (file == NULL){
        printf("Error abriendo archivo (guardando");
        exit(1);
    }
    fwrite(&es, sizeof(struct estudiante), 1, file);
    fclose(file);
}

struct estudiante leer_estu(){
    struct estudiante es;
    FILE *file;
    file = fopen("miarchivoestud.bin", "rb");
    if (file == NULL){
        printf("Error abriendo archivo (guardando2)");
        exit(1);
    }
    fread(&es, sizeof(struct estudiante), 1, file);
    fclose(file);
    return es;
}

void estudiante_ejemplo(){
    struct estudiante jhan;
    jhan.matricula =20160728;
    int i=0;
    jhan.nombre[i++] = 'c';
    jhan.nombre[i++] = 'a';
    jhan.nombre[i++] = 'r';
    jhan.nombre[i++] = '\0';
    guardar_estu(jhan);
    printf("Matricula: %d", jhan.matricula);
    printf("Nombre: %s\n", jhan.nombre);
    ESTU otro = leer_estu();
    printf("Matricula: %d", otro.matricula);
    printf("Nombre: %s\n", otro.nombre);
    
}

int main()
{
    estudiante_ejemplo();
    printf("Hello world!\n");
    //int x=2;
    //x = leer();
    //printf("X=%d",x);
    //x++;
    //guardar(x);




    return 0;
}

int leer(){
    int x;
    FILE *file;
    file = fopen("miarchivo.bin", "rb");
    if (file == NULL){
        printf("Error abriendo archivo (guardando");
        exit(1);
    }
    fread(&x, sizeof(int), 1, file);
    fclose(file);
    return x;
}

void guardar(int x){
    FILE *file;
    file = fopen("miarchivo.bin", "wb");
    if (file == NULL){
        printf("Error abriendo archivo (guardando");
        exit(1);
    }
    fwrite(&x, sizeof(int), 1, file);
    fclose(file);
}
