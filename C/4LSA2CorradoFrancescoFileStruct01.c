//Autore: Francesco Corrado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(char*);
void leggiFile(char*);
void scriviFile(char*);
void svuotaFile(char*);

struct s_persone{
	char iCognome;
	char iNome;
	int statura;
}
typedef struct s_libro
	

int main(){
	menu("filestruct.txt");
    return 0;
}

void menu(char* nomeFile){
	int scelta;
	scelta=0;
	do{
		printf("\e[1;1H\e[2J");
		printf("\nScegliere una delle seguenti opzioni\n");
		printf("0: esci dal file \n");
		printf("1: leggi file\n");
		printf("2: scrivi file\n");
		printf("Scelta? ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("\nGrazie, arrivederci. \n");
			        break;
			case 1: leggiFile(nomeFile);
			        break;
			case 2: scriviFile(nomeFile);
			        break;
			default: printf("\nScelta non accettabile. Rifai\n");
			         break;
    }
    getchar();
    getchar();
	}while(scelta!=0);
	}

void leggiFile(char* nFile){
	FILE* pFile;
	pFile=NULL;
	char carattere;
	carattere=' ';
	pFile=fopen(nFile, "r");
	if(pFile!=NULL){
		printf("\nContenuto del file %s: \n", nFile);
		while(fscanf(pFile, "%c", &carattere)>0){
			printf("%c", carattere);
		}
	}else{
		printf("\nErrore durante l'apertura del file %s\n", nomeFile);
	}
}


