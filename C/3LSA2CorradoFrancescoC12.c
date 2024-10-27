//Autore: Francesco Corrado
#include <stdio.h>
#include <math.h>

int addizione(int rea, int imm, int rea1, int imm1);
int sottrazione(int rea, int imm, int rea1, int imm1);
int moltiplicazione(int rea, int imm, int rea1, int imm1);
int divisione(int rea, int imm, int rea1, int imm1);
float root(int rea, int imm, int rea1, int imm1);
void potenza(float rad);

main()
{
	int r, i, r1, i1, somma, differenza, prodotto, quoziente; //R e I stanno per parte reale e immaginartia
	float radice;
	printf("\nInserire la parte reale del primo numero: ");
    scanf("%d", &r);
    printf("\nInserire la parte immaginaria del primo numero: ");
    scanf("%d", &i);
    printf("\nInserire la parte reale del secondo numero:  ");
    scanf("%d", &r1);
    printf("\nInserire la parte immaginaria del secondo numero: ");
    scanf("%d", &i1);
    somma=addizione(r, i, r1, i1);
    differenza=sottrazione(r, i, r1, i1);
    prodotto=moltiplicazione(r, i, r1, i1);
    quoziente=divisione(r, i, r1, i1);
    radice=root(r, i, r1, i1);
    potenza(radice);
}
