#include<stdio.h>

main()
{
	int a, contatore, N;
	//int x[N]; è un errore inserirla qua perchè N non ha un valore definito
	contatore=0; //inizializzazione contatore
	do
	{
		puts("\nInserisci la dimensione dell\'array");
	    scanf("%d",&N);
	}
	while(N<2);
	
	int x[N]; //tipoarray nomearray[numero elementi]
	
	//x[3]=28; //primo indice array è 0
	
	for(a=0; a<N; a++)
	{
		puts("\nInserisci un valore");
		scanf("%d",&x[a]);
		printf("%d",&x[a]);
	}
	for(a=0; a<N; a++)
	{
		if(x[a]<0) contatore++;
		printf("\nl\'elemento %d dell\'array x contiene %d",a,x[a]);
	}
	printf("\nTrovati %d elementi negativi",contatore);
}
