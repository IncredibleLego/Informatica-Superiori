#include <stdlib.h>
#include <stdio.h>

void leggiFile(char*);
void menu(char*);
void scriviAppendiFile(char*);

int main (){
	menu("caratteri.txt");
	//system("PAUSE");
	getchar();
	return 0;
}
void menu(char* nomeFile){
	int scelta;
	scelta=0;
	do{
		printf("\n1: leggi dal file\n");
		printf("2: scrivi o appendi nel file\n");
		printf("0: esci dal programma\n");		
		printf("Scegli l'opzione desiderata:\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("Grazie per avere usato il mio programma. Arrivederci. F.Corrado\n");
					break;
			case 1: leggiFile(nomeFile);
					break;
			case 2: scriviAppendiFile(nomeFile);
			        break;
			default: printf("Scelta non accettabile. Rifai\n");
		}
	}while(scelta!=0);
}
void leggiFile(char* nomeFile){
	char carattere;
	FILE* pFile;	//puntatore al file: indirizzo dell'inizio del file
	carattere=' ';
	pFile=NULL;
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		printf("Ecco il contenuto del file %s:\n", nomeFile);
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
void scriviAppendiFile(char* nomeFile){
	char carattere;
	int scelta;
	FILE* pFile;	//puntatore al file: indirizzo dell'inizio del file
	carattere=' ';
	pFile=NULL;
	do{
		printf("\n1: Scrivi nel file con funzione write\n2: Scrivi nel file con funzione append\n");
	    scanf("%d", &scelta);
	}while((scelta!=1)&&(scelta!=2));
	if(scelta==1){
		pFile=fopen(nomeFile, "w");
	}else{
		pFile=fopen(nomeFile, "a");
	}
	if(pFile!=NULL){
		printf("Inserisci un testo, termina con il carattere '.'\n");
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!='.'); //una volta scritto quello che chiede l'utente, mi cancella quello scritto im precedenza e lo sostituisce perchè sono in modalità W. 
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file.\n");
	}
}
