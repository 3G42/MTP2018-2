/* P2.c */
/* Gabriel Gomes Garcia*/
/* 11811EEL014 */
#include<stdio.h>

long bindec(char v[]);
void binhex(char v[]);
long hexdec(char v[]);
long potencia(int x2,int x1);
void HexToBin();
void DecToBin();
void DecToHex();

int main ()
{
	int dec = 0, i, j, aux, hexadecimal,op;
	char bits[256];
	printf("\t Menu de opcoes \t\n(1) Binario para Decimal\n(2) Binario para Hexadecimal\n(3) Hexadecimal para Decimal\n(4) Hexadecimal para Binario");
	printf("\n(5) Decimal para Binario\n(6) Decimal para Hexadecimal\n(7) Octal para Decimal\n(8) Decimal para Octal\n\n");
	scanf("%i", &op);
	switch(op)
	{
		case 1:
            dec = bindec(bits);
            printf("O valor convertido eh: \n %d",dec);
            break;
		case 2:
			binhex(bits);
            break;
		case 3:
			dec = hexdec(bits);
            printf("O valor convertido eh: \n %d",dec);
            break;
		case 4:
			HexToBin();
			break;
		case 5:
			DecToBin();
			break;
		case 6:
            DecToHex();
            break;
		case 7:
			printf("\nDigite um octal: ");
			fflush(stdin);
			scanf("%s", bits);
			getchar();
			for(i = 0; bits[i] != '\0'; i++);
			i--;
			for(j = 1; i >= 0; i--, j = j * 8)
				dec = dec + j * (bits[i] - 48);
			printf("\n%i", dec);
			break;
		case 8:
			printf("\nDigite o numero decimal: ");
			scanf("%d", &dec);
			getchar();
			for (i = 0, j = 1; j < dec; i++, j = j*8);
			j = j/8;
			aux = i;
			while(i >= 0)
			{
				if(dec % 8 == 0)
					bits[i] = 0;
				else if(dec % 8 == 1)
					bits[i] = 1;
				else if(dec% 8 == 2)
					bits[i] = 2;
				else if(dec% 8 == 3)
					bits[i] = 3;
				else if(dec% 8 == 4)
					bits[i] = 4;
				else if(dec% 8 == 5)
					bits[i] = 5;
				else if(dec% 8 == 6)
					bits[i] = 6;
				else if(dec% 8 == 7)
					bits[i] = 7;
				dec = dec/8;
				i--;
				j = j/8;
			}
			printf("\n");
			for(i = 1; i <= aux; i++)
				printf("%i", bits[i]);
			break;
		default:
			return 0;
	}
}
void binhex(char v[])
{
    long decimal = 0;
    char pac[5];
    decimal = bindec(v);

    printf("\n Seu numero convertido em hexadecimal eh:\n\n %X\n\n",decimal);
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
void HexToBin(){
    int decimal,i=0,j,aux;
    char bits[250];
    printf("\nDigite um hexadecimal: ");
			scanf("%s", bits);
			getchar();
			for(i = 0; bits[i] != '\0'; i++)
			{
				if (bits[i] == 'A' || bits[i] == 'a')
					bits[i] = 10;
				else if (bits[i] == 'B' || bits[i] == 'b')
					bits[i] = 11;
				else if (bits[i] == 'C' || bits[i] == 'c')
					bits[i] = 12;
				else if (bits[i] == 'D' || bits[i] == 'd')
					bits[i] = 13;
				else if (bits[i] == 'E' || bits[i] == 'e')
					bits[i] = 14;
				else if (bits[i] == 'F' || bits[i] == 'f')
					bits[i] = 15;
				else if (bits[i] == '0')
					bits[i] = 0;
				else if (bits[i] == '1')
					bits[i] = 1;
				else if (bits[i] == '2')
					bits[i] = 2;
				else if (bits[i] == '3')
					bits[i] = 3;
				else if (bits[i] == '4')
					bits[i] = 4;
				else if (bits[i] == '5')
					bits[i] = 5;
				else if (bits[i] == '6')
					bits[i] = 6;
				else if (bits[i] == '7')
					bits[i] = 7;
				else if (bits[i] == '8')
					bits[i] = 8;
				else if (bits[i] == '9')
					bits[i] = 9;
			}
			i--;
			for(j = 1; i >= 0; i--, j = j * 16)
				decimal = decimal + j * bits[i];
			for (i = 0, j = 1; j < decimal; i++, j = j*2);
			j = j/2;
			aux = i;
			while(i >= 0)
			{
				if(decimal % 2 == 0)
				bits[i] = 0;
				else
				bits[i] = 1;
				decimal = decimal /2;
				i--;
				j = j/2;
			}
			printf("\n");
			for(i = 1; i <= aux; i++)
				printf("%i", bits[i]);
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
void DecToBin()
{
        int decimal,i,j,aux;
        char bits[256];
        printf("\nDigite o numero decimal: ");
        scanf("%d", &decimal);
        getchar();
        for (i = 0, j = 1; j < decimal; i++, j = j*2);
        j = j/2;
        aux = i;
        while(i >= 0)
        {
            if(decimal % 2 == 0)
            bits[i] = 0;
            else
            bits[i] = 1;
            decimal = decimal /2;
            i--;
            j = j/2;
        }
        printf("\n");
        for(i = 1; i <= aux; i++)
            printf("%i", bits[i]);
}
void DecToHex()
{
        int decimal, aux, i , j;
        char bits[256];
        for(i=0; i<255;i++, bits[i]='G');
        i=255;
        printf("\nDigite o numero decimal: ");
        scanf("%d", &decimal);
        getchar();
        for (i = 0, j = 1; j < decimal; i++, j = j*16);
        j = j/16;
        aux = i;
        i--;
        while(i >= 0)
        {
            if(decimal % 16 == 0)
                bits[i] = '0';
            else if(decimal % 16 == 1)
                bits[i] = '1';
            else if(decimal % 16 == 2)
                bits[i] = '2';
            else if(decimal % 16 == 3)
                bits[i] = '3';
            else if(decimal % 16 == 4)
                bits[i] = '4';
            else if(decimal % 16 == 5)
                bits[i] = '5';
            else if(decimal % 16 == 6)
                bits[i] = '6';
            else if(decimal % 16 == 7)
                bits[i] = '7';
            else if(decimal % 16 == 8)
                bits[i] = '8';
            else if(decimal % 16 == 9)
                bits[i] = '9';
            else if(decimal % 16 == 10)
                bits[i] = 'A';
            else if(decimal % 16 == 11)
                bits[i] = 'B';
            else if(decimal % 16 == 12)
                bits[i] = 'C';
            else if(decimal % 16 == 13)
                bits[i] = 'D';
            else if(decimal % 16 == 14)
                bits[i] = 'E';
            else if(decimal % 16 == 15)
                bits[i] = 'F';
            decimal = decimal/16;
            i--;
            j = j/16;
        }
            i--;
            i--;
            for (i=0;bits[i]!= 'G';i++);
            bits[i] = '\0';
            printf("\n");
            for (i=0;bits[i]!='\0';i++)
            {
                printf("%c", bits[i]);
            }


}
