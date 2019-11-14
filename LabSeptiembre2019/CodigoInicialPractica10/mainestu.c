#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre_evaluacion[20];
    float ponderacion;
    float calificacion;
} evaluaciones;

typedef struct
{
    char nombre[20];
    int cant_evalua;
    evaluaciones ev[10];
} asignatura;

typedef struct
{
    int matricula;
    char nombre[20];
    int edad;
    int cant_asig;
    asignatura asig[10];
    float promedio;
} alumno;

void orden_nota(alumno *alumnos,int cont_alum);
int nota_mas_alta (alumno *est, int cont_alum);
float promedio (alumno *est, int cant_al);
void orden_alfebetico(alumno *alumnos,int cont_alum);
void calificacion_asignatura_todos (alumno *alumnos, int cont_alum);
void calificacion_asignatura (alumno *est, int matricula, int cant_al);
int buscar_est_por_mat(int matricula,alumno *est,int n);
int buscar_est_por_nom(char *nombre,alumno *est,int n);

int main()
{
    int cond,matric,nota_alta;
    int cont_alum=0;
    char nombre[20];
    alumno alumnos[10];

    do
    {

        printf("\n\nMenu:\n");
        printf("1- Ingresar estudiantes.\n");
        printf("2- Notas y promedio de un estudiante.\n");
        printf("3- Notas y promedio de todos los estudiantes.\n");
        printf("4- Buscar un estudiante por matricula.\n");
        printf("5- Buscar un estudiante por nombre.\n");
        printf("6- Imprimir el listado de estudiantes ordenado por nombre (orden alfabetico).\n");
        printf("7- Imprimir el listado de estudiantes ordenados por nota.\n");
        printf("8- Imprimir el nombre del estudiante con la nota mas alta.\n");
        printf("9- Salir.\n");
        printf("- Ingresar opcion -: \n");
        scanf("%d",&cond);

        switch(cond)
        {
            case 1:

                printf("\nIngrese el nombre del estudiante: ");
                scanf("%s",&alumnos[cont_alum].nombre);
                printf("\nIngrese la matricula del estudiante: ");
                scanf("%d",&alumnos[cont_alum].matricula);
                printf("\nIngrese la edad del estudiante: ");
                scanf("%d",&alumnos[cont_alum].edad);
                printf("\nIngrese el numero de materias que lleva el estudiante: ");
                scanf("%d",&alumnos[cont_alum].cant_asig);
                int a;
                float pond;
                for (a=0; a<alumnos[cont_alum].cant_asig; a++)
                {
                    printf("\nNombre de la %d asignatura: ",a+1);
                    scanf("%s",&alumnos[cont_alum].asig[a].nombre);
                    printf("\nNumero de evaluaciones de la asignatura: ");
                    scanf("%d",&alumnos[cont_alum].asig[a].cant_evalua);
                    int b;
                    do
                    {
                        pond=0;
                        for (b=0; b<alumnos[cont_alum].asig[a].cant_evalua; b++)
                        {

                            printf("\nNombre de la %d evaluacion: ",b+1);
                            scanf("%s",&alumnos[cont_alum].asig[a].ev[b].nombre_evaluacion);
                            printf("\nValor de la evaluacion (expresado en decimales. Ej: 20%% = 0.20): ");
                            scanf("%f",&alumnos[cont_alum].asig[a].ev[b].ponderacion);
                            pond+=alumnos[cont_alum].asig[a].ev[b].ponderacion;
                            printf("\nCalificacion del alumno: ");
                            scanf("%f",&alumnos[cont_alum].asig[a].ev[b].calificacion);

                        }
                        if (pond<1.0)
                            printf("\nFalta un %.2f%% de ponderaciones. Intentelo de nuevo.",(1.0-pond)*100);
                        if (pond>1.0)
                            printf("\nDemasiadas ponderaciones. Intentelo de nuevo.");
                    }
                    while(pond!=1.0);
                }
                alumnos[cont_alum].promedio=promedio(alumnos,cont_alum);

                cont_alum++;
                break;
            case 2:
                printf("\nIngrese la matricula del estudiante: ");
                scanf("%d",&matric);
                calificacion_asignatura (alumnos, matric, cont_alum);
                break;
            case 3:
                calificacion_asignatura_todos (alumnos, cont_alum);
                break;
            case 4:
                printf("\nIngrese la matricula: ");
                scanf("%d",&matric);
                if(buscar_est_por_mat(matric,alumnos,cont_alum)==(-1))
                {
                    printf("\nEl alumno con dicha matricula no existe.");
                }
                else
                {
                    int o=buscar_est_por_mat(matric,alumnos,cont_alum);
                    printf("\nEl nombre del estudiante es %s",alumnos[o].nombre);
                    printf("\nSu matricula es %d",alumnos[o].matricula);
                    printf("\nSu edad es %d.",alumnos[o].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[o].cant_asig; x++)
                        printf("\n%s",alumnos[o].asig[x].nombre);

                }
                break;
            case 5:
                printf("\nIngrese el nombre: ");
                scanf("%s",&nombre);
                if(buscar_est_por_nom(nombre,alumnos,cont_alum)==(-1))
                {
                    printf("\nEl alumno con dicha matricula no existe.");
                }
                else
                {
                    int u=buscar_est_por_nom(nombre,alumnos,cont_alum);
                    printf("\nEl nombre del estudiante es %s",alumnos[u].nombre);
                    printf("\nSu matricula es %d",alumnos[u].matricula);
                    printf("\nSu edad es %d.",alumnos[u].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int y=0; y<alumnos[u].cant_asig; y++)
                        printf("\n%s",alumnos[u].asig[y].nombre);

                }
                break;
            case 6:
                orden_alfebetico(alumnos,cont_alum);
                for (int e=0; e<cont_alum; e++)
                {
                    printf("\n\nEl nombre del estudiante es %s",alumnos[e].nombre);
                    printf("\nSu matricula es %d",alumnos[e].matricula);
                    printf("\nSu edad es %d.",alumnos[e].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[e].cant_asig; x++)
                        printf("\n%s",alumnos[e].asig[x].nombre);
                }
                break;
            case 7:
                orden_nota(alumnos,cont_alum);
                for (int e=0; e<cont_alum; e++)
                {
                    printf("\n\nEl nombre del estudiante es %s",alumnos[e].nombre);
                    printf("\nSu matricula es %d",alumnos[e].matricula);
                    printf("\nSu edad es %d.",alumnos[e].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[e].cant_asig; x++)
                        printf("\n%s",alumnos[e].asig[x].nombre);
                }
                printf("\nSu nota promedio es %.2f",alumnos[nota_alta].promedio);
                break;
            case 8:
                nota_alta=nota_mas_alta(alumnos,cont_alum);
                printf("\n\nEl nombre del estudiante es %s",alumnos[nota_alta].nombre);
                printf("\nSu matricula es %d",alumnos[nota_alta].matricula);
                printf("\nSu edad es %d.",alumnos[nota_alta].edad);
                printf("\nEsta cursando las asignaturas de: ");
                for (int x=0; x<alumnos[nota_alta].cant_asig; x++)
                {

                    printf("\n%s",alumnos[nota_alta].asig[x].nombre);
                }
                printf("\nSu nota promedio es %.2f",alumnos[nota_alta].promedio);

                break;
        }
    }
    while(cond!=9);

}

