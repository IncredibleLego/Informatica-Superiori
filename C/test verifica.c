//Autore: Francesco Corrado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(char*, char*, char*, char*);
void leggiFile(char*);
void scriviFileTerminatore(char*, char*);


int main(){
	char *fileUno, *fileDue, *fileCoppie, *fileFrequenze;
	fileUno="uno.txt";
	fileDue="due.txt";
	fileCoppie="coppie.txt";
	fileFrequenze="frequenze.txt";
	srand((unsigned)time(NULL));
	menu(fileUno, fileDue, fileCoppie, fileFrequenze);
	getchar();
	return 0;
}

void menu(char* fileUno, char* fileDue, char* fileCoppie, char* fileFrequenze){
	int scelta;
	scelta=0;
	do{
		printf("\e[1;1H\e[2J");
		printf("\nScegli l'operazione che vuoi eseguire:\n");
		printf("0: esci dal programma");
		printf("1: leggi i file uno.txt due.txt coppie.txt e frequenze.txt\n");
		printf("2: la funzione di fra la pagliaccia\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 1: leggiFile(fileUno);
			        leggiFile(fileDue);
			        leggiFile(fileCoppie);
			        leggiFile(fileFrequenze);
			        break;
			case 2: scriviFileTerminatore(fileUno, "w");
			        break;
			default: if (scelta!=0)
			        printf("\nScelta non accettabile. Rifai.\n\n");
		}
	}while(scelta!=0);
	getchar();
	getchar();
}

void leggiFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	carattere=' ';
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		printf("\nContenuto del file %s: \n", nomeFile);
		printf("\n\nLMAOO\n");
		while (fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
		printf("\n");
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s", nomeFile);
	}
	
}

void scriviFileTerminatore(char* nomeFile, char* terminatore){
	FILE *pFile;
	char carattere;
	char ciao;
	ciao= *terminatore;
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	printf("Per terminare usa il carattere %c ", terminatore);
	if(pFile!=NULL){
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!=ciao);
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s ", nomeFile);
	}
}










