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

int main() {
	menu();
	printf("Grazie per aver usato il mio programma. F.Corrado. Arrivederci.");
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
			default: printf("Scelta non accettabile. Rifai.\n");
		}
		getchar();
	}while (scelta!=0);
	eliminaLista(&testa);
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
void eliminaLista(pNodo* testa){
	pNodo a,b,c;
	if(*testa==NULL){
		printf("Non posso eliminare niente dato che testa e' vuota");
	}else{
		a=*testa;
		while(a->succ!=NULL){
			b=a->succ;
			a->succ=a->succ->succ;
			free(b);
		}
		printf("La lista e' stata svuotata con successo");
	}
	c=*testa;
	*testa=(*testa)->succ;
	free(c);
	getchar();
}
