//Autore: Francesco Corrado
#include <stdio.h>
#include <math.h>

int addizione(int rea, int imm, int rea1, int imm1);
int sottrazione(int rea, int imm, int rea1, int imm1);
int moltiplicazione(int rea, int imm, int rea1, int imm1);
int divisione(int rea, int imm, int rea1, int imm1);
float root(int rea, int imm, int rea1, int imm1);
void potenza(float ra, int esponente); //Ra = radicando;

main()
{
	printf("Il programma chiede l'inserimento di due numeri immaginari e ne calcola somma, sottrazione, prodotto, quoziente, modulo e potenza della parte reale e immaginaria");
	int r, i, r1, i1, esp, somma, differenza, prodotto, quoziente; //R e I stanno per parte reale e immaginartia
	float modulo;
	printf("\n\nInserire la parte reale del primo numero: ");
	scanf("%d", &r);
	printf("\nInserire la parte immaginaria del primo numero: ");
	scanf("%d", &i);
	printf("\nInserire la parte reale del secondo numero:  ");
	scanf("%d", &r1);
	printf("\nInserire la parte immaginaria del secondo numero: ");
	scanf("%d", &i1);
	printf("\nQuanto vale l'esponente della potenza?: ");
	scanf("%d", &esp);
	addizione(r, i, r1, i1);
	sottrazione(r, i, r1, i1);
	moltiplicazione(r, i, r1, i1);
	divisione(r, i, r1, i1);
	modulo=root(r, i, r1, i1);
	potenza(modulo, esp);
}


int addizione(int rea, int imm, int rea1, int imm1)
{
	int sommaReale, sommaImmaginaria;
	sommaReale=rea+rea1;
	sommaImmaginaria=imm+imm1;
	printf("\n\nLa somma dei numeri immaginari vale: %d i(%d)", sommaReale, sommaImmaginaria);
} 

int sottrazione(int rea, int imm, int rea1, int imm1)
{
	int differenzaReale, differenzaImmaginaria;
	differenzaReale=rea-rea1;
	differenzaImmaginaria=imm-imm1;
	printf("\nLa differenza dei numeri immaginari vale: %d i(%d)", differenzaReale, differenzaImmaginaria);
}

int moltiplicazione(int rea, int imm, int rea1, int imm1)
{
	int prodottoReale, prodottoImmaginario;
	prodottoReale=rea*rea1;
	prodottoImmaginario=imm*imm1;
	printf("\nIl prodotto dei numeri immaginari vale: %d i(%d)", prodottoReale, prodottoImmaginario);
}

int divisione(int rea, int imm, int rea1, int imm1)
{
	int quozienteReale, quozienteImmaginario;
	if (rea>rea1)
	{
		quozienteReale=rea/rea1;
	}
	else
	{
		quozienteReale=rea1/rea;
	}
	if (imm>imm1)
	{
		quozienteImmaginario=imm/imm1;
	}
	else
	{
		quozienteImmaginario=imm1/imm;
	}
	printf("\nIl quoziente dei numeri immaginari (arrotondato per intero) vale: %d i(%d)", quozienteReale, quozienteImmaginario);
}

float root(int rea, int imm, int rea1, int imm1)
{
	int somma, somma1, fattore, fattore1, radicando;
	float radice;
	somma=rea+rea1;
    somma1=imm+imm1;
    fattore=somma*somma;
    fattore1=somma1*somma1;
    radicando=fattore+fattore1;
    radice=sqrt(radicando);
    printf("\nIl modulo dei numeri immaginari vale: %f", radice);
    return radice;
}

void potenza(float ra, int esponente)
{
	float potenza;
	potenza=pow( ra, esponente);
	printf("\nLa potenza del modulo vale = %f ",potenza);
}
