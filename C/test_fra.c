#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUANTIALFABETO 26
#define ASCIIMAIUSCOLE 65

struct s_nodo{
	char classe;
	int studenti;
	struct s_nodo *succ;
};
typedef struct s_nodo nodo; 
typedef nodo* pNodo;

void visualizzaLista(pNodo); 
void inserisciInTesta(pNodo*, char, int);
void eliminaLista(pNodo*);
void aggiungiInCoda(pNodo*, char, int);
int calcoloSomma(pNodo);
float calcoloMedia(pNodo); 
void salvaListaNelFile(pNodo, char*); 
void caricaListaDalFile(pNodo*, char*);
void leggiDalFile(char*);
void trovaMinima(pNodo); 
void recordNelFile(char*);
void menu(); 

int main() {
	srand((unsigned)time(NULL));
	menu();
	printf("Grazie per aver usato il mio programma. R.Zoni. Arrivederci.");
	getchar();
	return 0;
}

void pulisciSchermo(){
    #if defined(_linux) || defined(unix) || defined(APPLE_)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void menu(){
	int scelta, sommaA, sommaB;
	float mediaA, mediaB;
	pNodo testaA;
	pNodo testaB;
	char* nomeFileA, * nomeFileB;
	scelta=0;
	sommaA=0;
	sommaB=0;
	mediaA=0;
	mediaB=0;
	testaA=NULL;
	testaB=NULL; 
	nomeFileA="4LSA1CognomeNomeA.dat";
	nomeFileB="4LSA1CognomeNomeB.dat";
	do{
		pulisciSchermo();
		printf("0 uscita\n");
		printf("1 visualizza listaA e listaB\n");
		printf("2 inserisci in testa lista B\n");
		printf("3 aggiungi in coda lista A\n");
		printf("4 elimina listaA e listaB\n");
		printf("5 salva listaA in 4LSA1CognomeNomeA.dat e listaB in 4LSA1CognomeNomeB.dat\n");
		printf("6 carica listaA da 4LSA1CognomeNomeA.dat e listaB da 4LSA1CognomeNomeB.dat\n");
		printf("7 leggi file 4LSA1CognomeNomeA.dat e 4LSA1CognomeNomeB.dat\n");
		printf("8 calcola media studenti in listaA e in listaB\n");
		printf("9 calcola studenti massimo di 4LSA1CognomeNomeA.dat e di 4LSA1CognomeNomeB.dat\n");
		printf("10 elimina nodo con studenti scelto dall'utente in listaA e in listaB\n");
		printf("Scelta?  ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: break;
			case 1: printf("\nTesta prima della visualizza: %p\n", testaA);
					visualizzaLista(testaA);
					printf("Testa dopo la visualizza: %p\n", testaA);
					printf("\nTesta prima della visualizza: %p\n", testaB);
					visualizzaLista(testaB);
					printf("Testa dopo la visualizza: %p\n", testaB);
					break;
			case 2: printf("\nTesta prima della inserisciIntesta: %p\n", testaB);
					inserisciInTesta(&testaB, rand()%26+65, rand()%140+100);  //mancavano i punti random 
					printf("Testa dopo la inserisciIntesta: %p\n", testaB);
					break;
			case 3: printf("\nTesta prima della aggiungiInCoda: %p\n", testaA);
					aggiungiInCoda(&testaA, rand()%26+65, rand()%140+100);
					printf("Testa dopo la aggiungiInCoda: %p\n", testaA);
					break;
			case 4: eliminaLista(&testaA);
			        eliminaLista(&testaB);
					break;
			case 5: salvaListaNelFile(testaA, nomeFileA);
					salvaListaNelFile(testaB, nomeFileB);
					break;
	//		case 6: caricaListaDalFile(&testaA, nomeFileA);
	//		        caricaListaDalFile(&testaB, nomeFileB);
	//				break;
	//		case 7: leggiDalFile(nomeFileA);
			        leggiDalFile(nomeFileB);
					break;
			case 8: mediaA=calcoloMedia(testaA); 
					mediaB=calcoloMedia(testaB); 
					printf("Lo studente medio della listaA e':  %d, della listaB e': %d'\n", mediaA, mediaB);
					break;
			case 9: //printf("Il massimo studente di 4LSA1CognomeNomeA.dat e': %d, di 4LSA1CognomeNomeB.dat e':  %d\n", );
					break;
			case 10://printf("Il numero di record nel file e': %d\n", recordNelFile(nomeFile));
					break;
			default: printf("\nScelta non accettabile. Rifai.\n");
		}
		getchar();
		getchar(); 
	}while (scelta!=0);
}

