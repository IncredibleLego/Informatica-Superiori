//Autore: Francesco Corrado
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void menu(char*, char*, char*, char*);
void leggiFile(char*);
void scriviFile(char*, char*);
void svuotaFile(char*);
void copiaAppendiFile(char*, char*, char*);
void appendiFile(char*, char*, char*, char*);


int main(){
        char *fileUno, *fileDue, *fileTre, *fileQuattro;
        fileUno="uno.txt";
        fileDue="due.txt";
        fileTre="tre.txt";
        fileQuattro="quattro.txt";
        menu(fileUno, fileDue, fileTre, fileQuattro);
        getchar();
        return 0;
}

void menu(char* fileUno, char* fileDue, char* fileTre, char* fileQuattro){
	int scelta;
	scelta=0;
	do{
		printf("\e[1;1H\e[2J");
		printf("\nScegliere una delle seguenti opzioni\n");
		printf("0: esci dal file \n");
		printf("1: leggi dai file uno.txt due.txt tre.txt quattro.txt\n");
		printf("2: scrivi nel file uno.txt fino all'inserimento del carattere , \n");
		printf("3: scrivi nel file due.txt fino all'inserimento del caratter ; \n");
		printf("4: svuota i file uno.txt due.txt tre.txt e quattro.txt\n");
		printf("5: elimina i file uno.txt due.txt tre.txt e quattro.txt\n");
		printf("6: copia il file uno.txt nel file due.txt\n");
		printf("7: appendi il file due.txt nel file uno.txt\n");
		printf("8: appendi un testo contemporaneamente a uno.txt due.txt tre.txt e quattro.txt\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("\nGrazie, arrivederci. \n");
			        break;
			case 1: leggiFile(fileUno);
			        leggiFile(fileDue);
			        leggiFile(fileTre);
			        leggiFile(fileQuattro);
			        break;
			case 2: scriviFile(fileUno, ",");
			        break;
			case 3: scriviFile(fileDue, ";");
			        break;
			case 4: svuotaFile(fileUno);
			        svuotaFile(fileDue);
			        svuotaFile(fileTre);
			        svuotaFile(fileQuattro);
			        break;
			case 5: remove(fileUno);
			        remove(fileDue);
			        remove(fileTre);
			        remove(fileQuattro);
			        printf("I file sono stati eliminati con successo\n");
			        break;
			case 6: copiaAppendiFile(fileUno, fileDue, "w");
			        break;  
			case 7: copiaAppendiFile(fileDue, fileUno, "a");
			        break;
			case 8: appendiFile(fileUno, fileDue, fileTre, fileQuattro);
			        break;
			default: if(scelta!=0)
			         printf("\nScelta non accettabile. Rifai\n");
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
		while(fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
	}else{
		printf("\nErrore durante l'apertura del file %s\n", nomeFile);
	}
}

void scriviFile(char* nomeFile, char* fine){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	char finale;
	finale= *fine;
	carattere=' ';
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		printf("Inserisci il testo da inserire in %s, deve terminare con %c\n", nomeFile, finale);
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!=finale);
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s\n", nomeFile);
	}
	}

void svuotaFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		pFile=fopen(nomeFile, "w");
		printf("Il file %s e' stato svuotato con successo\n", nomeFile);
		fclose(pFile);
	}else{
		printf("\nErrore durante l'apertura del file %s\n", nomeFile);
	}
	}

void copiaAppendiFile(char* nomeFile, char* nomeFile2, char* modo){
	FILE* pFile;
	FILE* pFile2;
	pFile=NULL;
	pFile2=NULL;
	pFile=fopen(nomeFile, "r");
	pFile2=fopen(nomeFile2, modo);
	if((pFile!=NULL)&&(pFile2!=NULL)){
		char a;
		a=fgetc(pFile);
		while(a!=EOF){
			fputc(a, pFile2);
			a=fgetc(pFile);
		 }
		 printf("\nCopia del file %s nel file %s completata con successo\n", nomeFile, nomeFile2);
		fclose(pFile);
		fclose(pFile2);
	}else{
		if(pFile==NULL){
		printf("\nErrore durante l'apertura del file di origine %s\n", nomeFile);
	}
	    if(pFile2==NULL){
			printf("\nErrore durante l'apertura del file di destinazione %s\n", nomeFile2);
		}
	}
}

void appendiFile(char* nomeFile, char* nomeFile2, char* nomeFile3, char* nomeFile4){
	FILE* pFile;
	FILE* pFile2;
	FILE* pFile3;
	FILE* pFile4;
	pFile=NULL;
	pFile2=NULL;
	pFile3=NULL;
	pFile4=NULL;
	pFile=fopen(nomeFile, "a");
	pFile2=fopen(nomeFile2, "a");
	pFile3=fopen(nomeFile3, "a");
	pFile4=fopen(nomeFile4, "a");
	char carattere[10000];
	if((pFile!=NULL)&&(pFile2!=NULL)&&(pFile3!=NULL)&&(pFile4!=NULL)){
		printf("Inserire il testo da inserire nei file: \n");
		scanf(" %[^\n]s", carattere);
		fprintf(pFile, "%s", carattere);
		fprintf(pFile2, "%s", carattere);
		fprintf(pFile3, "%s", carattere);
		fprintf(pFile4, "%s", carattere);
		fclose(pFile);
		fclose(pFile2);
		fclose(pFile3);
		fclose(pFile4);
	}else{
	     if(pFile==NULL){
		printf("\nErrore durante l'apertura del file %s\n", nomeFile);
	}
	if(pFile2==NULL){
		printf("\nErrore durante l'apertura del file %s\n", nomeFile2);
	}
	if(pFile3==NULL){
		printf("\nErrore durante l'apertura del file %s\n", nomeFile3);
	}
	if(pFile4==NULL){
		printf("\nErrore durante l'apertura del file %s\n", nomeFile4);
	}
	}
}









