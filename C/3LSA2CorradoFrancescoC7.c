//Autore: Francesco Corrado
#include <stdio.h>

void quick_sort(int *arr, int first, int last);

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
    quick_sort(array,0,N-1);
    printf("\nIl contenuto dell'array ordinato tramite selection sort e': [");
	for (a=0;a<N;a++)
	{
		printf(" %d ",array[a]);
	}
	printf("]");
    
}

void quick_sort(int *arr, int first, int last)
{
	int i, j, pivot, temp;
	if(first<last)
	{
      pivot=first;
      i=first;
      j=last;     
      while(i<j)
	  {
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j)
		 {   
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quick_sort(arr,first,j-1);
      quick_sort(arr,j+1,last);
   }
}
