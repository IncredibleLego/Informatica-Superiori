#include <stdio.h>
#include <string.h>
void function( char *string);
void cerca( char *stringa);
void vocali(char *strings);
main()
{
	int n;
	do
	{
		printf("\nInserisci la grandezza della stringa (>100): ");
		scanf("%d", &n);
	}while (n<=100);
	
	char str[n];
	char str1[n];
	char str2[n];
	char str3[n];
	char str4[n];
	printf("\nInserire le parole nella stringa: ");
	scanf(" %[^\n]s", str);
	strcpy(str1, str);
	strcpy(str2, str);
	strcpy(str3, str);
	strcpy(str4, str);
	printf("\nLe parole che hai inserito sono: %s", str1);
	function (str2);	
	cerca (str3);
	vocali(str4);
}
void function( char *string)
{
	strrev (string);
	printf("\nLa stringa inserita al contario e': %s", string);
}
void cerca( char *stringa)
{
	 char c;
     //c=carattere inserito da comparare con la stringa
    printf("\nInserire il carattere che si vuole cercare nella stringa: ");
    scanf(" %c", &c);
    printf("\nIl carattere inserito da cercare nella stringa e': %c", c);
	int dim, i, check;
	check=0;
	dim=strlen(stringa);
	for(i=0;i<dim;i++)
	{
		if(stringa[i]==c)
		{
			check=check+1;
		}else
		{
			continue;
		}
	}
	if(check!=0)
	{
		printf("\nLa stringa contiene il carattere %c %d volte ", c, check);
	}else
	{
		printf("\nLa stringa non contiene il carattere dato: EFFE ");
		printf("\nLa stringa contiene il carattere %c %d volte ", c, check);
	}
	int dimensione;
	do
	{
		printf("\nLa dimensione della stringa che vuoi cercare (>0): ");
		scanf("%d", &dimensione);
	}while(dimensione<=0);
	char stringa1[dimensione];
	printf("\nInserisci la stringa da cercare: ");
	scanf(" %[^\n]s", stringa1);
	int j=0;
	check=0;
	for(i=0; i<strlen(stringa)-1; i++)
{
	for(j=0;j<strlen(stringa1)-1;j++)
	{
	if(stringa[i]==stringa1[j])
{
check++;
}
else
{
continue;
}
}	
	}
if(check!=0)
	{
		printf("\nLa stringa contiene la substringa: EVVIVA!");
	}else
	{
		printf("\nLa stringa non contiene la substringa: EFFE! ");
	}
}
void vocali(char *strings)
{
	int dim, dimensione, j, f;
	int contaVocali;
	char vocali[] = "AEIOUaeiou";
	dimensione=strlen(vocali);
	dim=strlen(strings);
	contaVocali=0;
for(j=0;j<dim;j++)
{
	for(f=0;f<dimensione;f++)
	{
		if( strings[j] == vocali[f])
		{
			contaVocali=contaVocali+1;
		}else
		{
			continue;
		}
	}	
}
	printf("\nLe vocali contenute nella stringa sono: %d", contaVocali);
}
