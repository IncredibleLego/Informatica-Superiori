//Autrice: Francesco Corrado
#include <stdio.h>

void input1(float *Soglia, int *n); 
float input2(float *numeri, int n, float limite, int calcolo);

main()
{
	int N, i, Calcolo=0;
	float soglia=0.0;
	input1(&soglia,&N);
	float valori[N]; 
	Calcolo=input2(valori, N, soglia, Calcolo);
	printf("\nI valori dell'array sono: [ "); 
	for(i=0;i<N;i++)
	{
		printf(" %f ", valori[i]); 
	}
	printf(" ] "); 
	if(Calcolo>0)
	{
		printf("\nNell'array ci sono piu valori maggiori della soglia");
	}
	else
	{
		if(Calcolo<0)
		{
			printf("\nNell'array ci sono piu valori minori della soglia"); 
		}
		else
		{
			printf("\nIl numero di valori maggiori della somma e' uguale al numero di quelli minori"); 
		}
	}
}

void input1(float *Soglia, int *n) 
{
	do{
		printf("Inserisci un numero a piacere tra 1 e 100: ");
		scanf("%f", Soglia); 
	}while(*Soglia<1||*Soglia>100); 
	do{
		printf("\nQuanti valori vuoi inserire nell'array? ");
		scanf("%d", n);
	}while(n<0); 
}

float input2(float *numeri, int n, float limite, int calcolo)
{
	int i; 
	for(i=0;i<n;i++)
	    {
		printf("\nInserisci il %d valore dell'array: ", i+1);
		scanf("%f", &numeri[i]);
		if(numeri[i]>limite)
		{
			calcolo++;
		}
		else
		{
			if(numeri[i]<limite){
				calcolo--; 
			}
		}
	}
	return calcolo;
}


