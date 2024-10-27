//Autore: Francesco Corrado
#include <stdio.h>
#include <time.h>

main()
{
	printf("Il programma chiede l'inserimento di due matrici e restituisce entrambe le matrici e la matrice somma");
    int A=1, B=1;
    int Matrice1[A][B], Matrice2[A][B], Matrice_unione[A][B];
    int n,x,j;
    do 
	{
    printf("\n\nQuanto sara' grande la matrice?: ");
    scanf("%d", &n);
    } 
	while (n<=1);
    int min, max, MIN, MAX;  
	do
	{
		printf("\nInserisci il minimo valore della Prima matrice: ");
		scanf("%d",&min);
		printf("\nInserisci il massimo valore della Prima matrice: ");
		scanf("%d",&max);
	}
	while (min>=max);
	srand(time(0));
	for (x=0;x<n;x++) 
	{
    for(j=0;j<n;j++)
	{
		do
		{
			Matrice1[x][j]=(rand()%(max-min+1)+min);
		}
		while((Matrice1[x][j]<min)||(Matrice1[x][j]>max));
	}
	}
    do
	{
		printf("\nInserisci il minimo valore della Seconda matrice: ");
		scanf("%d",&MIN);
		printf("\nInserisci il massimo valore della Seconda matrice: ");
		scanf("%d",&MAX);
	}
	while (min>=max);
	srand(time(0));
	for (x=0;x<n;x++) 
	{
    for(j=0;j<n;j++)
	{
		do
		{
			Matrice2[x][j]=(rand()%(MAX-MIN+1)+MIN);
		}
		while((Matrice2[x][j]<MIN)||(Matrice2[x][j]>MAX));
	}
	}
    printf("\nPrima matrice: ");
    for (x=0;x<n;x++) 
	{
    printf("\n");
    for(j=0;j<n;j++) 
        printf("\t%d", Matrice1[x][j]);                
    }
    printf("\nSwconda matrice: ");
    for (x=0;x<n;x++) 
	{
    printf("\n");
    for(j=0;j<n;j++) 
        printf("\t%d", Matrice2[x][j]);                
    }
   for (x=0;x<n;x++) 
   {
   for (j=0;j<n;j++) 
       Matrice_unione[x][j]=Matrice1[x][j]+Matrice2[x][j];               
    }
    printf("\nMatrice somma: ");
    for (x=0;x<n;x++) 
	{
    printf("\n");
    for(j=0;j<n;j++) 
        printf("\t%d", Matrice_unione[x][j]);                
    }
}
