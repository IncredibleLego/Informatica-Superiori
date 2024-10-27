//Autore: Francesco Corrado
#include<stdio.h>
#include<time.h>

void rappresentaMatrice(int dim, int MATRICE[][dim], int min, int max);
int diagonale(int dim, int MATRICE[][dim]);
int sottostanti(int dim, int MATRICE[][dim]);
int soprastanti(int dim, int MATRICE[][dim]);

main()
{
	printf("Il programma chiede all'utente di inserire i parametri di creazione di una matrice, e procede successivamente a restituire i valori massimi della diagonale e dei numeri sopra e sotto a essa");
	int N, min, max, a, b, c, x, y;
	do
	{
		printf("\nQuanto deve essere grande la matrice?: ");
		scanf("%d", &N);
	}
	while(N<=1);
	int matrice[N][N];
	srand(time(0));
	do
	{
		printf("\nInserisci il minimo valore della matrice: ");
		scanf("%d",&min);
		printf("\nInserisci il massimo valore della matrice: ");
		scanf("%d",&max);
	}
	while (min>=max);
	rappresentaMatrice(N, matrice, min, max);
	a=diagonale(N, matrice);
	b=sottostanti(N, matrice);
	c=soprastanti(N, matrice);
	printf("\n");
	for(x=0;x<N;x++) 
	{
		printf("\n");
		for(y=0;y<N;y++)
		{
			printf("\t%d",matrice[x][y]);
		}
	}
	printf("\n\nValore massimo presente della diagonale: %d", a);
	printf("\nValore massimo presente sotto la diagonale: %d", b);
	printf("\nValore massimo presente sopra la diagonale: %d", c);
}

void rappresentaMatrice(int dim, int MATRICE[][dim], int MIN, int MAX)
{
	{
	int riga,col,range=(MAX-MIN)+1;
	for(riga=0;riga<dim;riga++) 
	{
		for(col=0;col<dim;col++) 
		{
			MATRICE[riga][col]=(rand()%range+MIN);
		}
	}
}

}

int diagonale(int dim, int MATRICE[][dim])
{
	int x, y, massimo;
	massimo=MATRICE[0][0];
    for(y=0;y<dim;y++)
	{
		if(MATRICE[x][y]>massimo)
		{
			massimo=MATRICE[x][y];
		}
		x++;
	}
	return massimo;
}

int sottostanti(int dim, int MATRICE[][dim])
{
	int riga, col, massimo;
	massimo=MATRICE[1][0];
	for(riga=1;riga<dim;riga++)
	{
		for(col=0;col<dim;col++)
		{   
		if (riga>col)
		{
			if(MATRICE[riga][col]>massimo)
			{
				massimo=MATRICE[riga][col];
			}
		}
		}
	}
	return massimo;
}

int soprastanti(int dim, int MATRICE[][dim])
{
	int riga, col, massimo;
	massimo=MATRICE[0][1];
	for(riga=0;riga<dim;riga++)
	{
		for(col=1;col<dim;col++)
		{   
		if (col>riga)
		{
			if(MATRICE[riga][col]>massimo)
			{
				massimo=MATRICE[riga][col];
			}
		}
		}
	}
	return massimo;
}