int nota_mas_alta (alumno *est, int cont_alum)
{
    int aux;
    int i;
    for (i=0; i<cont_alum-1; i++)
    {
        if(est[i].promedio>est[i+1].promedio)
            aux=i;
        if(est[i+1].promedio>est[i].promedio)
            aux=(i+1);

    }
    return aux;
}

void orden_nota(alumno *alumnos,int cont_alum)
{
    for(int i=0; i<cont_alum; i++)
    {
        for(int j=1; j<cont_alum; j++)
        {
            if(alumnos[j].promedio>alumnos[j-1].promedio)
            {
                alumno aux=alumnos[j];
                alumnos[j]=alumnos[j-1];
                alumnos[j-1]=aux;
            }
        }
    }
}

void orden_alfebetico(alumno *alumnos,int cont_alum)
{
    for(int i=0; i<cont_alum; i++)
    {
        for(int j=1; j<cont_alum; j++)
        {
            if(strcmp(alumnos[j].nombre,alumnos[j-1].nombre)<0)
            {
                alumno aux=alumnos[j];
                alumnos[j]=alumnos[j-1];
                alumnos[j-1]=aux;
            }
            if(strcmp(alumnos[j].nombre,alumnos[j-1].nombre)==0)
            {
                if(alumnos[j].matricula>alumnos[j-1].matricula)
                {
                    alumno aux=alumnos[j];
                    alumnos[j]=alumnos[j-1];
                    alumnos[j-1]=aux;
                }
                if(alumnos[j].matricula<alumnos[j-1].matricula)
                {
                    alumno aux=alumnos[j-1];
                    alumnos[j-1]=alumnos[j];
                    alumnos[j]=aux;
                }
            }
        }
    }
}


