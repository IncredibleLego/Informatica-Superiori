//Autore: Francesco Corrado

#include <stdio.h>
#include <time.h>

void output(int lunghezza, int *array);

main()
{
	int min, MAX, n, a;  
	printf("Programma che chiede all'utente di inserire un valore massimo e uno minimo e calcola dei numeri casuali nell'intervallo compreso tra i due valori");
	do
	{
		printf("\nQuanti sono i numeri casuali da inserire nell'intervallo?': ");
		scanf("%d",&n);
	}
	while (n<=0);
	printf("\nIl numero di elementi da inserire nell'intervallo e': %d", n);
	do
	{
		printf("\n\nInserire min valore intervallo: ");
		scanf("%d",&min);
		printf("\nInserire max valore intervallo: ");
		scanf("%d",&MAX);
	}
	while (min>=MAX);
	printf("\nIl valore del minimo e': %d", min);
	printf("\nIl valore del massimo e': %d", MAX);
	int x[n];
	srand(time(0));
	for(a=0;a<n;a++)
	{
		do
		{
			x[a]=(rand()%(MAX-min+1)+min);
		}
		while((x[a]>MAX)||(x[a]<min));
	}
	output(n, x);

}

void output(int lunghezza, int *array)
{
	int a;
	printf("\nI numeri casuali generati sono: ");
	for (a=0;a<lunghezza;a++)
	{
		printf(" %d ",array[a]);
	}
}
