#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void menu(char*, char*, char*, char*);
void leggiFile(char*);
void scriviFile(char*, char*);
void svuotaFile(char*);
void copiaFile(char*, char*);

int main(){
	char *fileUno, *fileDue, *fileCoppie, *fileFrequenze;
	fileUno="uno.txt";
	fileDue="due.txt";
	fileCoppie="coppie.txt";
	fileFrequenze="frequenze.txt";
//	srand((unsigned)time=(NULL)); //Guardato
	menu(fileUno, fileDue, fileCoppie, fileFrequenze);
	getchar();
	return 0;
}

void menu(char* fileUno, char* fileDue, char* fileCoppie, char* fileFrequenze){
	int scelta;
	scelta=0;
	do{
		system("cls");
		printf("\nScegli una delle seguenti opzioni: \n");
		printf("0: chiudi il programma\n");
		printf("1: leggi i file uno.txt due.txt coppie.txt frequenze.txt\n");
		printf("2: scrivi nel file uno.txt fino all'inserimento del carattere ; \n");
		printf("3: scrivi nel file due.txt fino all'inserimento del carattere . \n");
		printf("4: svuota i file uno.txt e due.txt\n");
		printf("5: elimina i file uno.txt e due.txt\n");
		printf("6: copia il file uno.txt nel file due.txt\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 1: leggiFile(fileUno);
			        leggiFile(fileDue);
			        leggiFile(fileCoppie);
			        leggiFile(fileFrequenze);
			        break;
			case 2: scriviFile(fileUno, ";");
			        break;
			case 3: scriviFile(fileDue, ".");
			        break;
			case 4: svuotaFile(fileUno);
			        svuotaFile(fileDue);
			        break;
			case 5: remove(fileUno);
			        remove(fileDue);
			        printf("I file sono stati rimossi con successo\n");
			        break;
			case 6: copiaFile(fileUno, fileDue);
			        break;
			default: if (scelta!=0)
			         printf("Risultato non accettabile, rifai\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}

void leggiFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	carattere=' ';
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		printf("\nContenuto del file %s: \n", nomeFile);
		while(fscanf(pFile, "%c", &carattere)>0){          //Guardato
			printf("%c", carattere);                       //Guardato
		}
		printf("\n");
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s \n", nomeFile);
	}
}

void scriviFile(char* nomeFile, char* fine){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	carattere=' ';
	char finale;
	finale= *fine;
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		printf("Inserire il testo (deve terminare con il carattere %s) da immettere in %s \n", fine, nomeFile);
		do{
			scanf("%c", &carattere);            //Guardato
			fprintf(pFile, "%c", carattere);    //Guardato
		}while(carattere!=finale);              //Guardato
		printf("\n");
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s \n", nomeFile);
	}
}

void svuotaFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	fclose(pFile);
	printf("Il file %s e' stato svuotato con successo\n", nomeFile);
}

void copiaFile(char* nomeFile, char* nomeFile2){
	FILE* pFile;
	FILE* pFile2;
	pFile=NULL;
	pFile2=NULL;
	char carattere;
	carattere=' ';
	pFile=fopen(nomeFile, "r");
	pFile=fopen(nomeFile, "w");
	if((pFile!=NULL)&&(pFile2!=NULL)){
		char a;
		a=getc(pFile);
	    while (a!=EOF){
        fputc(a, pFile2);
        a = fgetc(pFile);
        }
        printf("\nCopioa del file %s nel file %s avvenuta con successo\n", nomeFile, nomeFile2);
        fclose(pFile);
        fclose(pFile2);
	}else{
		printf("\nErrore durante l'apertura del file %s \n", nomeFile);
	}
}













