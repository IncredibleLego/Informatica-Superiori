//Autore: Francesco Corrado
#include <stdio.h>

int input1(int n);
float input2(int n,int *array1, int *array2);

main()
{
	int num_prodotti;
	printf("Chiede il numero di prodotti che si desiderano comprare e chiede successivamente applica gli sconti");
	num_prodotti = input1(num_prodotti);
	int prezzo[num_prodotti];
	int sconti[num_prodotti];
	input2(num_prodotti, prezzo, sconti);
	
}
int input1(int n)
{
	do
	{
		printf("\nInserisci quanti prodotti si vogliono comprare: ");
	    scanf("%d", &n);
	}
	while(n<0);
}
float input2(int n,int *array1, int *array2)
{
	int a;
	for(a=0;a<n;a++)
	{
		printf("\n Quanto costa il prodotto? : ");
		scanf("%d",&array1[a]);
		printf("\nIl prodotto costa %d", array1[a]);
		printf("\n Quale e' lo sconto da applicare? : ");
		scanf("%d",&array2[a]);
		printf("\nLo sconto da applicare e' del %d %", array2[a]);
	}
}
