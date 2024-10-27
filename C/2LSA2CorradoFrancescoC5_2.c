#include <stdio.h>
main()
{
	int min,max,i,N;
	printf("Chiede il numero di elementi dell'array e riporta il minimo e massimo numero contenuti in esso");
	do
	{
		printf("\nInserisci quanto deve essere lungo l'array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
	int x[N];
	for(i=0;i<2;i++)
	{
		printf("\nInserisci il valore : ");
		scanf("%d",&x[i]);
		if(i>0)
		{
			if(x[i]>x[i-1])
			{
				max=x[i];
				min=x[i-1];
			}
			else
			{
				max=x[i-1];
				min=x[i];
			}
		}
	}
	for(i=2;i<N;i++)
	{
		printf("\nInserisci il valore : ");
		scanf("%d",&x[i]);
		if(x[i]>max)
		{
			max=x[i];
		}
		else
		{
			if (x[i]<min)
			{
				min=x[i];
			}
		}
	}
	printf("\nIl valore maggiore conenuto nell'array è %d", max);
	printf("\nIl valore minore conenuto nell'array è %d", min);
}