void calificacion_asignatura (alumno *est, int matricula, int cant_al)
{
    int s=buscar_est_por_mat(matricula,est,cant_al);
    float prom=0;
    float nota=0;
    for(int i=0; i<est[s].cant_asig; i++)
    {

        for(int j=0; j<est[s].asig[i].cant_evalua; j++)
        {
            nota+=((est[s].asig[i].ev[j].calificacion)*(est[s].asig[i].ev[j].ponderacion));
        }
        printf("\nLa calificacion de %s es %.2f.",est[s].asig[i].nombre,nota);
        prom+=nota;
        nota=0;
    }
    printf("\nEl promedio de sus calificaciones es de %.2f.",((prom)/(est[s].cant_asig)));

}

float promedio (alumno *est, int pos)
{
    float prom=0;
    float nota=0;
    for(int i=0; i<est[pos].cant_asig; i++)
    {

        for(int j=0; j<est[pos].asig[i].cant_evalua; j++)
        {
            nota+=((est[pos].asig[i].ev[j].calificacion)*(est[pos].asig[i].ev[j].ponderacion));
        }
        prom+=nota;
        nota=0;
    }
    return ((prom)/(est[pos].cant_asig));
}

void calificacion_asignatura_todos (alumno *est, int cont_alum)
{
    for(int s=0; s<cont_alum; s++)
    {
        printf("\n\nCalificaciones de %s:",est[s].nombre);
        float prom=0;
        float nota=0;
        for(int i=0; i<est[s].cant_asig; i++)
        {

            for(int j=0; j<est[s].asig[i].cant_evalua; j++)
            {
                nota+=((est[s].asig[i].ev[j].calificacion)*(est[s].asig[i].ev[j].ponderacion));
            }
            printf("\nLa calificacion de %s es %.2f.",est[s].asig[i].nombre,nota);
            prom+=nota;
            nota=0;
        }
        printf("\nEl promedio de sus calificaciones es de %.2f.",((prom)/(est[s].cant_asig)));
    }
}

int buscar_est_por_mat(int matricula,alumno *est,int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if(est[i].matricula==matricula)
        {
            return i;
        }
    }
    return -1;
}

int buscar_est_por_nom(char *nombre,alumno *est,int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if(strcmp(est[i].nombre,nombre)==0)
        {
            return i;
        }
    }
    return -1;
}// ��Sin memoria dinamica aun!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre_evaluacion[20];
    float ponderacion;
    float calificacion;
} evaluaciones;

typedef struct
{
    char nombre[20];
    int cant_evalua;
    evaluaciones ev[10];
} asignatura;

