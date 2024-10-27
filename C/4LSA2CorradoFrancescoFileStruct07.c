/*
 * 4LSA2CorradoFrancescoFileStruct07.c
 * 
 * Copyright 2021 Corrado Francesco <francesco.corrado@setificio.edu.it>
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUANTI 2
#define MIN 1
#define MAX 250

struct s_persona{
	char iCognome;
	char iNome;
	int statura;
	float peso;
};
typedef struct s_persona persona;

void menu(char*, char*, int);
void caricaTabella(persona*, int, char, int, int);
void copiaTabella(persona*, persona*, int);
void inizializzaTabella(persona*, int);
int inputDato(char*, char, int, int);
void leggiFile(char*);
void scriviFile(char*, char*, char, int, int);
void visualizzaTabella(persona*, int, char*);
void copiaFile(char*, char*);
void svuotaFile(char*);
int main(){
	menu("filestruct.dat", "fileCopia.dat", QUANTI);
	srand(time(NULL));
	return 0;
}
void menu(char* nomeFileA, char* nomeFileB, int quanti){
	int scelta, min, max;
	persona studentiA[quanti], studentiB[quanti];
	scelta=0, min=0, max=0;
	inizializzaTabella(studentiA, quanti);
	inizializzaTabella(studentiB, quanti);
	do{
		printf("\e[1;1H\e[2J");
		printf("1 leggi file\n");
		printf("2 inserisci statura minima e massima\n");
		printf("3 scrivi file\n");
		printf("4 appendi file\n");
		printf("5 copia il file %s nel file %s\n", nomeFileA, nomeFileB);
		printf("6 svuota il file %s\n", nomeFileA);
		printf("7 elimina i file\n");
		printf("0 esci\n");
		printf("Scelta?");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("Grazie, arrivederci. F.Corrado\n");
					break;
			case 1: leggiFile(nomeFileA);
			        leggiFile(nomeFileB);
					break;
			case 2: min=inputDato("Inserisci la statura minima", 'a', MIN, MAX);
					max=inputDato("Inserisci la statura massima", 'a', min, MAX);
					break;
			case 3: if(min!=0 &&max!=0)
						scriviFile(nomeFileA, "wb", 'm', min, max);
					else
						printf("Prima devi impostare la statura minima e massima, punto 2 del menu'.\n");
					break;
			case 4: if(min!=0 &&max!=0)
						scriviFile(nomeFileA, "ab", 'm', min, max);
					else
						printf("Prima devi impostare la statura minima e massima, punto 2 del menu'.\n");
					break;
			case 5: copiaFile(nomeFileA, nomeFileB);
			        break;
			case 6: svuotaFile(nomeFileA);
			        break;
			case 7: remove(nomeFileA); 
		         	remove(nomeFileB); 
			        printf("Tutti i file sono stati eliminati con successo\n");
			        break;
			default: printf("Scelta non accettabile. Rifai.\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}
//caricaTabella(array di persona, n° elementi dell'array, manuale==0 o automatico !=0', min statura, max statura)
void caricaTabella(persona* persone, int quanti, char opzione, int min, int max){
	int i;
	i=0;
	srand(time(NULL));
	for(i=0; i<quanti; i++){
		if(opzione=='m'){	
			printf("Cognome?");
			scanf(" %c", &persone[i].iCognome);
			printf("Nome?");
			scanf(" %c", &persone[i].iNome);
			printf("Statura?");
			scanf("%d", &persone[i].statura);
			printf("Peso?");
			scanf("%f", &persone[i].peso);
		}
		if(opzione=='a'){
			persone[i].iCognome=rand()%26+65;
			persone[i].iNome=rand()%26+97;
			persone[i].statura=rand()%(max-min+1)+min;
			persone[i].peso=rand()%(max-min+1)+min;
		}
	}
	if(opzione=='a'){
		printf("Caricamento automatico tabella terminato.\n");
	}
}
void inizializzaTabella(persona* persone, int quanti){
	int i;
	i=0;
	for(i=0; i<quanti; i++){
		persone[i].iCognome=' ';
		persone[i].iNome=' ';
		persone[i].statura=0;
		persone[i].peso=0;
	}
}
int inputDato(char* msg, char sex, int min, int max){
	int dato;
	dato=0;
	do{
		printf("%s, compres%c tra %d e %d inclusi: ", msg, sex, min, max);
		scanf("%d", &dato);
	}while((dato<min)||(dato>max));
	return dato;
}
void leggiFile(char* nFile){
	FILE *pFile;
	persona individuo;
	pFile=NULL;
	inizializzaTabella(&individuo, 1);
	pFile=fopen(nFile, "rb");
	if(pFile!=NULL){
		while(fread(&individuo, sizeof(persona), 1, pFile)>0){
			printf("Cognome: %c\t", individuo.iCognome);
			printf("Nome: %c\t", individuo.iNome);
			printf("Statura: %d\n", individuo.statura);
			printf("Peso: %f\n", individuo.peso);
		}
		fclose(pFile);	
	}
	else{
		printf("Errore nell'apertura del file %s", nFile);
	}
}
void scriviFile(char* nomeFile, char* tipo, char modo, int min, int max){
	FILE* pFile;
	persona individuo;
	pFile=NULL;
	/*individuo.iCognome=' ';
	individuo.iNome=' ';
	individuo.statura=0;*/
	inizializzaTabella(&individuo, 1);
	pFile=fopen(nomeFile, tipo);
	if(pFile!=NULL){
		caricaTabella(&individuo, 1, modo, min, max);
		fwrite(&individuo, sizeof(persona), 1, pFile);
		fclose(pFile);	
	}
	else{
		printf("Errore durante l'apertura del file %s.\n", nomeFile);
	}
}
void copiaFile(char* nomeFile1, char* nomeFile2)
{
	FILE* pFileA=NULL;
	FILE* pFileB=NULL;
	persona individuo;
	char copiaCarattere;
	pFileA=fopen(nomeFile1, "rb");
	pFileB=fopen(nomeFile2, "wb");
	inizializzaTabella(&individuo, 1);
	copiaCarattere=' ';
	if((pFileA!=NULL)&&(pFileB!=NULL)){
		while(fread(&individuo, sizeof(persona), 1, pFileA)>0)
		{
			fwrite(&individuo, sizeof(persona), 1, pFileB);
		}
				printf("Copia del file %s nel file %s e' avvenuta con successo", nomeFile1, nomeFile2);
		fclose(pFileA);
		fclose(pFileB);
	}
	else{
		if(pFileA==NULL){
			printf("Errore durante l'apertura del file origine %s.\n", nomeFile1);
		}
		if(pFileB==NULL){
			printf("Errore durante l'apertura del file destinazione %s.\n", nomeFile2);
		}
	}
}
void svuotaFile(char* nomeFile){
	FILE* pFile;
	persona individuo;
	pFile=NULL;
//	inizializzaTabella(&individuo, 1);
	pFile=fopen(nomeFile, "wb");
	if(pFile!=NULL){
		printf("Il file %s e' stato svuotato con successo\n", nomeFile);
		fclose(pFile);	
	}
	else{
		printf("Errore durante l'apertura del file %s.\n", nomeFile);
	}
}
