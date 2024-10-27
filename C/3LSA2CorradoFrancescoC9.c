//Autore: Francesco Corrado
#include <stdio.h>

int input(int n);
void calcolo(int n, char m[n][n]);
void output(int n, char m[n][n]);

main()
{
	int N;
	printf("Il programma chiede all'utente la lunghezza di una matrice quadrata, per poi disegnare la stessa con le diagonali contrassegnate da delle 'x'");
	N=input(0);
	char matrice[N][N];
	calcolo(N, matrice);
	output(N, matrice);
}

int input(int n)
{
	do
	{
		printf("\nQuale e' la dimensione della matrice quadrata?: ");
		scanf("%d", &n);
		if (n<2)
		{
			printf("\nErrore: il valore inserito deve essere maggiore o uguale a 2 perche' si possa disegnare una matrice.");
		}
	}
	while(n<2);
}

void calcolo(int n, char m[n][n])
{
	int x, y;
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			m[x][y]='-';
		}
	}
	for(x=0; x<n; x++)
	{
		m[x][x]='x';
		y=n-1-x;
		m[x][y]='x';
	}
}

void output(int n, char m[n][n])
{
	int x, y;
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			printf("%c ", m[x][y]);
		}
		printf("\n");
	}
}
