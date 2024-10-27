//Autore: Francesco Corrado
#include <stdio.h>

int inserimento_valori(int n1, int n2, int *a1, int *a2);
int ordinamento(int n1, int n2, int *a1, int *a2);
int unione(int n1, int n2, int *a1, int *a2);
int intersezione(int n1, int n2, int *a1, int *a2);

main()
{
	int l1,l2,a;
	printf("Calcola l'unione e l'intersezione di due insiemi numerici");
	do
	{
		printf("\nInserisci quanto deve essere lungo il primo array (> di 1): ");
	    scanf("%d", &l1);
	}
	while(l1<2);
	printf("\nIl primo array e' lungo %d", l1);
	do
	{
		printf("\n\nInserisci quanto deve essere lungo il secondo array (> di 1): ");
	    scanf("%d", &l2);
	}
	while(l2<2);
	printf("\nIl secondo array e' lungo %d", l2);
	int array1[l1];
	int array2[l2];
	inserimento_valori(l1, l2, array1, array2);
	ordinamento(l1, l2, array1, array2);
	printf("\nIl contenuto dell'array1 ordinato in ordine crescente e': [");
	for (a=0;a<l1;a++)
	{
		printf(" %d ",array1[a]);
	}
	printf("]");
	printf("\nIl contenuto dell'array2 ordinato in ordine crescente e': [");
	for (a=0;a<l2;a++)
	{
		printf(" %d ",array2[a]);
	}
	printf("]");
	unione(l1, l2, array1, array2);
	intersezione(l1, l2, array1, array2);

}
//Funzione che chiede di inserire i valori di array1 e array2
int inserimento_valori(int n1, int n2, int *a1, int *a2)
{
	int a;
	for(a=0;a<n1;a++)
	{
		printf("\n\nInserisci i %d valori del primo array (i valori devono essere diversi tra loro): ", n1);
		scanf("%d",&a1[a]);
		printf("\nIl valore inserito in array1 e' %d", a1[a]);
    }
    for(a=0;a<n2;a++)
	{
		printf("\n\nInserisci ora i %d valori del secondo array (i valori devono essere diversi tra loro): ", n2);
		scanf("%d",&a2[a]);
		printf("\nIl valore inserito in array2 e' %d", a2[a]);
    }
}
//Funzione che ordina i valori nei due array utulizzando il metodo bubblesort
int ordinamento(int n1, int n2, int *a1, int *a2)
{
	int a, b, scambio;
	for(a=0;a<n1-1;a++)
	{
		for(b=0;b<n1-1;b++)
		{
			if(a1[b]>a1[b+1])
			{
				scambio=a1[b];
				a1[b]=a1[b+1];
				a1[b+1]=scambio;
		    }
	    }
    }
	for(a=0;a<n2-1;a++)
	{
		for(b=0;b<n2-1;b++)
		{
			if(a2[b]>a2[b+1])
			{
				scambio=a2[b];
				a2[b]=a2[b+1];
				a2[b+1]=scambio;
		    }
		}
    }
}
//Funzione che crea un array che contiene tutti i valori di array1 e array2 solo una volta
int unione(int n1, int n2, int *a1, int *a2)
{
	int a,b,c,num_scalano,scambio,scalati;
	scalati=0;
	int arrayunione[200];
	for(a=0;a<n1;a++)
	{
		arrayunione[a]=a1[a];
	}
	c=0;
	for(a=n1;a<n1+n2;a++)
	{
		arrayunione[a]=a2[c];
		c++;
	}
	c=1;
	for(a=0;a<n1+n2-1;a++) //Ricerca ed eliminazione dei numeri doppi
	{
		for(b=c;b<n1+n2-1;b++)
		{
			if(arrayunione[a]==arrayunione[b])
			{
				for(num_scalano=b;num_scalano<n1+n2-1;num_scalano++)
				{
					scambio=arrayunione[num_scalano+1];
					arrayunione[num_scalano]=scambio;
				}
				scalati++;
		    }
		}
		c++;
    }
    for(a=0;a<n1+n2;a++) //Bubblesort per ordinare l'array finale
	{
		for(b=0;b<n1+n2;b++)
		{
			if(arrayunione[b]>arrayunione[b+1])
			{
				scambio=arrayunione[b];
				arrayunione[b]=arrayunione[b+1];
				arrayunione[b+1]=scambio;
		    }
		}
    }
    printf("\nIl contenuto dell'array unione array1 e array2 e': [");
	for (a=1;a<n1+n2-scalati+2;a++)
	{
		printf(" %d ",arrayunione[a]);
	}
	printf("]");
}
//Funzione che crea un array che contiene tutti i valori comuni di array1 e array2 solo una volta
int intersezione(int n1, int n2, int *a1, int *a2)
{
	int a,b,inserimento;
	int arrayintersezione[200];
	inserimento=0;
	for(a=0;a<n1-1;a++)
	{
		for(b=0;b<n2-1;b++)
		{
			if(a1[a]==a2[b])
			{
				arrayintersezione[inserimento]=a1[a];
				inserimento++;
			}
		}
	}
	printf("\nIl contenuto dell'array intersezione array1 e array2 e': [");
	for (a=0;a<inserimento;a++)
	{
		printf(" %d ",arrayintersezione[a]);
	}
	printf("]");
}






