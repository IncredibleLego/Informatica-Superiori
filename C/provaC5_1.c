#include <stdio.h>
main()
{
	int N,somma,a,avg,sum=0;
	N=5;
	int x[N];   
	for(a=0;a<N;a++)
	{
		printf("\n Inserisci il voto : ");
		scanf("%d",&x[a]);
		printf("%d",&x[a]);
	}
	
	for(a=0;a<N;a++)
	{
		sum+=x[a];			
	}
	
	avg=sum/N;
	printf("\n Voto medio : %d",avg);
	printf("\n\n");
}

