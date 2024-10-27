#include <stdlib.h>
#include <stdio.h>
void leggiFile(char*);
void scriviOAppendiFile(char* , char*);
void eliminaFile(char*);
void svuotaFile(char*);
void menu (char*);

int main (){
	menu("caratteri.txt");
	getchar();
	return 0;
}

void menu(char* nomeFile){
	int scelta=0;
	do{
		printf("\n1: leggi dal file\n");
		printf("2: scrivi nel file\n");
		printf("3: appendi al file\n");
		printf("4: svuota file\n");
		printf("5: elimina file\n");
		printf("0: esci dal programma\n");
				
		printf("Scegli l'opzione desiderata:\n");
		scanf("%d", &scelta);
	
		switch(scelta){
			case 0: printf("Grazie per avere usato il mio programma. Arrivederci.\nF.Corrado\n");
			break;
			case 1: leggiFile(nomeFile);
				break;
			case 2: scriviOAppendiFile(nomeFile, "w");
				break;
			case 3: scriviOAppendiFile(nomeFile, "a");
				break;
			case 4: svuotaFile(nomeFile);
				break;
			case 5: eliminaFile(nomeFile);
				break;
			default: printf("Scelta non accettabile. Rifai\n");
				scelta=0;
			}
	}while(scelta!=0);
	
}

void leggiFile(char* nomeFile){
	char carattere;
	int conferma=0;
	FILE* pFile;
	carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, "r");
	printf("Ecco il contenuto del file %s:\n", nomeFile);
	if(pFile!=NULL){
		while(fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
		printf("\n");
		fclose(pFile);
		do{
				printf("\nConfermare la avvenuta lettura del file inserendo 1\n");
				scanf("%d", &conferma);
		}while (conferma!=1);
		system ("cls");
	}
	else{
		printf("Errore durante l'apertura del file.\n");
	}
}

void scriviOAppendiFile(char* nomeFile, char* tipo){
	system ("cls");
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

void eliminaFile(char* nomeFile){
	system ("cls");
	int answ; //answ indica la risposta del computer sull'esistenza o meno del file
	answ=remove(nomeFile);
	if (answ==0){ //se answ=0, significa che il file è stato eliminato
		printf("File eliminato con successo.\n");
	}else{
		printf("Errore durante la rimozione del file.\n");
	}
}

void svuotaFile(char* nomeFile){
	system ("cls");
	FILE* pFile;
	pFile = NULL;
	pFile=fopen(nomeFile,"w");
	fclose(pFile);
	printf("File svuotato con successo.\n");
}
