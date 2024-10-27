#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct s_nodo{//12B
	int dato; //4B
	struct s_nodo *succ; //8B
};
typedef struct s_nodo nodo; //12B
typedef nodo* pNodo; //8B
void pulisciSchermo();
void menu();
void visualizzaLista(pNodo);
void inserisciInTesta(pNodo*);
void eliminaLista(pNodo*);
void aggiungiInCoda(pNodo);
int calcoloSomma(pNodo);
float calcoloMediaLista(pNodo);
int main() {
	srand((unsigned)time(NULL));
	menu();
	printf("Grazie per aver usato il mio programma. R.Zoni. Arrivederci.");
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
	scelta=0;
	somma=0;
	testa=NULL;
	do{
		pulisciSchermo();
		printf("0 uscita\n");
		printf("1 inserisci in testa\n");
		printf("2 visualizza lista\n");
		printf("3 elimina lista\n");
		printf("4 aggiungi in coda\n");
		printf("5 calcola la somma dei valori del campo dato\n");
		printf("6 calcola la media dei valori del campo dato\n");
		printf("Scelta?  ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: break;
			case 1: printf("\nTesta prima della inserisciIntesta: %p\n", testa);
					inserisciInTesta(&testa);
					printf("Testa dopo la inserisciIntesta: %p\n", testa);
					break;
			case 2: printf("\nTesta prima della visualizza: %p\n", testa);
					visualizzaLista(testa);
					printf("Testa dopo la visualizza: %p\n", testa);
					break;
			case 3: eliminaLista(&testa);
					break;
			case 4: if(testa==NULL){
						printf("\nTesta prima della aggiungiInCoda (inserisciIntesta): %p\n", testa);
						inserisciInTesta(&testa);
						printf("Testa dopo la aggiungiInCoda (inserisciIntesta): %p\n", testa);
					}
					else{
						printf("\nTesta prima della aggiungiInCoda: %p\n", testa);
						aggiungiInCoda(testa);
						printf("Testa dopo la aggiungiInCoda: %p\n", testa);
					}
					break;
			case 5: somma=calcoloSomma(testa);
					if(somma!=0)
						printf("La somma di tutti i valori del campo dato della lista e\':  %d\n", somma);
					break;
			case 6: media=calcoloMediaLista(testa);
			        if(testa!=0)
						printf("La media di tutti i valori del campo dato della lista e\':  %f\n", media);
					break;
			default: printf("\nScelta non accettabile. Rifai.\n");
		}
		getchar();
		getchar();
	}while (scelta!=0);
}
void visualizzaLista(pNodo testa){
	if(testa!=NULL){
		while(testa!=NULL){	//scorrimento lista
			printf("%d\t", testa->dato);
			testa=testa->succ;
		}
		printf("\n");
	}
	else{
		printf("Lista vuota: nulla da visualizzare\n");
	}
}
void inserisciInTesta(pNodo* testa){
	pNodo pNuovoNodo;	//8B
	pNuovoNodo=NULL;
	pNuovoNodo=malloc(sizeof(nodo));	//12B
	if(pNuovoNodo!=NULL){
		printf("Inserisco il dato random\n");
		pNuovoNodo->dato=rand()%10+1;
		pNuovoNodo->succ=*testa;
		*testa=pNuovoNodo;
		printf("Dato random inserito: %d\n", pNuovoNodo->dato);
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
			*testa=(*testa)->succ;	//*testa=temp->succ;
			free(temp);
		}
		printf("\n");
		printf("Lista eliminata.\n");
	}
	else{
		printf("Lista vuota: nulla da eliminare\n");
	}
}
void aggiungiInCoda(pNodo testa){
	pNodo pNuovoNodo;	//8B
	pNuovoNodo=NULL;
	pNuovoNodo=malloc(sizeof(nodo));	//12B
	if(pNuovoNodo!=NULL){
		printf("Appendo il dato random\n");
		pNuovoNodo->dato=rand()%26+65;
		pNuovoNodo->succ=NULL;
		while(testa->succ!=NULL){
			testa=testa->succ;
		}
		testa->succ=pNuovoNodo;
		printf("Dato random appeso: %d\n", pNuovoNodo->dato);
	}
	else{
		printf("Errore creazione nodo.\n");
	}
}
int calcoloSomma(pNodo testa){
	int somma;
	somma=0;
	if(testa!=NULL){
		printf("\nCalcolo della somma...\n");
		while(testa!=NULL){
			somma=somma+testa->dato;
			testa=testa->succ;
		}
	}
	else {
		printf("\nLista vuota: nulla da sommare.\n");
		somma=0;
	}
	return somma;
}
float calcoloMediaLista(pNodo testa){
	int i;
	float somma, media;
	somma=0.0;
	media=0.0;
	if(testa!=NULL){
		printf("\nCalcolo della media...\n");
		while(testa!=NULL){
			somma=somma+testa->dato;
			testa=testa->succ;
			i++;
		}
		media=somma/i;
	}
	else {
		printf("\nLista vuota: impossibile trovare la media.\n");
		media=0;
	}
	return media;
}
