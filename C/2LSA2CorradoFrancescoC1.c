#include <stdio.h>

main()
{
	int a,b,c,d,min,MAX;
	printf("Inserisci il primo valore: ");
	scanf("%d", &a);
	printf("\nInserisci il secondo valore: ");
	scanf("%d", &b);
	if (a>b)
	{
	  MAX=a;
	  min=b;
    } 
	else 
	{
	     MAX=b;
	     min=a;
	 }
	printf("\nInserisci il terzo valore");
	scanf("%d", &c);
	if (c>MAX)
	{
	    MAX=c;
	}
	if (c<min)
	{
	    min=c;
	}
	printf("\nInserisci l'ultimo' valore");
	scanf("%d", &d);
	if (d>MAX)
	{
	    MAX=d;
	}
	if (d<min)
	{
	    min=d;
	}
	printf("\nIl valori minimi e massimi sono MAX = %d e min = %d ",MAX,min);
	
}
