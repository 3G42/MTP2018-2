/* P7.c */
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
    }
    return p;
}
void salvaPonto(Ponto *p, int N)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("pontos.dat","wb" );
    for(i=0;i<N;i++)
    {
        fprintf(arquivo, "(%.3lf,%.3lf) ", p[i].x, p[i].y);
    }
    printf("Arquivo gravado");
    fclose(arquivo);
}
void lePontos(Ponto *p)
{
    FILE *arquivo;
    char text[1000];
    int i;
    arquivo = fopen("pontos.dat","rb");
    fread(&text, sizeof(char), 1000, arquivo);
    printf(" \n %s \n ",text);
    fclose(arquivo);
}
int main() {
    unsigned int N,op;
    Ponto *p;
    printf("\n (1)Gerar arquivos com pontos \n (2)Recuperar pontos de arquivo\n Op:");
    scanf("%d",&op); getchar();
    switch(op)
    {
        case 1:
            printf("\nInforme a quantidade de divisoes da esfera:\n");
            scanf("%d",&N); getchar();
            p = gera_pontos(N);
            salvaPonto(p,N);
        break;

        case 2:
            printf("\nAs coordenadas sao: ");
            lePontos(p);
        break;
        default :
            printf("OP INVALIDA - FECHANDO APLICACAO");
            break;

    }
    free(p);
    return 0;
}
