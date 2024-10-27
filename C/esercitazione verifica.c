//Autore: Francesco Corrado
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void menu(char*, char*, char*, char*);
void leggiFile(char*);
void scriviFile(char*, char*);
void svuotaFile(char*);
void copiaAppendiFile(char*, char*, char*);
void appendiFile(char*, char*);
void coppie(char*, char*, char*);
void frequenze(char*);
void scriviCasuali(char*);

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
	do
	{
		printf("\e[1;1H\e[2J");
		system("cls");
		printf("\nScegli l'operazione che vuoi eseguire:\n");
		printf("0: Esci dal programma\n");
		printf("1: Leggi i file di testo uno.txt due.txt coppie.txt e frequenze.txt\n");
		printf("2: scrivi nel file uno.txt fino all'inserimento del carattere ';'\n");
		printf("3: scrivi nel file due.txt fino all'inserimento del carattere '.'\n");
		printf("4: svuota i file uno.txt e due.txt\n");
		printf("5: elimina i file uno.txt e due.txt\n");
		printf("6: copia il file uno.txt nel file due.txt\n");
		printf("7: appendi il file uno.txt nel file due.txt\n");
		printf("8: appendi un testo di input ai file uno.txt e due.txt\n");
		printf("9: scrivi nel file coppie.txt le coppie di caratteri corrispondenti del file uno.txt e due.txt\n");
		printf("10: scrivi nel file frequenze.txt il numero di presenze di ciascuno dei caratteri (A-Z) presenti nel file coppie.txt\n");
		printf("11: inserisci dei caratteri casuali nel file uno.txt in base al valore inserito dall'utente\n");
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
			        printf("I file %s e %s sono stati eliminati con successo\n", fileUno, fileDue);
		    case 6: copiaAppendiFile(fileUno, fileDue, "w");
		            break;
		    case 7: copiaAppendiFile(fileUno, fileDue, "a");
		            break;
		    case 8: appendiFile(fileUno, fileDue);
		            break;
		    case 9: coppie(fileUno, fileDue, fileCoppie);
		            break;
		    case 10: frequenze(fileCoppie);
		             break;
		    case 11: scriviCasuali(fileUno);
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
	char carattere;
	pFile=NULL;
	carattere=' ';
	pFile=fopen(nomeFile, "r");
	if(pFile!=NULL){
		printf("Contenuto del file %s:\n", nomeFile);
		while (fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
		printf("\n");
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
	
}

void scriviFile(char* nomeFile, char* fine){
	FILE* pFile;
	int finale;
	finale= *fine;
	char carattere;
	pFile=NULL;
	carattere=' ';
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		if (finale==';'){
			printf("Inserisci un testo, termina con il carattere ';'\n");
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!=';');
		}
		if(finale=='.'){
			printf("Inserisci un testo, termina con il carattere '.'\n");
		do{
			scanf("%c", &carattere);
			fprintf(pFile, "%c", carattere);
		}while(carattere!='.');
		}
		printf("\n");
		fclose(pFile);
	}else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}

void svuotaFile(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	fclose(pFile);
	printf("Il file %s e' stato svuotato con successo\n", nomeFile);
	
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
	while (a!=EOF)
    {
        fputc(a, pFile2);
        a = fgetc(pFile);
    }
    printf("\nCopioa del file %s nel file %s avvenuta con successo\n", nomeFile, nomeFile2);
    fclose(pFile);
    fclose(pFile2);
    }else{
		if(pFile==NULL){
			printf("Errore durante l'apertura del file origine %s\n", nomeFile);
		}
		if(pFile2==NULL){
			printf("Errore durante l'apertura del file destinazione %s\n", nomeFile2);
		}
	}
}

void appendiFile(char* nomeFile, char* nomeFile2){
	FILE* pFile;
	FILE* pFile2;
	char carattere[10000];
	pFile=NULL;
	pFile2=NULL;
	pFile=fopen(nomeFile, "a");
	pFile2=fopen(nomeFile2, "a");
	if(pFile!=NULL&&pFile2!=NULL){
		printf("Inserire il testo da inserire nei file:\n");
		scanf(" %[^\n]s", carattere);
		fprintf(pFile, "%s", carattere);
		fprintf(pFile2, "%s", carattere);
		fclose(pFile);
		fclose(pFile2);
	}else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}

void coppie(char* nomeFile, char* nomeFile2,char* nomeFile3){
	FILE* pFile;
	FILE* pFile2;
	FILE* pFile3;
	char carattere;
	carattere=' ';
	pFile=NULL;
	pFile2=NULL;
	pFile3=NULL;
	pFile=fopen(nomeFile, "r");
	pFile2=fopen(nomeFile2, "r");
	pFile3=fopen(nomeFile3, "w");
	int i;
	i=0;
	if(pFile!=NULL){
		if(pFile2!=NULL){
			if(pFile3!=NULL){
				for(i=0; i<100; i++){
					fscanf(pFile, "%c", &carattere);
					fprintf(pFile3, "%c", carattere);
					fscanf(pFile2, "%c", &carattere);
					fprintf(pFile3, "%c", carattere);
				}
				
			}else{
				printf("Errore durante l'apertura del file %s\n", nomeFile3);
			}
		}else{
			printf("Errore durante l'apertura del file %s\n", nomeFile2);
		}
	}else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}

void frequenze(char* nomeFile){
	
}

void scriviCasuali(char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	carattere=' ';
	int quanti=0;
	int i=0;
	pFile=fopen(nomeFile, "w");
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









