#include <stdio.h>
#include <string.h>
void scriviFile(char*, char*);
void leggiFile(char*, char*);
void sovrascrivi(char*, char*);
void inserisci(char*, char*);
void menu(char*, char*);

void svuotaFile(char*);

int main(){
	char* nomeFile;
	char* fileCopia;
	nomeFile="file.txt";
	fileCopia="copia.txt";
	menu(nomeFile, fileCopia);
	return(0);
}
void menu(char* nomeF, char* nomeCopia){
	int scelta;
	scelta=0;
	do{
		printf("\e[1;1H\e[2J");
//		system("cls");
		printf("\n0: uscita\n");
		printf("1: leggi file\n");
		printf("2: scrivi file\n");
		printf("3: aggiungi alla fine del file\n");
		printf("4: sovrascrivi a partire da una certa posizione del file\n");
		printf("5: inserisci a partire da una certa posizione del file\n");
		printf("6: svuota file\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 1: leggiFile(nomeF, "r");
					break;
			case 2: scriviFile(nomeF, "w");
					break;
			case 3: scriviFile(nomeF, "a");
					break;
			case 4: sovrascrivi(nomeF, nomeCopia);
					break;
			case 5: inserisci(nomeF, nomeCopia);
					break;
			case 6: svuotaFile(nomeF);
			        svuotaFile(nomeCopia);
			        break;
			default: printf("Scelta non accettabile. Rifai.\n");
					break;
		}
		getchar();
		getchar();
	}while(scelta!=0);
}
void scriviFile(char* nomeF, char* modo) {
	FILE *fp;
	char messaggio[200];
	fp = fopen(nomeF, modo);
	if(fp!=NULL){
		printf("\nInserisci il testo da inserire in %s: ", nomeF);
		scanf(" %[^\n]s", &messaggio);
		fputs(messaggio, fp);
		fclose(fp); 
	}
}
void sovrascrivi(char* nomeF, char* nomeCopia){
	FILE *fp, *fp2;
	char messaggio[200], a;
	int pos, i, sizeMess;
	fp=NULL; fp2=NULL;
	fp = fopen(nomeF, "r");
	fp2 = fopen(nomeCopia, "w");
	if((fp!=NULL)&&(fp2!=NULL)){
		a=fgetc(fp);
		while(a!=EOF){
			fputc(a, fp2);
			a=fgetc(fp);
		}
		printf("\nInserisci il testo da inserire in %s: ", nomeF);
		scanf("%s", &messaggio);
		sizeMess = strlen(messaggio);
		printf("\nInserisci da che posizione si vuole inserire nel file: ");
		scanf("%d", &pos);
		fseek( fp2, pos, SEEK_SET);
		fputs(messaggio, fp2);
		fseek(fp2, pos+sizeMess, SEEK_SET);
		i=0;
		a=fgetc(fp);
		while(i!=20){
			fputc(' ', fp2);
			a=fgetc(fp);
			i++;
		 }
		fclose(fp);
		fclose(fp2);	
		fp = fopen(nomeF, "w");
	    fp2 = fopen(nomeCopia, "r");
		a=fgetc(fp2);
		while(a!=EOF){
			fputc(a, fp);
			a=fgetc(fp2);
		 }
		fclose(fp);
		fclose(fp2);
    }
    else{
		printf("Errore apertura file %s\n", nomeF);
	}
}
void inserisci(char* nomeF, char* nomeCopia){
	FILE *fp;
	FILE *fp2;
	char messaggio[200];
	char a;
	int pos, i, size, sizeMess;
	fp=NULL;
	fp2=NULL;
	fp = fopen(nomeF, "r");
	fp2 = fopen(nomeCopia, "w");
	if((fp!=NULL)&&(fp2!=NULL)){
		a=fgetc(fp);
		while(a!=EOF){
			fputc(a, fp2);
			a=fgetc(fp);
		 }
		printf("\nHo copiato il file");
    }
    if(fp!=NULL){
		printf("\nInserisci il testo da inserire in %s: ", nomeF);
		scanf("%s", &messaggio);
		printf("\nIl messsaggio e' %s", messaggio);
		printf("\nInserisci da che posizione si vuole inserire nel file: ");
		scanf("%d", &pos);
		sizeMess = strlen(messaggio);
		fseek(fp2, 0, SEEK_END);
        size = ftell(fp);
        fseek(fp2, 0, SEEK_SET);
		printf("\nLa dimensione del messaggio e': %d", sizeMess);
		printf("\nLa dimensione del file e': %d", size);
		printf("\nLa posizione in cui inserire e': %d", pos);
		fseek(fp, pos, SEEK_SET);
		i = ftell(fp);
		printf("\nLa pozione nel file 1 e': %d ", i);
		fseek(fp2, pos+sizeMess, SEEK_SET);
		i = ftell(fp2);
		printf("\nLa pozione nel file 2 e': %d ", i);
		a=fgetc(fp);
		printf("\nCarttere preso: %c", a);
		fputc(' ', fp2);
		while(a!=EOF){
			fputc(a, fp2);
			a=fgetc(fp);
			printf("\nCarttere preso: %c", a);
		}
		printf("\nHo copiato la parte finale del file");
		i=0;
/*		printf("\nLettura file:\n");
		do{
			a = fgetc(fp2);
			if( feof(fp2) ) {
				break;
			}
			printf("%c", a);
			i++;
		}while(i!=(size-sizeMess));  */
		
		fseek(fp2, pos, SEEK_SET);
		fputs(messaggio, fp2);	
		fclose(fp);
		fclose(fp2);	
		fp = fopen(nomeF, "w");
	    fp2 = fopen(nomeCopia, "r");
	}
	printf("\nOra ricopio il file copia nel file originale");
	if((fp!=NULL)&&(fp!=NULL)){
		char a;
		a=fgetc(fp2);
		while(a!=EOF){
			fputc(a, fp);
			a=fgetc(fp2);
		 }
		fclose(fp);
		fclose(fp2);
		printf("\nHo copiato il file");
    }
}

void leggiFile(char* nomeF, char* modo) {
	FILE *fp;
	int c;
	fp = fopen(nomeF, modo);
	if(fp!=NULL){
		printf("Lettura file:\n");
		while(1) {
			c = fgetc(fp);
			if( feof(fp) ) {
				break;
			}
			printf("%c", c); 
		}
		fclose(fp);
	}
	else{
		printf("Errore apertura file %s\n", nomeF);
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

