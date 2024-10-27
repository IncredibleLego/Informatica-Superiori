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
	}
	printf("\nArray iniziale: [");
	for(a=0;a<N;a++)
	{
		printf(" %d ",bubblesort[a]);	
	}
	printf("]");
	bubble(bubblesort, N);
	printf("\nIl contenuto dell'array ordinato in ordine crescente e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",bubblesort[a]);
	}
	printf("]");
}
void bubble(int *array, int x)
{
	int a, b, scambio;
	for(a=0;a<x-1;a++)
		for(b=0;b<x-1;b++)
			if(array[b]>array[b+1])
			{
				scambio=array[b];
				array[b]=array[b+1];
				array[b+1]=scambio;
		    }
}
