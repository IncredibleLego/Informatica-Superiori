#include <stdio.h>

main()
{
	printf("Cosa fa il programma");
	int inserire le variabili;
//Chiede quanto deve essere lungo l'array
	do
	{
		printf("\nInserisci quanto deve essere lungo l'array (> di 1): ");
	    scanf("%d", &N);
	}
	while(N<2);
//Chiede i valori da inserire nell'array
	for(a=0;a<N;a++)
	{
		printf("\n Inserisci il valore : ");
		scanf("%d",&nomearray[a]);
	}
	bubble(bubblesort, N);
}
//Ordinamento bubble sort con un array
void bubble(int *array, int x)
{
	int a, b, scambio;
	for(a=0;a<x-1;a++)
		for(b=0;b<x-1;b++)
			if(array[b]>array[b+1])
			{
				scambio=array[b];
				array[b]=array[b+1];
				array[b+1]=scambio;
		    }
//Trasformazione di un orario in secondi
#include <stdio.h>

void split_time (long int tot_sec, int *h, int *m, int *s);

main()
{
	long int totSecondi; 
	int ore, minuti, secondi;
	printf("Inserisci il numero di secondi dalla mezzanotte: ");
	scanf("%d", &totSecondi); 
	printf("%d", totSecondi); 
	split_time (totSecondi, &ore, &minuti, &secondi); 
	printf("\n%d ore, %d minuti, %d secondi", ore, minuti, secondi); 
}

void split_time (long int tot_sec, int *h, int *m, int *s)
{
	*m=tot_sec/60; 
	*s=tot_sec%60; 
	*h=*m/60;
	*m=*m%60;
}
//Scambio di valori
#include <stdio.h> 
#include <string.h>

void rovescia (char *s);

main()
{
	char stringa[20];
	printf("inserisci una parola da rovesciare: ");
	scanf("%s", stringa); 	
	//printf("la parola scelta e': %s", stringa);
	rovescia(stringa);  
}

void rovescia(char *s)
{
	int i1,i2;
	printf("la parola scelta e': %s", s); 
	i1=0;
	i2=0; 
	/*do{
		if(s[i1]==){
			i2=i1; 
			i1=20; 
		}
		i1++;
	}while(i1<20);*/ 
	i2=strlen(s); 
	printf("\n i2: %d\n", i2);
	for(i1=i2-1;i1>=0;i1--){
		printf("%c", s[i1]); 
	}
}
//Trovare i due valori più grandi
#include <stdio.h>

void  max_secondmax( int a[], int n, int *max, int *second_max );

main()
{
	printf("Con questo programma andremo ad ordinare in ordine crescente un array di numeri con il metodo bubble sort");
	int x, N, massimo, secondo_massimo;
	massimo=5;
	secondo_massimo=13; 
	//N e n sono la lunghezza dell'array 
	do
	{
		printf("\nInserire numero lunghezza array ");
	    scanf("%d", &N);
	}
	while(N<2);
	int elencoNumeri[N];
	for(x=0;x<N;x++)
	{
		printf("\nInserire il %d valore dell'array: ", x+1);
		scanf("%d",&elencoNumeri[x]);
		printf("Il valore inserito e': %d",elencoNumeri[x]);
	}
	max_secondmax(elencoNumeri, N, &massimo, &secondo_massimo); 
}

void  max_secondmax( int a[], int n, int *max, int *second_max )
{
	printf("a[0]: %d", a[0]); 
	printf("\n n: %d", n);
	printf("\n max: %d", max);
	printf("\n second_max: %d", second_max); 

//Puntatore al minimo
#include <stdio.h>
int *smallest( int a[], int n);
main()
{
	int array[20], lunghezza, i;
	printf("Quanti numeri vuoi inseire nell'array? ");
	scanf("%d", &lunghezza); 
	for(i=0;i<lunghezza;i++)
	{
		printf("inserisci il %d.o valore ", i+1);
		scanf("%d", &array[i]); 
	}
	smallest(array, lunghezza);
}
int *smallest( int a[], int n)
{
	int x, y, temp; 
	temp=0;
	for(x=0;x<n-1;x++)
	{
		for(y=0;y<n;y++)
		{
			if(a[y]>a[y+1])
			{
				temp=a[y+1];
				a[y+1]=a[y];
				a[y]=temp;
		    }
		}
	}
	printf("Il puntatore del numero piu' piccolo dell'array e' %d", &temp); 
}
