#include <stdio.h>
#include <stdlib.h>
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
void sommaNodi(pNodo);
int main() {
	menu();
	printf("Grazie per aver usato il mio programma. R.Zoni. Arrivederci.");
	getchar();
	return 0;
}
//Using macros you can check if you're on Windows, Linux, Mac or Unix,
//and call the respective function depending on the current platform. 
void pulisciSchermo(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
void menu(){
	int scelta;
	pNodo testa;
	scelta=0;
	testa=NULL;
	do{
		pulisciSchermo();
		printf("0 uscita\n");
		printf("1 inserisci in testa\n");
		printf("2 visualizza lista\n");
		printf("3 elimina lista\n");
		printf("4 aggiungi in coda\n");
		printf("5 somma i nodi contenuti in testa\n");
		printf("Scelta?");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: break;
			case 1: printf("Testa prima della inserisciIntesta: %p\n", testa);
					inserisciInTesta(&testa);
					printf("Testa dopo la inserisciIntesta: %p\n", testa);
					break;
			case 2: printf("Testa prima della visualizza: %p\n", testa);
					visualizzaLista(testa);
					printf("Testa dopo la visualizza: %p\n", testa);
					break;
			case 3: eliminaLista(&testa);
					break;
			case 4: if(testa==NULL){
						printf("Testa prima della aggiungiInCoda (inserisciIntesta): %p\n", testa);
						inserisciInTesta(&testa);
						printf("Testa dopo la aggiungiInCoda (inserisciIntesta): %p\n", testa);
					}
					else{
						printf("Testa prima della aggiungiInCoda: %p\n", testa);
						aggiungiInCoda(testa);
						printf("Testa dopo la aggiungiInCoda: %p\n", testa);
					}
					break;
			case 5: sommaNodi(testa);
			        break;
			default: printf("Scelta non accettabile. Rifai.\n");
		}
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
	getchar();
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
	getchar();
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
	getchar();
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
	getchar();
}
void sommaNodi(pNodo testa){
	int sommaNodi;
	if(testa!=NULL){
		while(testa!=NULL){
			sommaNodi=sommaNodi+testa->dato; 
		}
		printf("\nLa somma dei nodi all'interno della lista e' uguale a: %d \n", sommaNodi); 
	}
	else{
		printf("La lista e' vuota. Riprovare dopo aver inserito dei valori.\n");
	}
	getchar(); 
}
