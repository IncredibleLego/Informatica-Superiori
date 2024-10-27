
/*

#### ISTRUZIONI ####
Scrivi un programma che (VEDI ESEMPIO SOTTO):
1) Chiede il numero di alunni.
2) Per ogni alunno, chiede cognome, nome e i voti in informatica, matematica e fisica.
3) I dati inseriti al punto 2 devono essere memorizzati usando una struttura (che chiamrai "alunni").
4) L'elenco degli alunni promossi viene memorizzato all'interno della matrice (che chiamerai "tabellone").
   In questa matrice deve essere memorizzato il numero di elenco dell'alunno e la media dei tre voti.
   Attenzione: la matrice deve contenere solo i dati degli alunni promossi (quelli con media >=6)
5) Viene stampato il tabellone come nell'esempio

L'uso delle funzioni non è obbligatorio ma permette di prendere un voto superiore al 7, in base a quante,
e come, sono state utilizzate.
Se vuoi puoi anche ordinare alfabeticamente il tabellone.


#### ESEMPIO ####
 Inserisci il numero di alunni presenti.
 Numero di alunni : 5

 ALUNNO 1
 cognome : Barbarossa
 nome    : Federico
 voto informatica : 3
 voto matematica  : 5
 voto fisica      : 2

 ALUNNO 2
 cognome : Einstein
 nome    : Albert
 voto informatica : 8
 voto matematica  : 10
 voto fisica      : 10

 ALUNNO 3
 cognome : Vivaldi
 nome    : Antonio
 voto informatica : 4
 voto matematica  : 7
 voto fisica      : 7

 ALUNNO 4
 cognome : Manzoni
 nome    : Alessandro
 voto informatica : 8
 voto matematica  : 6
 voto fisica      : 6

 ALUNNO 5
 cognome : Montalbano
 nome    : Salvo
 voto informatica : 8
 voto matematica  : 3
 voto fisica      : 2

 Numero alunni promossi : 3
 Elenco alunni promossi :

 #  Cognome              Nome                  Media
 ---------------------------------------------------
  2 Einstein             Albert                9.3
  3 Vivaldi              Antonio               6.0
  4 Manzoni              Alessandro            6.7
*/

//Autore: Francesco Corrado
#include <stdio.h>
#include <string.h>
struct alunni
{
	char nome[30];
	char cognome[30];
	int mate;
	int info;
	int fisica;
}a;

main()
{
	int i, n, nelenco=0;
	struct alunni a[i];
	printf("Il programma chiede il numero di alunni e successivamente i voti in 3 materie, per stabilire i sufficienti e gli insufficienti");
	do
	{
		printf("\n\nInserire il numero di alunni: ");
	    scanf("%d", &n);
	}
	while(n<0);
	int tabellone[n][2];
	for(i=0;i<n;i++)
	{
		nelenco++;
		int media;
		printf("\nInserire il nome dell'alunno: ");
		scanf(" %[^\n]s ", a[i].nome);
		printf("Inserire il cognome dell'alunno: ");
		scanf(" %[^\n]s ", a[i].cognome);
		do
		{
			printf("Inserire il voto di matematica dell'alunno: ");
		    scanf(" %d ", &a[i].mate);
		}while((a[i].mate<1)||(a[i].mate>10));
		do
		{
			printf("\nInserire il voto di informatica dell'alunno: ");
		    scanf(" %d ", &a[i].info);
		}while((a[i].info<1)||(a[i].info>10));
		do
		{
			printf("\nInserire il voto di fisica dell'alunno: ");
		    scanf(" %d ", &a[i].fisica);
		}while((a[i].fisica<1)||(a[i].fisica>10));
		media=(a[i].mate+a[i].info+a[i].fisica)/n;
		printf("\nLa media di %s e' uguale a %d", a[i].nome, media);
		if (media>6)
		{
			printf("\nL'alunno e' stato promosso!");
			tabellone[i][1]=a[i].nome;
			tabellone[i][2]=media;
		}
	}
}
