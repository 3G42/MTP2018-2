#include<stdio.h>


long bindec(char v[]);
void binhex(char v[]);
long hexdec(char v[]);
long potencia(int x2,int x1);
void hexbin(char hex[],char bin[]);
int main ()
{
    char bits[256],hex[256];
    int i;
    long dec;
    printf("Digite umas das das opcoes, para conversao:\n 1)Binario para decimal\n 2)Binario para hexadecimal\n 3)Hexadecimal para Decimal\n 4)Hexadecimal para binario\n 5) Decimal para Binario\n 6) Decimal para Hexadecimal\n 7)Octal para Decimal\n 8) Decimal para Octal ");

	    scanf("%d",&i);

    switch(i)
    {
    case 1:
        dec = bindec(bits);
        printf("O valor convertido eh: \n %d",dec);
        break;
    case 2:
        binhex(bits);
        break;
    case 3:
        dec = hexdec(hex);
        printf("O valor convertido eh: \n %d",dec);
        break;
    case 4:
        hexbin(hex,bits);
        printf("\nO valor convertido eh: \n %s",bits);
        break;
    case 5:
        break;
    case 6:
        break;

    case 7:
        break;

    case 8:
        break;

    default:
    return 0;
}
}
long bindec(char v[])
{
    int i = 0,j=0,tamanhoVet=0;
    long num = 0,pot=1;
    printf("Informe um numero em binario\n");
    fflush(stdin);
    scanf("%s",v);
    while(v[i]!='\0')
    {
        i++;
    }
    i--;
    tamanhoVet = i;
    for(i=0;v[i]!='\0';i++)
    {
        if (v[i]=='1')
        {

            if((tamanhoVet-i)==0)
            {
                num = num+1;
            }
            else
            {
                j=0;
                pot=1;
                while((tamanhoVet-i)>j)
                {
                    pot = pot*2;
                    j++;
                }
                num = num+pot;
            }
        }
    }
    return num;
}
void binhex(char v[])
{
    long decimal = 0;
    char pac[5];
    decimal = bindec(v);

    printf("\n Seu numero convertido em hexadecimal eh:\n\n %X\n\n",decimal);
}
long hexdec(char v[])
{
    int i = 0,j=0,tamanhoVet=0;
    long num = 0,pot=1;
    printf("Informe um numero em binario\n");
    fflush(stdin);
    scanf("%s",v);
    while(v[i]!='\0')
    {
        i++;
    }
    tamanhoVet = i;
        for(i=0;v[i]!='\0';i++)
    {
        pot = 1;
        if(v[i]==48)
        {
            pot = potencia(tamanhoVet,i);
            pot = 0*pot;
        }
        else if(v[i]=='1')
        {
            pot = potencia(tamanhoVet,i);
            pot = 1*pot;
        }
        else if(v[i]=='2')
        {
            pot = potencia(tamanhoVet,i);
            pot = 2*pot;
        }
        else if(v[i]=='3')
        {
            pot = potencia(tamanhoVet,i);
            pot = 3*pot;
        }
        else if(v[i]=='4')
        {
            pot = potencia(tamanhoVet,i);
            pot = 4*pot;
        }
        else if(v[i]=='5')
        {
            pot = potencia(tamanhoVet,i);
            pot = 5*pot;
        }
        else if(v[i]=='6')
        {
            pot = potencia(tamanhoVet,i);
            pot = 6*pot;
        }
        else if(v[i]=='7')
        {
            pot = potencia(tamanhoVet,i);
            pot = 7*pot;
        }
        else if(v[i]=='8')
        {
            pot = potencia(tamanhoVet,i);
            pot = 8*pot;
        }
        else if(v[i]=='9')
        {
            pot = potencia(tamanhoVet,i);
            pot = 9*pot;
        }
        else if(v[i]=='a'||v[i]=='A')
        {
            pot = potencia(tamanhoVet,i);
            pot = 10*pot;
        }
        else if(v[i]=='b'||v[i]=='B')
        {
            pot = potencia(tamanhoVet,i);
            pot = 11*pot;
        }
        else if(v[i]=='c'||v[i]=='C')
        {
            pot = potencia(tamanhoVet,i);
            pot = 12*pot;
        }
        else if(v[i]=='d'||v[i]=='D')
        {
            pot = potencia(tamanhoVet,i);
            pot = 13*pot;
        }
        else if(v[i]=='e'||v[i]=='E')
        {
            pot = potencia(tamanhoVet,i);
            pot = 14*pot;
        }
        else if(v[i]=='f'||v[i]=='F')
        {
            pot = potencia(tamanhoVet,i);
            pot = 15*pot;
        }
        num = num+pot;

    }
    return num;
}
long potencia(int x2,int x1)
{
    int j=0;
    int pot=1;
    while((x2-x1)>j+1)
        {
            pot = pot*16;
            j++;
        }
    return pot;
}
void hexbin(char hex[],char bin[])
{
    int i=0,j=0,h;
    char c;

    scanf("%s",hex);
    for(i=0; hex[i]!='\0'; i++);

    j = i*4-1;
    i--;
    bin[j+1]='\0';
    h=j+1;
    while(i>=0)
    {
        if(hex[i]==48)
        {
            bin[j]= '0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;

        }
        else if(hex[i]==49)
        {
            bin[j]= '1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==50)
        {
            bin[j]= '0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==51)
        {
            bin[j]= '1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==52)
        {
            bin[j]= '0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==53)
        {
            bin[j]= '1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==54)
        {
            bin[j]= '0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==55)
        {
            bin[j]= '1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
        }
        else if(hex[i]==56)
        {
            bin[j]= '0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
        }
        else if(hex[i]==57)
        {
            bin[j]= '1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
        }
        else if(hex[i]=='a'||hex[i]=='A')
        {
            bin[j]= '0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
        }
        else if(hex[i]=='b'||hex[i]=='B')
        {
            bin[j]= '1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
        }
        else if(hex[i]=='c'||hex[i]=='C')
        {
            bin[j]= '0';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
        }
        else if (hex[i]=='d'||hex[i]=='D')
        {
            bin[j]= '1';
            j--;
            bin[j]='0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
        }
        else if (hex[i]=='e'||hex[i]=='E')
        {
            bin[j]= '0';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
        }
        else if (hex[i]=='f'||hex[i]=='F')
        {
            bin[j]= '1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
            bin[j]='1';
            j--;
        }
        i--;
    }
}

