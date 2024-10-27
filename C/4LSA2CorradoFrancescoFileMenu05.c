#include <stdlib.h>
#include <stdio.h>
void eliminaFile(char*);
void leggiFile(char*);
void svuotaFile(char*);
void scriviFile(char* , char*);
void menu (char* , char*);
void copiaFile(char*, char*);

int main (){
	
	menu("caratteri.txt", "filecopia.txt");
	getchar();
	return 0;
}

void menu(char* nomeFile, char* nomeFile2){
	int scelta=0;
	do{
		//system("clear"); linux
		//system("cls"); //windows
		printf("\e[1;1H\e[2J"); //linux e windows
		printf("\n1: leggi dal file \n");
		printf("2: scrivi nel file \n");
		printf("3: appendi al file \n");
		printf("4: svuota file \n");
		printf("5: elimina il file \n");
		printf("6: copia il contenuto del file dentro un altro file \n");
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
			case 5: eliminaFile(nomeFile);
				break;
			case 6: copiaFile(nomeFile, nomeFile2);
			    break;
			default: if (scelta!=0)
						printf("\nScelta non accettabile. Rifai.\n\n");
			}
		//system("read"); //linux
		//system("pause"); windows
		getchar();
		getchar();
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
void svuotaFile(char* nomeFile)
{
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "w");
	if(pFile!=NULL){
		fclose(pFile);
	}
	else
		printf("Errore durante l'apertura del file.\n");
}
void eliminaFile(char* nomeFile){
	//system("del caratteri.txt"); //windows
	//system("rm caratteri.txt"); //linux
	remove(nomeFile);
}

void copiaFile(char* nomeFile, char* nomeFile2){
	char a;
	FILE* pFile;
	FILE* pFile2;
	pFile=NULL;
	pFile2=NULL;
	pFile=fopen(nomeFile, "r");
	pFile2=fopen(nomeFile2, "w");
	a=fgetc(pFile);
    while (a != EOF)
    {
        fputc(a, pFile2);
        a = fgetc(pFile);
    }
    printf("\nCopia avvenuta con successo.");
    fclose(pFile);
    fclose(pFile2);
}
