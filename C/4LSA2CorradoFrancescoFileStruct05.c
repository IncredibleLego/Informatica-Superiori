/*
 * 4LSA2CorradoFrancescoFileStruct05.c
 * 
 * Copyright 2021 CorradoFrancesco <francesco.corrado@setificio.edu.it>
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUANTI 2

struct s_persona{
	char iCognome;
	char iNome;
	int statura;
};
typedef struct s_persona persona;

void menu(char*, int);
void inizializzaTabella(persona*, int);
void caricaTabellaManuale(persona*, int);
void caricaTabellaAutomatica(persona*, int, int, int);
void visualizzaTabella(persona*, int, char*);
void copiaTabella(persona*, persona*, int);
void leggiFile(char*);
void scriviFile(char*);
int main(){
	menu("filestruct.txt", QUANTI);
	return 0;
}

void menu(char* nomeFile, int quanti){
	int scelta;
	int min;
	int max;
	persona studentiA[quanti], studentiB[quanti];
	scelta=0;
	min=0;
	max=0;
	inizializzaTabella(studentiA, quanti);
	inizializzaTabella(studentiB, quanti);
	do{
		printf("\e[1;1H\e[2J");
		printf("1 leggi file\n");
		printf("2 scrivi file\n");
		printf("3 carica tabella\n");
		printf("4 visualizza tabelle\n");
		printf("5 copia tabella studenti in studentiCopia\n");
		printf("6: genera valori casuali nei parametri della struttura\n");
		printf("0 esci\n");
		printf("Scelta?");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("Grazie, arrivederci. F.Corrado\n");
					break;
			case 1: leggiFile(nomeFile);
					break;
			case 2: scriviFile(nomeFile);
					break;
			case 3: caricaTabellaManuale(studentiA, quanti);
					break;
			case 4: visualizzaTabella(studentiA, quanti, " tabella originale ");
					visualizzaTabella(studentiB, quanti, " tabella copia ");
					break;
			case 5: copiaTabella(studentiA, studentiB, quanti);
					break;
			case 6: printf("Inserisci il valore minimo possibile della statura (>0 <= 249): \n");
		        	do{
	        		scanf("%d", &min);
					}while((min<=0)||(min>249));
		        	printf("Inserisci il valore massimo possibile della statura (>%d <=250): \n", min);
				    do{
			       		scanf("%d", &max);
					}while((max<=min)||(max>250));
			        caricaTabellaAutomatica(studentiA, quanti, min, max);
			        break;
			default: printf("Scelta non accettabile. Rifai.\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}
void inizializzaTabella(persona* persone, int quanti){
	int i;
	i=0;
	for(i=0; i<quanti; i++){
		persone[i].iCognome=' ';
		persone[i].iNome=' ';
		persone[i].statura=0;
	}
}
void caricaTabellaManuale(persona* persone, int quanti){
	int i;
	i=0;
	for(i=0; i<quanti; i++){
		printf("Cognome?");
		scanf(" %c", &persone[i].iCognome);
		printf("Nome?");
		scanf(" %c", &persone[i].iNome);
		printf("Statura?");
		scanf("%d", &persone[i].statura);
	}
}
void visualizzaTabella(persona* persone, int quanti, char* msg){
	int i;
	i=0;
	printf("Visualizzo i dati contenuti nella%s:\n", msg);
	for(i=0; i<quanti; i++){
		printf("Studente %d: %c\t%c\t%d\n",i+1, persone[i].iCognome, persone[i].iNome, persone[i].statura);
		
	}
}
void leggiFile(char* nFile){
	
	FILE *pFile;
	pFile=NULL;
	pFile=fopen(nFile, "r");
	if(pFile!=NULL){
		
	}
	else{
		printf("Errore nell'apertura del file %s", nFile);
	}
}
void scriviFile(char* nFile){
	
}
void copiaTabella(persona* studA, persona* studB, int quanti){
	int i;
	i=0;for(i=0; i<quanti; i++){
		/*
		studB[i].iCognome=studA[i].iCognome;
		studB[i].iNome=studA[i].iNome;
		studB[i].statura=studA[i].statura;
		*/
		studB[i]=studA[i];
	}
}
void caricaTabellaAutomatica(persona* persone, int quanti, int min, int max){
	int i;
	int intervallo;
	i=0;
	intervallo=0;
	intervallo=(max-min)+1;
	for(i=0; i<quanti; i++){
	    persone[i].iCognome=rand()%26+65;
	    persone[i].iNome=rand()%26+97;
		persone[i].statura=(rand()%intervallo+min);
	}
}
