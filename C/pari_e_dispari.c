//Autore: Francesco Corrado
#include <stdio.h>
#include <time.h>

void creaMatrice(int n, int matrice[][n]);
void stampaMatrice(int n, int matrice[][n]);
void ordinaMatrice(int n, int matrice[][n], int ordinata[][n]);
void pariDispari(int n, int ordinata[][n], int scala[][n]);

main()
{
	int N, r, c;
	printf("Il programma chiede l'inserimento di una matrice quadrata e genera una matrice con i numeri ordinati, prima i pari");
	do
	{
		printf("\nInserici la dimensione della matrice quadrata: ");
		scanf("%d", &N);
	}
	while(N<1);
	int matr[N][N];
	int matrOrd[N][N];
	int matrPari[N][N];
	creaMatrice(N, matr);
	printf("\n\nMatrice iniziale: ");
	stampaMatrice(N, matr);
	ordinaMatrice(N, matr, matrOrd);
	printf("\n\nMatrice ordinata: ");
	stampaMatrice(N, matrOrd);
	pariDispari(N, matrOrd, matrPari);
	printf("\n\nMatrice pari/dispari: ");
	stampaMatrice(N, matrPari);

	
}

void creaMatrice(int n, int matrice[][n])
{
	int row, col, range;
	int min=0;
	int max=100;
	range=(max-min)+1;
	srand(time(0));
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			matrice[row][col]=(rand()%range+min);
		}
	}
}

void stampaMatrice(int n, int matrice[][n])
{
	int row,col;
	for(row=0;row<n;row++)
	{
		printf("\n");
		for(col=0;col<n;col++)
		{
			printf("\t%d", matrice[row][col]);
		}
	}
}

void ordinaMatrice(int n, int matrice[][n], int ordinata[][n])
{
	int row, col, numero, x, y;
	x=0;
	y=0;
	int min=0;
	int max=100;
	for(numero=min;numero<max+1;numero++)
	{
		for(row=0;row<n;row++)
		{
			for(col=0;col<n;col++)
			{
				if (matrice[row][col]==numero)
				{
					ordinata[x][y]=numero;
					x++;
					if (x=n)
					{
						y++;
						x=0;
					}
				}
			}
		}
	}
}

void pariDispari(int n, int ordinata[][n], int scala[][n])
{
	int row, col;
	int x=0;
	int y=0;
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			if(ordinata[row][col]%2==0)
			{
				scala[x][y]=ordinata[row][col];
				x++;
				if(x=n)
				{
					y++;
					x=0;
				}
			}
		}
	}
	for(row=0;row<n;row++)
	{
		for(col=0;col<n;col++)
		{
			if(ordinata[row][col]%2!=0)
			{
				scala[x][y]=ordinata[row][col];
				x++;
				if(x=n)
				{
					y++;
					x=0;
				}
			}
		}
	}
}
