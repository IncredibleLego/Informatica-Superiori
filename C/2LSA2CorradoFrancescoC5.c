#include <stdio.h>
main()
{
	int a,b,N,i;
	printf("Dato un array x di n elementi, il programma calcola un array y con tutti gli elementi di x in ordine invertito e lo scrive sullo schermo.");
	do
	{
		printf("\nInserisci quanto deve essere lungo l'array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
	int x[N];
	int y[N];
	b=N;
	for(a=0;a<N;a++)
	{
		printf("\n Inserisci il valore : ");
		scanf("%d",&x[a]);
	}
	printf("\nIl contenuto dell'array x è: x[");
	for (i=0;i<N;i++)
	{
		printf("%d",&x[i]);
	}
	printf("]");
	printf("\nIl contenuto dell'array y (invertito) è: y[");
	for (i=0;i<N;i++)
	{
		printf("%d",&y[i]);
	}
	printf("]");
}
