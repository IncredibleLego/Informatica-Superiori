//Autore: Francesco Corrado
#include <stdio.h>

void selection_sort(int n, int *arr);

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
    selection_sort(N, array);
    printf("\nIl contenuto dell'array ordinato tramite selection sort e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",array[a]);
	}
	printf("]");
    
}

void selection_sort(int n, int *arr)
{
	int a, b, pos, min, x; 
	for(a=0;a<n;a++)
	{
		min=arr[a];
		pos=a;  
		for(b=a;b<n;b++)
		{
			if(arr[b]<min)
			{
				min=arr[b]; 
				pos=b; 
			}	
	    }
	    x=arr[a]; 
	    arr[a]=min;
	    arr[pos]=x; 
    }
}
