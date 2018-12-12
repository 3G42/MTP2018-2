/* P6.c */
/* Gabriel Gomes Garcia*/
/* 11811EEL014 */
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define PI = 3.1415
typedef struct {float x,y;} Ponto;
Ponto *gera_pontos(int N)
{
    Ponto *p = (Ponto *)calloc(N,sizeof(Ponto));
    int i;
    printf("\n");
    for (i=0;i<N;i++)
    {
        p[i].x = cos(i*2.0*M_PI/(N-1));
        p[i].y = sin(i*2.0*M_PI/(N-1));
        printf("(%.3f,%.3f) ",p[i].x,p[i].y);
    }
    return p;
}
int main() {
    unsigned int N;
    Ponto *p;
    printf("Informe a quantidade de divisões da esfera:\n");
    scanf("%d",&N); getchar();
    p = gera_pontos(N);
    free(p);
    return 0;
}
