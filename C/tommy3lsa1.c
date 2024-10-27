#include <stdio.h>
#include <time.h>
void riempiMatrice(int r, int c, int matr[][c], int minimo, int massimo);
void modificaMatrice(int r, int c, int x[][c], int y[][c]);
void mostraMatrice(int r, int c, int matr[][c], int y[][c]);
void ordinaMatrice(int r, int c, int x[][c]);

main()
{
	int n, m;
	do
	{
		printf("\nInserire il numero di righe della matrice(>1): ");
		scanf("%d", &n);
		printf("\nInserire il numero di colonne della matrice(>1): ");
		scanf("%d", &m);
	}while((n<=1)||(m<=1));
	int mat1[n][m];
	riempiMatrice(n, m, mat1, 0, 8);
	int mat2[n][m];
	modificaMatrice(n, m, mat1, mat2);
	mostraMatrice(n, m, mat1, mat2);
	ordinaMatrice(n, m, mat1);
	
}
void riempiMatrice(int r, int c, int matr[][c], int minimo, int massimo)
{
	int row, col, range;
	range=(massimo-minimo)+1;
	srand(time(0));
	for(row=0;row<r;row++)
	{
		for(col=0;col<c;col++)
		{
			matr[row][col]=(rand()%range+minimo);
		}
	}
}
void modificaMatrice(int r, int c, int x[][c], int y[][c])
{
	int row, col, temp;
	for(row=0;row<r;row++)
	{
		for(col=0;col<c;col++)
		{
			y[row][col]=x[row][col];
		}
	}
	for(row=0;row<r;row++)
	{
		for(col=0;col<c;col++)
		{
			if((row==0)||(row==r-1)||(col==0)||(col==c-1))
			{
				y[row][col]=(-1)*(y[row][col]);
			}
		}
	}
}
void mostraMatrice(int r, int c, int x[][c], int y[][c])
{
	int row, col;
	printf("\nMatrice originaria mat1: ");
	for(row=0;row<r;row++)
	{
		printf("\n");
		for(col=0;col<c;col++)
		{
			printf("\t%d", x[row][col]);
		}
	}
	printf("\nMatrice modificata mat2: ");
	for(row=0;row<r;row++)
	{
		printf("\n");
		for(col=0;col<c;col++)
		{
			printf("\t%d", y[row][col]);
		}
	}
}
void ordinaMatrice(int r, int c, int x[][c])
{
	int row1, col1, col2, temp, row, col;
	for(row1=0; row1<r; row1++){
		for(col1=0; col1<c; col1++){
			for(col2=col1; col2<c; col2++){
				if(x[row1][col2]<x[row1][col1]){
					temp=x[row1][col1];	//temp=valore grande
					x[row1][col1]=x[row1][col2];	//pos iniziale al valore piccolo
					x[row1][col2]=temp;	//pos più in là al v grande
				}
			}
		}
	}
	printf("\nMatrice ordinata mat1: ");
	for(row=0;row<r;row++)
	{
		printf("\n");
		for(col=0;col<c;col++)
		{
			printf("\t%d", x[row][col]);
		}
	}
}