typedef struct
{
    int matricula;
    char nombre[20];
    int edad;
    int cant_asig;
    asignatura asig[10];
    float promedio;
} alumno;
/*
a. Ingresar estudiantes (Nombre, matr�cula, edad, materias en curso).
b. Cada materia en curso debe de tener un nombre y un listado de evaluaciones
c. Cada evaluaci�n debe de tener un nombre, una ponderaci�n y una calificaci�n. No se debe de permitir a�adir m�s de
100% en ponderaciones de evaluaciones por materia.
d. Calcular el promedio de un estudiante
e. Calcular el promedio de todos los estudiantes
f. Calcular la cantidad porcentual que faltan por evaluar
g. Buscar un estudiante por matr�cula
h. Buscar un estudiante por nombre
i. Imprimir el listado de estudiantes ordenado por nombre (orden alfab�tico). Si el nombre es igual debe de ver la
matr�cula para decidir cu�l va primero.
j. Imprimir el listado de estudiantes ordenados por nota
k. Imprimir el nombre del estudiante con la nota m�s alta
*/

void orden_nota(alumno *alumnos,int cont_alum);
int nota_mas_alta (alumno *est, int cont_alum);
float promedio (alumno *est, int cant_al);
void orden_alfebetico(alumno *alumnos,int cont_alum);
void calificacion_asignatura_todos (alumno *alumnos, int cont_alum);
void calificacion_asignatura (alumno *est, int matricula, int cant_al);
int buscar_est_por_mat(int matricula,alumno *est,int n);
int buscar_est_por_nom(char *nombre,alumno *est,int n);