void visualizzaLista(pNodo testa){
	if(testa!=NULL){
		while(testa!=NULL){	
			printf("\n%d %c\t", testa->studenti, testa->classe);
			testa=testa->succ;
		}
		printf("\n");
	}
	else{
		printf("Lista vuota: nulla da visualizzare\n");
	}
}

void inserisciInTesta(pNodo* testa, char classe, int studenti){
	pNodo pNuovoNodo;
	pNuovoNodo=NULL;
	pNuovoNodo=malloc(sizeof(nodo));
	if(pNuovoNodo!=NULL){
		pNuovoNodo->classe=classe;
		pNuovoNodo->studenti=studenti;
		pNuovoNodo->succ=*testa;
		*testa=pNuovoNodo;
		printf("Studente inserito: %c %d\n", pNuovoNodo->classe, pNuovoNodo->studenti);
	}
	else{
		printf("Errore creazione nodo.\n");
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
		printf("Lista eliminata.\n");
	}
	else{
		printf("Lista vuota: nulla da eliminare\n");
	}
}

void aggiungiInCoda(pNodo* testa, char classe, int studenti){ //mancava la classe 
	pNodo pNuovoNodo, temp;	
	pNuovoNodo=NULL;
	temp=NULL;
	if(*testa==NULL){
		inserisciInTesta(testa, classe, studenti); 
	}
	else{
		temp=*testa;
		pNuovoNodo=malloc(sizeof(nodo));	
		if(pNuovoNodo!=NULL){
			pNuovoNodo->studenti=studenti;
			pNuovoNodo->succ=NULL;
			while(temp->succ!=NULL){
				temp=temp->succ;
			}
			temp->succ=pNuovoNodo;
			printf("Dati appeso: %c %d\n", pNuovoNodo->classe, pNuovoNodo->studenti);
		}
		else{
			printf("Errore creazione nodo.\n");
		}
	}
}

int calcoloSomma(pNodo testa){
    int somma;
	somma=0;
	if(testa!=NULL){
		printf("\nCalcolo della somma.\n");
		while(testa!=NULL){
			somma=somma+testa->studenti;
			testa=testa->succ;
		}
	}
	else {
		printf("\nLista vuota: nulla da sommare.\n");
		somma=0;
	}
	return somma;
}

float calcoloMedia(pNodo testa){
	float media;
    int contatore=0;
    int somma;
    pNodo testaVecchia;
    testaVecchia=testa;
    media=0;
	somma=0;
	if(testa!=NULL){
		printf("\nCalcolo della media...\n");
		while(testa!=NULL){
			somma=somma+testa->studenti;
			testa=testa->succ;
			contatore++;
		}
		media=(float)calcoloSomma(testaVecchia)/contatore;
	}
	else {
		printf("\nLista vuota: nulla da sommare.\n");
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
		fclose(pFile);
	}
	else{
		printf("Errore nell'apertura del file %s", nomeFile);
	}
}

/*void caricaListaDalFile(){
	nodo nodoTemp;
	
	if(){
		
		}
		printf("lista caricata al file\n");
		fclose(pFile);
	}
	else{
	printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}

void leggiDalFile(){
	nodo nodoTemp;
	
	if(){
		
		}
		fclose(pFile);
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}

int recordNelFile(){
	
	
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
	return nRecord;
}*/
