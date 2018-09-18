/*P1.c*/
/*Gabriel Gomes Garcia*/
/*11811EEL014*/
#include <stdio.h>

int main()
{
    int est = 0,i;
    char num[256];

    printf("Informe um número em binario para que eu possa verificar se eh um multiplo de 3\n");
    scanf("%s",num);

    for (i = 0; num[i]!='\0' ; i++ )
    {
        if(est == 0 && num[i]=='1')
        {
            est = 1;
        }
        else if(est == 1)
        {
            if(num[i]=='1')
            {

                est = 0;

            }
            else if(num[i]=='0')
            {
                est = 2;
            }
        }
        else if(est == 2 && num[i]=='0')
        {
            est = 1;
        }
    }
    printf("%s ",num);

    if(est==0)
    {
        printf(" eh multiplo de 3");
    }
    else
    {
        printf(" nao eh");
    }
    return 0;
}