int main()
{
    int cond,matric,nota_alta;
    int cont_alum=0;
    char nombre[20];
    alumno alumnos[10];

    do
    {

        printf("\n\nMenu:\n");
        printf("1- Ingresar estudiantes.\n");
        printf("2- Notas y promedio de un estudiante.\n");
        printf("3- Notas y promedio de todos los estudiantes.\n");
        printf("4- Buscar un estudiante por matricula.\n");
        printf("5- Buscar un estudiante por nombre.\n");
        printf("6- Imprimir el listado de estudiantes ordenado por nombre (orden alfabetico).\n");
        printf("7- Imprimir el listado de estudiantes ordenados por nota.\n");
        printf("8- Imprimir el nombre del estudiante con la nota mas alta.\n");
        printf("9- Salir.\n");
        printf("- Ingresar opcion -: \n");
        scanf("%d",&cond);

        switch(cond)
        {
            case 1:

                printf("\nIngrese el nombre del estudiante: ");
                scanf("%s",&alumnos[cont_alum].nombre);
                printf("\nIngrese la matricula del estudiante: ");
                scanf("%d",&alumnos[cont_alum].matricula);
                printf("\nIngrese la edad del estudiante: ");
                scanf("%d",&alumnos[cont_alum].edad);
                printf("\nIngrese el numero de materias que lleva el estudiante: ");
                scanf("%d",&alumnos[cont_alum].cant_asig);
                int a;
                float pond;
                for (a=0; a<alumnos[cont_alum].cant_asig; a++)
                {
                    printf("\nNombre de la %d asignatura: ",a+1);
                    scanf("%s",&alumnos[cont_alum].asig[a].nombre);
                    printf("\nNumero de evaluaciones de la asignatura: ");
                    scanf("%d",&alumnos[cont_alum].asig[a].cant_evalua);
                    int b;
                    do
                    {
                        pond=0;
                        for (b=0; b<alumnos[cont_alum].asig[a].cant_evalua; b++)
                        {

                            printf("\nNombre de la %d evaluacion: ",b+1);
                            scanf("%s",&alumnos[cont_alum].asig[a].ev[b].nombre_evaluacion);
                            printf("\nValor de la evaluacion (expresado en decimales. Ej: 20%% = 0.20): ");
                            scanf("%f",&alumnos[cont_alum].asig[a].ev[b].ponderacion);
                            pond+=alumnos[cont_alum].asig[a].ev[b].ponderacion;
                            printf("\nCalificacion del alumno: ");
                            scanf("%f",&alumnos[cont_alum].asig[a].ev[b].calificacion);

                        }
                        if (pond<1.0)
                            printf("\nFalta un %.2f%% de ponderaciones. Intentelo de nuevo.",(1.0-pond)*100);
                        if (pond>1.0)
                            printf("\nDemasiadas ponderaciones. Intentelo de nuevo.");
                    }
                    while(pond!=1.0);
                }
                alumnos[cont_alum].promedio=promedio(alumnos,cont_alum);

                cont_alum++;
                break;
            case 2:
                printf("\nIngrese la matricula del estudiante: ");
                scanf("%d",&matric);
                calificacion_asignatura (alumnos, matric, cont_alum);
                break;
            case 3:
                calificacion_asignatura_todos (alumnos, cont_alum);
                break;
            case 4:
                printf("\nIngrese la matricula: ");
                scanf("%d",&matric);
                if(buscar_est_por_mat(matric,alumnos,cont_alum)==(-1))
                {
                    printf("\nEl alumno con dicha matricula no existe.");
                }
                else
                {
                    int o=buscar_est_por_mat(matric,alumnos,cont_alum);
                    printf("\nEl nombre del estudiante es %s",alumnos[o].nombre);
                    printf("\nSu matricula es %d",alumnos[o].matricula);
                    printf("\nSu edad es %d.",alumnos[o].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[o].cant_asig; x++)
                        printf("\n%s",alumnos[o].asig[x].nombre);

                }
                break;
            case 5:
                printf("\nIngrese el nombre: ");
                scanf("%s",&nombre);
                if(buscar_est_por_nom(nombre,alumnos,cont_alum)==(-1))
                {
                    printf("\nEl alumno con dicha matricula no existe.");
                }
                else
                {
                    int u=buscar_est_por_nom(nombre,alumnos,cont_alum);
                    printf("\nEl nombre del estudiante es %s",alumnos[u].nombre);
                    printf("\nSu matricula es %d",alumnos[u].matricula);
                    printf("\nSu edad es %d.",alumnos[u].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int y=0; y<alumnos[u].cant_asig; y++)
                        printf("\n%s",alumnos[u].asig[y].nombre);

                }
                break;
            case 6:
                orden_alfebetico(alumnos,cont_alum);
                for (int e=0; e<cont_alum; e++)
                {
                    printf("\n\nEl nombre del estudiante es %s",alumnos[e].nombre);
                    printf("\nSu matricula es %d",alumnos[e].matricula);
                    printf("\nSu edad es %d.",alumnos[e].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[e].cant_asig; x++)
                        printf("\n%s",alumnos[e].asig[x].nombre);
                }
                break;
            case 7:
                orden_nota(alumnos,cont_alum);
                for (int e=0; e<cont_alum; e++)
                {
                    printf("\n\nEl nombre del estudiante es %s",alumnos[e].nombre);
                    printf("\nSu matricula es %d",alumnos[e].matricula);
                    printf("\nSu edad es %d.",alumnos[e].edad);
                    printf("\nEsta cursando las asignaturas de: ");
                    for (int x=0; x<alumnos[e].cant_asig; x++)
                        printf("\n%s",alumnos[e].asig[x].nombre);
                }
                printf("\nSu nota promedio es %.2f",alumnos[nota_alta].promedio);
                break;
            case 8:
                nota_alta=nota_mas_alta(alumnos,cont_alum);
                printf("\n\nEl nombre del estudiante es %s",alumnos[nota_alta].nombre);
                printf("\nSu matricula es %d",alumnos[nota_alta].matricula);
                printf("\nSu edad es %d.",alumnos[nota_alta].edad);
                printf("\nEsta cursando las asignaturas de: ");
                for (int x=0; x<alumnos[nota_alta].cant_asig; x++)
                {

                    printf("\n%s",alumnos[nota_alta].asig[x].nombre);
                }
                printf("\nSu nota promedio es %.2f",alumnos[nota_alta].promedio);

                break;
        }
    }
    while(cond!=9);

}

