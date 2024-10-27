#include <stdlib.h>
#include <stdio.h>
void leggiFile(char*);
void scriviFile(char* , char*);
void svuotaFile(char*);
void menu (char*);

int main (){
	
	menu("caratteri.txt");
	//system("PAUSE");
	getchar();
	return 0;
}

void menu(char* nomeFile){
	int scelta=0;
	do{
		printf("\n1: leggi dal file \n");
		printf("2: scrivi nel file \n");
		printf("3: appendi al file \n");
		printf("4: svuota il file \n");
		printf("5: elimina il file \n");
		printf("0: esci dal programma \n");
		printf("scegli l'opzione:");
		scanf("%d", &scelta);
	
		switch(scelta){
			case 0: printf("grazie, arrivederci\n");
			    break;
			case 1: leggiFile(nomeFile);
				break;
			case 2: scriviFile(nomeFile, "w");
				break;
			case 3: scriviFile(nomeFile, "a");
				break;
			case 4: svuotaFile(nomeFile);
			        break;
			case 5: remove(nomeFile);
			        printf("\n Il file e' stato eliminato con successo. \n");
			        break;
			default: printf("Riprova con opzioni esistenti\n");
				scelta=0;
			}
	}while(scelta!=0);
	
}

void leggiFile(char* nomeFile){
	char carattere;
	FILE* pFile;
	carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		while(fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
		printf("\n");
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file.\n");
	}
}

void scriviFile(char* nomeFile, char* tipo){
	char carattere= ' ';
	FILE* pFile;
	carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, tipo);
	if(pFile!=NULL){
		printf("Inserisci un testo, termina con il carattere '.'\n");
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!='.');
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file.\n");
	}
}

void svuotaFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	fclose(pFile);
	printf("\nIl file e' stato svuotato con successo. \n");
}
