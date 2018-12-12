/* P3.c */
/* Gabriel Gomes Garcia*/
/* 11811EEL014 */
#include<stdio.h>
int cont(char num[])
{
    int i = 0;
    for(i=0;num[i]!='\0';i++);
    return i;
}
long int converte (int i,char num[], int a,int dec)
{
    if(i<0)
    {
        return a;
    }
    else if(i>=0)
    {

        return converte(i-1, num, a +((num[i]-48)*dec) ,dec*10);
    }
}
void excluir_casa(char palavra[], int tamanho_string, int posicao);
int main()
{
    long int a=0,i,dec=1,j=0,con;
    char num[256];
    printf("Informe um numero lokao:");

    scanf("%s", num);
    i = cont(num);
    i--;
    for(j=0;j<=i;j++)
    {
        if(num[j]<'0'||num[j]>'9')
        {
            for(con = j; con <=i; con++)
				num[con] = num[con+1];
				j--;
				i--;
        }
    }
    //Verificar inversamente e multiplicar pela potência de 10//
    a = converte(i,num,a,dec);
    printf("%ld",a);
    return 0;
}
