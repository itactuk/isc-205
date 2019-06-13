#include <stdio.h>
int main()
{
    // 1   1   1   1  2   1    1   3    3    1    1    4   6   4   1
    // l1  l2  l2  l3 1&2 l3   l4  3&4  4&5  l4   l5   6&7 7&8 8&9 l5
    // 0   1   2   3  4   5    6   7    8    9    10   11  12  13  14
    int lineas, n;
    scanf("%d",&lineas);
    lineas++;
    n = (lineas * (lineas+1))/2;
    int pascal[n];
    pascal[0] = 1;
    pascal[1] = 1;
    pascal[2] = 1;
    int anterior = 1;
    int i = 3, j=1;
    for(int l=3; l<=lineas; l++){
        pascal[i++] = 1;
        for(int k=0; k<l-2; k++){
            pascal[i++] = pascal[j] + pascal[j+1];
            j++;
        }
        pascal[i++] = 1;
        j++;
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d,",pascal[i]);
    }
    printf("\n");
    i=0;
    for(int l=0; l<lineas; l++){
        for (int e=0; e<lineas-l;e++){
            printf(" ");
        }
        for(int k=0; k<=l; k++){
            printf("%4d", pascal[i++]);
        }
        printf("\n");
    }

    return 0;
}
