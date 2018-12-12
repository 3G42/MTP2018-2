/* P4.c */
/* Gabriel Gomes Garcia*/
/* 11811EEL014 */
#include<stdio.h>

int Acker(int m,int n);
int main()
{
    int m=-1,n=-1,a,b;
    printf("Informe dois números inteiros positivos\n");
    for(;m<0||n<0;)
    {
        scanf("%d,%d",&m,&n);
        }
    printf("\nAcker:%d + %d = %d",m,n,Acker(m,n));

}
int Acker(int m,int n)
{
    if(m>0&&n==0) return Acker(m-1,1);
    else if (m>0&&n>0) return Acker (m-1,Acker(m,n-1));
    if (m==0) return ++n;
}
