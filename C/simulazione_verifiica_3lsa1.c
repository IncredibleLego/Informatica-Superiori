//Autore: Francesco Corrado
#include <stdio.h>
#include <time.h>

void riempiMatrice(int altezza, int lunghezza, int matrice[][lunghezza], int min, int max);
void mostraMatrice(int altezza, int lunghezza, int matrice[][lunghezza]);
void modificaMatrice(int altezza, int lunghezza, int matrice[][lunghezza], int matriceModificata[][lunghezza]);

main()
{
	int n, m;
	printf("Il programma chiede le dimensioni di una matrice e restituisce");
	printf("\n\nInserisci il numero di righe della matrice: ");
	scanf("%d", &n);
	printf("\nInserisci il numero delle colonne della matrice: ");
	scanf("%d", &m);
	printf("\n\nLe righe della matrice (n) sono: %d ", n);
	printf("\nLe colonne della matrice (m) sono: %d ", m);
	int mat1[n][m];
	int mat2[n][m];
	srand(time(0));
	riempiMatrice(n, m, mat1, 0, 8);
	printf("\n\nMatrice originaria mat1: ");
	mostraMatrice(n, m, mat1);
	modificaMatrice(n, m, mat1, mat2);
	printf("\n\nMatrice modificata mat2: ");
	mostraMatrice(n, m, mat2);
	
}

void riempiMatrice(int altezza, int lunghezza, int matrice[][lunghezza], int min, int max)
{
	int row,col,range=(max-min)+1;
	for(row=0;row<altezza;row++) 
	{
		for(col=0;col<lunghezza;col++) 
		{
			matrice[row][col]=(rand()%range+min);
		}
	}
}

void mostraMatrice(int altezza, int lunghezza, int matrice[][lunghezza])
{
	int x, y;
	for(x=0;x<altezza;x++) 
	{
		printf("\n");
		for(y=0;y<lunghezza;y++)
		{
			printf("\t%d",matrice[x][y]);
		}
	}
}

void modificaMatrice(int altezza, int lunghezza, int matrice[][lunghezza], int matriceModificata[][lunghezza])
{
	int row,col;
	for(row=0;row<lunghezza;row++)
	{
		matriceModificata[row][altezza]=((matrice[row][altezza])*(-1));
	}
	for(row=1;row<altezza-1;row++) 
	{
		for(col=0;col<lunghezza;col++) 
		{
			if((col==0)||(row==lunghezza))
			{
				matriceModificata[row][col]=(matrice[row][col])*(-1);
			}
			else
			{
				matriceModificata[row][col]=matrice[row][col];
			}
		}
	}
	for(row=altezza-1;row<lunghezza;row++)
	{
		matriceModificata[row][lunghezza]=((matrice[row][lunghezza])*(-1));
	}
}




