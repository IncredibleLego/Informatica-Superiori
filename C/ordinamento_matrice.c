//Autore: Francesco Corrado
#include <stdio.h>
#include <time.h>

void creaMatrice(int dim, int matrice[][dim], int min, int max);
void ordinaMatrice(int dim, int matrice[][dim], int min, int max, int ordinata[][dim]);


main()
{
	int minimo, massimo, N, r, c;
	printf("Questo programma ordina una data matrice");
	N=imput();
	int matrice[N][N];
	int ordinata[N][N];
	srand(time(0));
	do
	{
	printf("\nInserisci il valore del minimo della matrice: ");
	scanf("%d",&minimo);
	printf("\nInserisci il valore del massimo della matrice: ");
	scanf("%d",&massimo);
    }
	while (minimo>=massimo);
	creaMatrice(N, matrice, minimo, massimo);
	printf("\n\nMatrice iniziale: ");
	for(r=0;r<N;r++) 
	{
		printf("\n");
		for(c=0;c<N;c++)
		{
			printf("\t%d",matrice[r][c]);
		}
	}
	printf("\n\nMatrice ordinata: ");
	ordinaMatrice(N, matrice, minimo, massimo, ordinata);
	for(r=0;r<N;r++) 
	{
		printf("\n");
		for(c=0;c<N;c++)
		{
			printf("\t%d",ordinata[r][c]);
		}
	}

}

imput()
{
	int n;
	do
	{
		printf("\nInserisci il valore della dimensione della matrice: ");
		scanf("%d", &n);
	}
	while(n<=1);
}

void creaMatrice(int dim, int matrice[][dim], int min, int max)
{
	int row,col,range=(max-min)+1;
	for(row=0;row<dim;row++) 
	{
		for(col=0;col<dim;col++) 
		{
			matrice[row][col]=(rand()%range+min);
		}
	}
}

void ordinaMatrice(int dim, int matrice[][dim], int min, int max, int ordinata[][dim])
{
	int row, col, numero, x, y;
	x=0;
	y=0;
	for(numero=min;numero<max+1;numero++)
	{
		for(row=0;row<dim;row++)
		{
			for(col=0;col<dim;col++)
			{
				if (matrice[row][col]==numero)
				{
					ordinata[x][y]=numero;
					x++;
					if (x=dim)
					{
						y++;
						x=0;
					}
				}
			}
		}
	}
}
