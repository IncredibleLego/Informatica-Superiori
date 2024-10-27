//Autore: Francesco Corrado
#include <stdio.h>

void insertion_sort(int n, int *arr);

main()
{
	int N,a;
	do
	{
		printf("\nInserisci quanto deve essere lungo l array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
	int array[N];
	printf("\nL'array e' lungo %d", N);
	for(a=0;a<N;a++)
	{
		printf("\n\nInserisci i %d valori dell'array: ", N);
		scanf("%d",&array[a]);
		printf("\nIl valore inserito e' %d", array[a]);
    }
    printf("\nIl contenuto dell'array non ordinato e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",array[a]);
	}
	printf("]");
    insertion_sort(N, array);
    printf("\nIl contenuto dell'array ordinato tramite selection sort e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",array[a]);
	}
	printf("]");
    
}

void insertion_sort(int n, int *arr)
{
	int a, b, x; 
	for(a=0;a<n;a++)
	{
		x=arr[a];
		b=a-1;
		while(b>=0 && arr[b]>x)
		{
			arr[b+1]=arr[b];
			b--;
		}
		arr[b+1]=x;
		
    }
}
