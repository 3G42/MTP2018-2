/* P5.c */
/* Gabriel Gomes Garcia*/
/* 11811EEL014 */
#include<stdio.h>
typedef
    unsigned long long int
Bytes8;
typedef
    struct LCG {
        Bytes8 a,c,m, rand_max, atual;
    }LCG;
void semente(LCG * r, Bytes8 seed)
{
    //Constantes do POSIX[de]rand98, glibc[de]rand48[_r]
    //ULL tranforma a constante 'int' em 'unsigned long long int'
    r->a = 0x5DEECE66DULL;
    r->c = 11ULL;
    r->m = (1ULL << 48);
    r->rand_max = r->m-1;
    r->atual = seed;
}
Bytes8 lcg_rand(LCG*r){
    r->atual = (r->a*r->atual + r->c)%r->m;
    return r->atual;
}
double lcg_rand_01(LCG*r)
{
    return((double)lcg_rand(r))/(r->rand_max);
}
void gera_numeros(float *vetor, int tam, float min, float max, LCG *r)
{
    int i;
    printf("Iremos montar o produtório e /ou somatório de 50 números aleatórios");
    for(i=0; i<tam; i++)
        vetor[i] = (max-min)*lcg_rand_01(r)+min;
}
float som(float *inicio_vetor, float *fim_vetor)
{
    while(fim_vetor > inicio_vetor)
 	{
 		return *fim_vetor + som(inicio_vetor, fim_vetor -1);
	}
	if(fim_vetor== inicio_vetor)
	{
		return *inicio_vetor;
	}
}
float prod(float *inicio_vetor, float *fim_vetor)
{
   while(fim_vetor > inicio_vetor)
 	{
 		return *fim_vetor * prod(inicio_vetor, fim_vetor -1);
	}
	if(fim_vetor == inicio_vetor)
	{
		return *inicio_vetor;
	}
}
int main()
{
    LCG random;
    semente(&random, 123456);
    int n = 50;
    double a,b;
    float vet[n];
    char x;
    printf("Escolha uma opção:\n1-Somatório,\n2-Produtório\n");
    scanf("%c",&x);
    gera_numeros(vet, 50, 0.5, 1.5, &random);
    switch(x)
    {
    case '1':
        a = som(&vet[0],&vet[49]);
        printf("\nO somatório é igual %lf\n\n",a);
        break;
    case '2':
        b = prod(&vet[0],&vet[49]);
        printf("\nO produtório é igual %lf\n\n",b);
        break;
    default:
        printf("\nERRO 404: Informe uma opção válida\n");
    }
    return x;


}
