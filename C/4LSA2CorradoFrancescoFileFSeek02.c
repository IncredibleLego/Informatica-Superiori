//Autore: Francesco Corrado
#include <stdio.h>
#include <string.h>
void scriviFile(char*, char*);
void leggiFile(char*, char*);
void menu(char*, char*);
void sovrascriviInserisci(char*, char*, int);
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
			case 4: sovrascriviInserisci(nomeF, nomeCopia, 0);
					break;
			case 5: sovrascriviInserisci(nomeF, nomeCopia, 1);
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
void sovrascriviInserisci(char* nomeF, char* nomeCopia, int contatore){
	FILE *fp, *fp2;
	char messaggio[200], a;
	int pos, i, sizeMess, size;
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
		printf("\nInserisci da che posizione si vuole inserire nel file: ");
		scanf("%d", &pos);
		sizeMess = strlen(messaggio);
		if(contatore==0){
			fseek(fp2, pos, SEEK_SET);
		    fputs(messaggio, fp2);
		 /* fseek(fp2, pos+sizeMess, SEEK_SET);
		    i=0;
	    	a=fgetc(fp);
		    while(i!=20){                      //Questa parte di codice e' da utilizzare in caso si voglia eliminare tutto ciò che si trova dopo il messaggio inserito
			    fputc(' ', fp2);
			    a=fgetc(fp);
			    i++;
		    }  */
		}
		if(contatore==1){
			fseek(fp2, 0, SEEK_END);
            size = ftell(fp);
            fseek(fp2, 0, SEEK_SET);
	        fseek(fp, pos-1, SEEK_SET);
		    fseek(fp2, pos+sizeMess, SEEK_SET);
		    a=fgetc(fp);
		    if(a==' '){
		        a=fgetc(fp);
			    fputc(' ', fp2);
		    }else{
			    a=fgetc(fp);
		    }
		    while(a!=EOF){
			    fputc(a, fp2);
			    a=fgetc(fp);
		    }
		    fseek(fp2, pos, SEEK_SET);
		    fputs(messaggio, fp2);	
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

