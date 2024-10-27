//Autore:Francesco Corrado
#include <stdio.h>
#include <time.h>

void riempiMatrice(int N, int M, int matrice[][M]);
void mostraMatrice(int N, int M, int matrice[][M]);
void modificaMatrice(int N, int M, int matrice[][M], int modificata[][M]);
void ordinaMatrice(int N, int M, int matrice[][M]);

main()
{
	srand(time(0));
	int n, m;
	printf("Il programma crea una matrice di numeri dispari generati tra 1 e 9 e poi la modifica");
	do
	{
		printf("\nInserisci la dimensione n della matrice: ");
	    scanf("%d", &n);
	    printf("\nInserisci la dimensione m della matrice: ");
	    scanf("%d", &m);
	}while(n<=1||m<=1);  //Ho richiesto l'input nel main per una questione di tempo
	printf("La matrice avra' dimensione %d e %d", n, m);
	int mat1[n][m];
	int mat2[n][m];
	riempiMatrice(n, m, mat1);
	printf("\n\nMatrice iniziale: ");
	mostraMatrice(n, m, mat1);
	modificaMatrice(n, m, mat1, mat2);
	printf("\n\nMatrice modificata: ");
	mostraMatrice(n, m, mat2);
	ordinaMatrice(n, m, mat1);
	printf("\n\nMatrice ordinata: ");
	mostraMatrice(n, m, mat1);
	printf("\n\n\nIl programma e' terminato.");
	
	
}

void riempiMatrice(int N, int M, int matrice[][M])
{
	int row, col, range;
	range=(9-1)+1;
	for(row=0;row<N;row++)
	{
		for(col=0;col<M;col++)
		{
			do
			{
				matrice[row][col]=(rand()%range+1);
			}while (matrice[row][col]%2==0);
		}
	}
}

void mostraMatrice(int N, int M, int matrice[][M])
{
	int row, col;
	for(row=0;row<N;row++)
	{
		printf("\n");
		for(col=0;col<M;col++)
		{
			printf("\t%d", matrice[row][col]);
		}
	}
}

void modificaMatrice(int N, int M, int matrice[][M], int modificata[][M])
{
	int row, col;
	for(row=0;row<N;row++)
	{
		for(col=0;col<M;col++)
		{
			if((row==0)||(row==N-1)||(col==0)||(col==M-1))
			{
				if(matrice[row][col]==5)
				{
					modificata[row][col]=0;
				}
				if(matrice[row][col]<5)
				{
					modificata [row][col]=(-1);
				}
				if(matrice[row][col]>5)
				{
					modificata[row][col]=(1);
				}
			}
			else
			{
				if(matrice[row][col]==5)
				{
					modificata[row][col]=0;
				}
				if(matrice[row][col]<5)
				{
					modificata [row][col]=(1);
				}
				if(matrice[row][col]>5)
				{
					modificata[row][col]=(-1);
				}
			}
		}
	}
}

void ordinaMatrice(int N, int M, int matrice[][M])
{
	int row, col, row1, row2, col1, temp;
	for(row1=0;row1<N;row1++)
	{
		for(row2=0;row2<N;row2++)
		{
			for(col1=0;col1<M;col1++)
			{
				if(matrice[row1][col1]<matrice[row2][col1])
				{
					temp=matrice[row1][col1];
					matrice[row1][col1]=matrice[row2][col1];
					matrice[row2][col1]=temp;
				}
			}
		}
	}
}
