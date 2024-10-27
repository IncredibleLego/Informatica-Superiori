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

void menu();
void visualizzaLista(pNodo);
void inserisciInTesta(pNodo*, int, char);
void eliminaLista(pNodo*);
void aggiungiInCoda(pNodo*, int, char);
void salvaListaNelFile(pNodo, char*);
void caricaListaDalFile(pNodo, char*);
void leggiDalFile(char*);

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
	int scelta, somma;
	float media;
	pNodo testa;
	pNodo testa2;
	char* nomeFileA;
	char* nomeFileB;
	nodo.studenti=0;
	nodo.classe=' ';
	scelta=0;
	somma=0;
	media=0;
	testa=NULL;
	testa2=NULL;
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
		printf("8 calcola media peso in listaA e in listaB\n");
		printf("9 calcola peso massimo di 4LSA1CognomeNomeA.dat e di 4LSA1CognomeNomeB.dat\n");
		printf("10 elimina nodo con peso scelto dall'utente in listaA e in listaB\n");
		printf("Scelta?  ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: break;
			case 1: visualizzaLista(testa);
					visualizzaLista(testa2);
					break;
			case 2: printf("\nTesta prima della inserisciIntesta: %p\n", testa2);
					inserisciInTesta(&testa2, studenti, classe);
					printf("Testa dopo la inserisciIntesta: %p\n", testa2);
					break;
			case 3: printf("\nTesta prima della aggiungiInCoda: %p\n", testa);
					aggiungiInCoda(&testa, studenti, classe);
					printf("Testa dopo la aggiungiInCoda: %p\n", testa);
					break;
			case 4: eliminaLista(&testa);
					eliminaLista(&testa2);
					break;
			case 5: salvaListaNelFile(testa, nomeFileA);
					salvaListaNelFile(testa2, nomeFileB)
					break;
			case 6: caricaListaDalFile(testa, nomeFileA);
					caricaListaDalFile(testa2, nomeFileB);
					break;
			case 7: leggiDalFile(nomeFileA);
					leggiDalFile(nomeFileB);
					break;
			case 8: printf("Il numero medio di studenti della listaA e':  %d, della listaB e': %d'\n", );
					break;
			case 9: printf("Il numero massimo di studenti di 4LSA1CognomeNomeA.dat e': %d, di 4LSA1CognomeNomeB.dat e':  %d\n", );
					break;
			case 10: printf("Il numero di record nel file e': %d\n", recordNelFile());
					break;
			default: printf("\nScelta non accettabile. Rifai.\n");
		}
	}while (scelta==0);
}
void visualizzaLista(pNodo testa){
	if(testa!=NULL){
		printf("\n");
		while(testa!=NULL){
			printf("%d\t",testa->studenti);
			printf("%c\t",testa->classe);
		}
	}
	else{
		printf("Lista vuota: nulla da visualizzare\n");
	}
}
void inserisciInTesta(pNodo* testa, int studenti, char classe){
	pNodo pNuovoNodo;
	pNuovoNodo=NULL;
	pNuovoNodo.classe=(97+rand()%(115-6+1));
	pNuovoNodo.studenti=100+rand()%(500-100+1));
	pNuovoNodo=malloc(sizeof(nodo));
	if(pNuovoNodo!=NULL){
		pNuovoNodo->studenti=studenti;
		pNuovoNodo->classe=classe;
		pNuovoNodo->succ=*testa;
		*testa=pNuovoNodo;
		printf("Dati inseriti.\n");
	}
	
}
void eliminaLista(pNodo* testa){
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
void aggiungiInCoda(pNodo* testa, int studenti, char classe){
	pNodo pNuovoNodo, temp;
	pNuovoNodo=NULL;
	temp=NULL;
	if(*testa==NULL){
		inserisciInTesta(testa, studenti, classe);
	}
	else{
		temp=*testa;
		pNuovoNodo=malloc(sizeof(nodo));
		if(pNuovoNodo!=NULL){
			pNuovoNodo->studenti=studenti;
			pNuovoNodo->classe=classe;
			while(temp->succ!=NULL){
				temp=temp->succ;
			}
			temp->succ=pNuovoNodo;
			printf("Dati appesi: %c\t%d\n", pNuovoNodo->inizCognome, pNuovoNodo->statura);
		}
		else{
			printf("Errore creazione nodo.\n");
		}
	}
}
int calcoloSomma(pNodo testa){
	int somma;
	somma=0;
	if(){
		
	}
	else {
		printf("\nLista vuota: nulla da sommare.\n");
		somma=0;
	}
	return somma;
}

float calcoloMedia(){
	
	if(testa!=NULL){
		
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
	if((testa!=NULL)&&(pFile!=null)){
		while(testa!=NULL){
			fwrite(testa, sizeof(nodo), 1, pFile);
			testa=testa->succ;
		}
		fclose(pFile);
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}
void caricaListaDalFile(pNodo testa, char* nomeFile){
	nodo nodoTemp;
	FILE* pFile;
	nodoTemp.classe=' ';
	nodoTemp.studenti=0;
	nodoTemp.succ=NULL;
	pFile=NULL;
	fopen(nomeFile, "rb");
	if(pFile!=NULL){
			while((fread(&nodoTemp, sizeof(nodo), 1, pFile)>0){
				aggiungiInCoda(testa, nodoTemp.studenti, nodoTemp.classe);
			}
			printf("lista caricata al file\n");
			fclose(pFile);
	}
	else{
	printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}
void leggiDalFile(char* nomeFile){
	nodo nodoTemp;
	FILE* pFile;
	pFile=NULL;
	nodoTemp.classe=' ';
	nodoTemo.Studenti=0;
	nodoTemp.succ=NULL;
	pFile=fopen(nomeFile, "rb");
	if(pFile!=NULL){
			while((fread(&nodoTemp, sizeof(nodo), 1, pFile))>0){
				printf("%d\t",nodoTemp.classe);
				printf("%d\t",nodoTemp.studente);
			}	
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
}
