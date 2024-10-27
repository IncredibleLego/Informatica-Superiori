#include <stdio.h>

main()
{
	printf("Dato un array lungo N e i suoi elementi inseriti, il programma li riordina utilizzando il metodo bubble sort");
	int a,b,N,scambio;
	do
	{
		printf("\nInserisci quanto deve essere lungo l'array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
	int bubblesort[N];
	for(a=0;a<N;a++)
	{
		printf("\n Inserisci il valore : ");
		scanf("%d",&bubblesort[a]);
		printf("%d",bubblesort[a]);
	}
	for(a=0;a<N-1;a++)
		for(b=0;b<N-1;b++)
			if(bubblesort[b]>bubblesort[b+1])
			{
				scambio=bubblesort[b];
				bubblesort[b]=bubblesort[b+1];
				bubblesort[b+1]=scambio;
		    }
	printf("\nIl contenuto dell'array ordinato in ordine crescente e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",bubblesort[a]);
	}
	printf("]");
}