int nota_mas_alta (alumno *est, int cont_alum)
{
    int aux;
    int i;
    for (i=0; i<cont_alum-1; i++)
    {
        if(est[i].promedio>est[i+1].promedio)
            aux=i;
        if(est[i+1].promedio>est[i].promedio)
            aux=(i+1);

    }
    return aux;
}

void orden_nota(alumno *alumnos,int cont_alum)
{
    for(int i=0; i<cont_alum; i++)
    {
        for(int j=1; j<cont_alum; j++)
        {
            if(alumnos[j].promedio>alumnos[j-1].promedio)
            {
                alumno aux=alumnos[j];
                alumnos[j]=alumnos[j-1];
                alumnos[j-1]=aux;
            }
        }
    }
}

void orden_alfebetico(alumno *alumnos,int cont_alum)
{
    for(int i=0; i<cont_alum; i++)
    {
        for(int j=1; j<cont_alum; j++)
        {
            if(strcmp(alumnos[j].nombre,alumnos[j-1].nombre)<0)
            {
                alumno aux=alumnos[j];
                alumnos[j]=alumnos[j-1];
                alumnos[j-1]=aux;
            }
            if(strcmp(alumnos[j].nombre,alumnos[j-1].nombre)==0)
            {
                if(alumnos[j].matricula>alumnos[j-1].matricula)
                {
                    alumno aux=alumnos[j];
                    alumnos[j]=alumnos[j-1];
                    alumnos[j-1]=aux;
                }
                if(alumnos[j].matricula<alumnos[j-1].matricula)
                {
                    alumno aux=alumnos[j-1];
                    alumnos[j-1]=alumnos[j];
                    alumnos[j]=aux;
                }
            }
        }
    }
}


void calificacion_asignatura (alumno *est, int matricula, int cant_al)
{
    int s=buscar_est_por_mat(matricula,est,cant_al);
    float prom=0;
    float nota=0;
    for(int i=0; i<est[s].cant_asig; i++)
    {

        for(int j=0; j<est[s].asig[i].cant_evalua; j++)
        {
            nota+=((est[s].asig[i].ev[j].calificacion)*(est[s].asig[i].ev[j].ponderacion));
        }
        printf("\nLa calificacion de %s es %.2f.",est[s].asig[i].nombre,nota);
        prom+=nota;
        nota=0;
    }
    printf("\nEl promedio de sus calificaciones es de %.2f.",((prom)/(est[s].cant_asig)));

}

float promedio (alumno *est, int pos)
{
    float prom=0;
    float nota=0;
    for(int i=0; i<est[pos].cant_asig; i++)
    {

        for(int j=0; j<est[pos].asig[i].cant_evalua; j++)
        {
            nota+=((est[pos].asig[i].ev[j].calificacion)*(est[pos].asig[i].ev[j].ponderacion));
        }
        prom+=nota;
        nota=0;
    }
    return ((prom)/(est[pos].cant_asig));
}

void calificacion_asignatura_todos (alumno *est, int cont_alum)
{
    for(int s=0; s<cont_alum; s++)
    {
        printf("\n\nCalificaciones de %s:",est[s].nombre);
        float prom=0;
        float nota=0;
        for(int i=0; i<est[s].cant_asig; i++)
        {

            for(int j=0; j<est[s].asig[i].cant_evalua; j++)
            {
                nota+=((est[s].asig[i].ev[j].calificacion)*(est[s].asig[i].ev[j].ponderacion));
            }
            printf("\nLa calificacion de %s es %.2f.",est[s].asig[i].nombre,nota);
            prom+=nota;
            nota=0;
        }
        printf("\nEl promedio de sus calificaciones es de %.2f.",((prom)/(est[s].cant_asig)));
    }
}

int buscar_est_por_mat(int matricula,alumno *est,int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if(est[i].matricula==matricula)
        {
            return i;
        }
    }
    return -1;
}

int buscar_est_por_nom(char *nombre,alumno *est,int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if(strcmp(est[i].nombre,nombre)==0)
        {
            return i;
        }
    }
    return -1;
}