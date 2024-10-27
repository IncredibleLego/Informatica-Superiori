#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s_nodo{
	int dato;
	struct s_nodo *succ;
};
typedef struct s_nodo nodo;
typedef nodo* pNodo;

void pulisciSchermo();
void menu();
void visualizzaLista(pNodo);
void inserisciInTesta(pNodo*, int);
void eliminaLista(pNodo*);
void aggiungiInCoda(pNodo*, int);
int calcoloSomma(pNodo);
float calcoloMedia(pNodo);
void salvaListaNelFile(pNodo, char*);
void caricaListaDalFile(pNodo*, char*);
void leggiDalFile(char*);
int recordNelFile(char*);

int main(){
	srand((unsigned)time(NULL));
	menu();
	printf("\nGrazie per avere utilizzato questo programma. F.Corrado");
	getchar();
	return 0;
}

void pulisciSchermo(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void menu(){
	int scelta, somma;
	float media;
	pNodo testa;
	char* nomeFile;
	scelta=0; somma=0; media=0;
	testa=NULL;
	nomeFile="dati.dat";
	do{
		pulisciSchermo();
		printf("0 uscita\n");
		printf("1 inserisci in testa\n");
		printf("2 visualizza lista\n");
		printf("3 elimina lista\n");
		printf("4 aggiungi in coda\n");
		printf("5 calcola la somma dei valori del campo dato\n");
		printf("6 calcola la media dei valori del campo dato\n");
		printf("7 salva la lista nel file\n");
		printf("8 carica la lista dal file\n");
		printf("9 leggi dal file\n");
		printf("10 visualizza la lunghezza del file\n");
		printf("Scelta?  ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: break;
			case 1: inserisciInTesta(&testa, rand()%10+1);
					break;
			case 2: visualizzaLista(testa);
					break;
			case 3: eliminaLista(&testa);
					break;
			case 4: aggiungiInCoda(&testa, rand()%26+65);
					break;
			case 5: somma=calcoloSomma(testa);
					if(somma!=0)
						printf("La somma di tutti i valori del campo dato della lista e\':  %d\n", somma);
					break;
			case 6: media=calcoloMedia(testa);
					if(media!=0)
						printf("La media di tutti i valori del campo dato della lista e\':  %f\n", media);
					break;
			case 7: salvaListaNelFile(testa, nomeFile);
					break;
			case 8: caricaListaDalFile(&testa, nomeFile);
					break;
			case 9: leggiDalFile(nomeFile);
					break;
			case 10: printf("Il numero di record nel file e': %d\n", recordNelFile(nomeFile));
					break;
			default: printf("\nLa scelta non e' accettabile. Rifai.\n");
		}
		getchar();
		getchar();
	}while (scelta!=0);
}

void visualizzaLista(pNodo testa){
	if(testa!=NULL){
		while (testa!=NULL){
			printf("%d\t", testa->dato);
			testa=testa->succ;
		}
		printf("\n");
	}
	else{
		printf("Errore durante la creazione del nodo.\n");
	}
}

void inserisciInTesta(pNodo* testa, int dato){
	pNodo pNuovoNodo;
	pNuovoNodo=NULL;
	pNuovoNodo=malloc(sizeof(nodo));
	if(pNuovoNodo!=NULL){
		printf("Inserisco il dato random\n");
		pNuovoNodo->dato=dato;
		pNuovoNodo->succ=*testa;
		*testa=pNuovoNodo;
		printf("Dato random inserito: %d\n", pNuovoNodo->dato);
	}
	else{
		printf("Errore durante la creazione del nodo.\n");
	}
}

void eliminaLista(pNodo *testa){
	pNodo temp;
	temp=NULL;
	if(*testa!=NULL){
		while(*testa!=NULL){	
			temp=*testa;
			*testa=(*testa)->succ;
			free(temp);
		}
		printf("\n");
		printf("La lista e' stata eliminata con successo.\n");
	}
	else{
		printf("La lista e' vuota: non c'e' nulla da eliminare\n");
	}
}

void aggiungiInCoda(pNodo* testa, int dato){
	pNodo pNuovoNodo, temp;
	pNuovoNodo=NULL;
	temp=NULL;
	if(*testa==NULL){
		inserisciInTesta(testa, dato);
	}
	else{
		temp=*testa;
		pNuovoNodo=malloc(sizeof(nodo));
		if(pNuovoNodo!=NULL){
			printf("Appendo il dato random\n");
			pNuovoNodo->dato=dato;
			pNuovoNodo->succ=NULL;
			while(temp->succ!=NULL){
				temp=temp->succ;
			}
			temp->succ=pNuovoNodo;
			printf("Il dato random e' stato appeso: %d\n", pNuovoNodo->dato);
		}
		else{
			printf("Errore durante la creazione del nodo.\n");
		}
	}
}

int calcoloSomma(pNodo testa){
	int somma;
	somma=0;
	if(testa!=NULL){
		printf("\nCalcolo della somma in corso\n");
		while(testa!=NULL){
			somma=somma+testa->dato;
			testa=testa->succ;
		}
	}
	else {
		printf("La lista e' vuota: non c'e' nulla da sommare\n");
		somma=0;
	}
	return somma;
}

float calcoloMedia(pNodo testa){
    float media;
    int contatore=0;
    pNodo testaVecchia;
    testaVecchia=testa;
    media=0;
	if(testa!=NULL){
		printf("\nCalcolo della media in corso\n");
		while(testa!=NULL){
			testa=testa->succ;
			contatore++;
		}
		media=(float)calcoloSomma(testaVecchia)/contatore;
	}
	else {
		printf("La lista e' vuota: non c'e' nulla da sommare\n");
		media=0;
	}
	return media;
}

void salvaListaNelFile(pNodo testa, char* nomeFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nomeFile, "wb");
	if((testa!=NULL)&&(pFile!=NULL)){
		while(testa!=NULL){
			fwrite(testa, sizeof(nodo), 1, pFile);
			testa=testa->succ;
		}
		printf("La lista e' stata correttamente salvata nel file\n");
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}
void caricaListaDalFile(pNodo* testa, char* nomeFile){
	nodo nodoTemp;
	FILE* pFile;
	nodoTemp.dato=0;
	nodoTemp.succ=NULL;
	pFile=NULL;
	pFile=fopen(nomeFile, "rb");
	if(pFile!=NULL){
		while((fread(&nodoTemp, sizeof(nodo), 1 ,pFile))>0){
			aggiungiInCoda(testa, nodoTemp.dato);
		}
		printf("\nLista caricata al file\n");
		fclose(pFile);
	}
	else{
	printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}

void leggiDalFile(char* nomeFile){
	nodo nodoTemp;
	FILE* pFile;
	nodoTemp.dato=0;
	nodoTemp.succ=NULL;
	pFile=NULL;
	pFile=fopen(nomeFile, "rb");
	if(pFile!=NULL){
		while((fread(&nodoTemp, sizeof(nodo), 1 ,pFile))>0){
			printf("%d\t", nodoTemp.dato);
		}
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
}

int recordNelFile(char* nomeFile){
	int nRecord;
	FILE* pFile;
	pFile=NULL;
	nRecord=0;
	pFile=fopen(nomeFile, "rb");
	if(pFile!=NULL){
		fseek(pFile, 0L, SEEK_END);
		nRecord=ftell(pFile)/sizeof(nodo);
		fclose(pFile);
	}
	else{
		printf("Errore durante l'apertura del file %s\n", nomeFile);
	}
	return nRecord;
}

