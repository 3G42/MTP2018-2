#include <stdio.h>
#include<conio2.h>
int main()
{
int x,y,largura,comprimento,i,j,k,l;
x=2;
y=2;
largura=1;
comprimento=1;

    gotoxy(x,y);
    printf("\xDA");
    for(i=1;i<largura-1;i++)
    {
        printf("\xC4");
    }
    printf("\xBF");
    for(j=1;j<comprimento-1;j++)
    {
        gotoxy(x,y+j);
        printf("\xB3");
        gotoxy(x+largura-1,y+j);
        printf("\xB3");
    }
    gotoxy(x,comprimento+y-1);
    printf("\xC0");
    for(i=1;i<largura-1;i++)
    {
        printf("\xC4");
    }
    printf("\xD9");

    gotoxy(10,10);
    textbackground(WHITE);
    printf("\xDB\xDD");
}
