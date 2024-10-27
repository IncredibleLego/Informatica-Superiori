//Autore: Francesco Corrado
#include<stdio.h>
#include<time.h>
void valoriMatrice(int dim, int matrice[][dim]);

main() {
	int n;
	int matrice[n][n];
	printf("Quanto deve essere grande la matrice? :");
	scanf("%d", n);
	printf("\n%d", n);
	valoriMatrice(n,matrice);
}


void valoriMatrice(int dim, int matr[][dim]) { //funzione per inserire valori casuali alla matrice
	int row,col;
	for(row=0; row<dim; row++) { //for per le righe
		for(col=0; col<dim; col++) { //for per le colonne
			matr[row][col]=(rand()%101);
		}
	}
}
