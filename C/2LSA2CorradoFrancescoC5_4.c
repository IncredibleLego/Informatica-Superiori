#include <stdio.h>
main()
{
	int N,somma,v,y,a,t;
	printf("Dato un array, identifica le coppie di numeri la cui somma è pari ad un numero dato.Come output mostra le coppie di numeri e la loro posizione dentro l'array.");
    printf("\nInserisci quanto deve essere lungo l'array (> di 0): ");
    scanf("%d", &N);
	int x[N];
	printf("\nOra inserisci gli elementi dell'array");
	for(v=0;v<N;v++)
	{
		printf("\n Inserisci il numero : ");
		scanf("%d",&x[v]);
	}
	printf("\nInserisci il numero per il quale vuoi trovare le coppie nell'array: ");
	scanf("%d", &somma);
	printf("\nLe coppie la cui somma fa %d sono: ", somma);
	y=1;
	a=N;
	for(v=0;v<N-1;v++)
	{
		for(t=y;t<N;t++)
		{
			if(x[v]+x[t]==somma)
			{
				printf("\n%d + %d nelle posizioni %d e %d", x[v],x[t],v,t);
			}
		}
	}
	
}
