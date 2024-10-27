#include <stdlib.h>
#include <stdio.h>
void leggiFile(char*);
void scriviFile(char*);
int main (){
	scriviFile("caratteri.txt");
	leggiFile("caratteri.txt");
	//system("PAUSE");
	getchar();
	return 0;
}

void leggiFile(char* nomeFile){
	char carattere;
	FILE* pFile;	//puntatore al file: indirizzo dell'inizio del file
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

void scriviFile(char* nomeFile){
	char carattere;
	char testo[10000];
	FILE* pFile;	//puntatore al file: indirizzo dell'inizio del file
	carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		printf("Inserisci un testo, termina con il carattere '.'\n");
//		do{
			scanf("%[^\n]s", testo);
			fprintf(pFile, "%s", testo);
//		}while(testo!='.');
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file.\n");
	}
}
