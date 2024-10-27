/*
 * 4LSA2CorradoFrancescoFileStruct01.c
 * 
 * Copyright 2021 Corrado Francesco <francesco.corrado@setificio.edu.it>
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
void caricaTabella(persona*, int);
void visualizzaTabella(persona*, int);
void leggiFile(char*);
void scriviFile(char*);
int main(){
	menu("filestruct.txt", QUANTI);
	return 0;
}

void menu(char* nomeFile, int quanti){
	int scelta;
	persona studenti[quanti];
	scelta=0;
	do{
		printf("\e[1;1H\e[2J");
		printf("\n1 leggi file\n");
		printf("2 scrivi file\n");
		printf("3 carica vettore\n");
		printf("4 visualizza vettore\n");
		printf("0 esci\n");
		printf("Scelta?");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("Grazie, arrivederci. R.Zoni\n");
					break;
			case 1: leggiFile(nomeFile);
					break;
			case 2: scriviFile(nomeFile);
					break;
			case 3: caricaTabella(studenti, quanti);
					break;
			case 4: visualizzaTabella(studenti, quanti);
					break;
			default: printf("Scelta non accettabile. Rifai.\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}

void caricaTabella(persona* persone, int quanti){
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
void visualizzaTabella(persona* persone, int quanti){
	int i;
	i=0;
	for(i=0; i<quanti; i++){
		printf("%d ", i+1);
		printf("Cognome: %c\t", persone[i].iCognome);
		printf("Nome: %c\t", persone[i].iNome);
		printf("Statura: %d\n", persone[i].statura);
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
