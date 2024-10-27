#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void leggiFile(char*);
void menu(char*, char*);
void scriviFileManuale(char*, char*);
void scriviFileAutomatica(char*, char*);
void svuotaFile(char*);
void copiaAppendiFile(char*, char*,char*);

int main (){
	char* nomeFileA, *nomeFileB;
	nomeFileA="origine.txt";
	nomeFileB="destinazione.txt";
	srand((unsigned)time(NULL));
	menu(nomeFileA, nomeFileB);
	getchar();
	return 0;
}

void menu(char *nomeFileA, char *nomeFileB){
	int scelta;
	char comando[50];
	scelta=0;
	strcpy(comando, "rm "); //linux
	//strcpy(comando, "del "); //windows
	strcat(comando, nomeFileA);
	do{
		printf("\e[1;1H\e[2J"); //linux e windows
		printf("\nScegli l'operazione che vuoi eseguire:\n");
		printf("0: uscita\n");
		printf("1: leggi dai fileA\n");
		printf("2: scrivi in fileA manualmente\n");
		printf("3: appendi al fileA\n");
		printf("4: elimina il fileA\n");
		printf("5: svuota il fileA\n");
		printf("6: copia dal fileA in fileB\n");
		printf("7: appendi dal fileA al fileB\n");
		printf("8: leggi dal fileB\n");
		printf("9: scrivi in fileA casualmente\n");
		scanf(" %d", &scelta);
		switch(scelta){
			case 1: leggiFile(nomeFileA);
					leggiFile(nomeFileB);
					break;
			case 2: scriviFileManuale(nomeFileA, "w");
					break;
			case 3: scriviFileManuale(nomeFileA, "a");
					break;
			case 4: system(comando); 
					break;
			case 5: svuotaFile(nomeFileA);
					break;
			case 6: copiaAppendiFile(nomeFileA, nomeFileB, "w");
					break;
			case 7: copiaAppendiFile(nomeFileA, nomeFileB, "a");
					break;
			case 8: leggiFile(nomeFileB);
					break;
			case 9: scriviFileAutomatica(nomeFileA, "w");
					break;
			default: if (scelta!=0)
						printf("\nScelta non accettabile. Rifai.\n\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}

void leggiFile(char* nomeFile){
	FILE* pFile;	
	char carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		printf("Contenuto del file %s:\n", nomeFile);
		while(fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
		printf("\n");
		fclose(pFile);
	}
	else{
		printf("\nErrore durante l'apertura del file %s.\n", nomeFile);
	}
}
void scriviFileManuale(char* nomeFile, char* tipo){
	FILE* pFile;
	char carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, tipo);
	if(pFile!=NULL){
			printf("\nScrivi i caratteri che desideri, usa il . per terminare la scrittura\n");
			do{
				scanf("%c", &carattere);
				fprintf(pFile, "%c", carattere);
			}while((carattere!='.'));
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file %s.\n", nomeFile);
	}
}
void scriviFileAutomatica(char* nomeFile, char* tipo){
	FILE* pFile;
	int i, quanti;
	char carattere=' ';
	pFile=NULL;
	i=0; quanti=0;
	pFile=fopen(nomeFile, tipo);
	if(pFile!=NULL){
			printf("\nScrivi quanti (>=0) caratteri desideri che vengano scritti nel file\n");
			do{
				scanf("%d", &quanti);
			}while(quanti<0);
			for(i=0; i<quanti; i++){
				carattere=rand()%26+65;
				fprintf(pFile, "%c", carattere);
			}
		fclose(pFile);
}
	else{
		printf("Errore durante l'apertura del file %s.\n", nomeFile);
	}
}
void svuotaFile(char* nomeFile){
	FILE* pFile;	
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		printf("File %s svuotato.\n", nomeFile);
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file.%s.\n", nomeFile);
	}
}

void copiaAppendiFile(char* nomeFileA, char* nomeFileB, char* tipo){
	FILE* pFileA=NULL;
	FILE* pFileB=NULL;
	char copiaCarattere;
	pFileA=fopen(nomeFileA, "r");
	pFileB=fopen(nomeFileB, tipo);
	if((pFileA!=NULL)&&(pFileB!=NULL)){
		while(fscanf(pFileA, "%c", &copiaCarattere)>0){
			fprintf(pFileB, "%c", copiaCarattere);
		}
		if (strcmp(tipo,"w")==0){
			printf("file %s copiato nel file %s", nomeFileA, nomeFileB);
		}
		else{
			printf("file %s appeso nel file %s", nomeFileA, nomeFileB);
		}
		fclose(pFileA);
		fclose(pFileB);
	}
	else{
		if(pFileA==NULL){
			printf("errore durante l\'apertura del file origine %s\n", nomeFileA);
		}
		if(pFileB==NULL){
			printf("errore durante l\'apertura del file destinazione %s\n", nomeFileB);
		}
	}
}
