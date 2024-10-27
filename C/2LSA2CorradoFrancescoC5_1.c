#include <stdio.h>
main()
{
	int sommaPositivi,sommaNegativi,i,N;
	sommaPositivi=0;
	sommaNegativi=0;
	printf("Chiede il numero di elementi dell'array e calcola la somma dei numeri positivi e negativi contenuti nell'array");
	do
	{
		printf("\nInserisci quanto deve essere lungo l'array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
	int x[N];
	for(i=0;i<N;i++)
	{
		printf("\nInserisci il valore : ");
		scanf("%d",&x[i]);
	}
	for(i=0;i<N;i++)
	{
		if(x[i]<0)
		{
			sommaNegativi=sommaNegativi+x[i];
		}
		else
		{
			sommaPositivi=sommaPositivi+x[i];
		}
	}
	printf("\nLa somma dei numeri postivi contenuti nell'array è uguale a %d", sommaPositivi);
	printf("\nLa somma dei numeri negativi contenuti nell'array è uguale a %d", sommaNegativi);
}
