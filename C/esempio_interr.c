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
void inserisciInTesta(pNodo*, char, int);
void eliminaLista(pNodo*);
void aggiungiInCoda(pNodo*, int, char);
void salvaListaNelFile(pNodo, char*);
void caricaListaDalFile(pNodo*, char*); //Aggiunto * al pNodo
void leggiDalFile(char*);
float calcoloMedia(pNodo);

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
//	nodo.studenti=0;
//	nodo.classe=' ';       //Rimossi perchè inutili
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
					inserisciInTesta(&testa2, rand()%26+65, rand()%500+101);             //Prima inserisciInTesta(&testa2, studenti, classe); modificato così
					printf("Testa dopo la inserisciIntesta: %p\n", testa2);
					break;
			case 3: printf("\nTesta prima della aggiungiInCoda: %p\n", testa);
					aggiungiInCoda(&testa, rand()%70+140, rand()%26+65);  //Stessa cosa qui
					printf("Testa dopo la aggiungiInCoda: %p\n", testa);
					break;
			case 4: eliminaLista(&testa);
					eliminaLista(&testa2);
					break;
			case 5: salvaListaNelFile(testa, nomeFileA);
					salvaListaNelFile(testa2, nomeFileB); //Aggiunto ; alla fine della riga
					break;
			case 6: caricaListaDalFile(&testa, nomeFileA);
					caricaListaDalFile(&testa2, nomeFileB); //Aggiunta & davanti a testa
					break;
			case 7: leggiDalFile(nomeFileA);
					leggiDalFile(nomeFileB);
					break;
			case 8: media=calcoloMedia(testa);
			        if(media!=0)
						printf("\nLa media della prima lista e': %f\n\n", media);
					media=calcoloMedia(testa2);
			        if(media!=0)
						printf("\nLa media della seconda lista e': %f\n\n", media); //Tutto il menu è stato copiato dal mio File
					break;
			case 9: printf("Il numero massimo di studenti di 4LSA1CognomeNomeA.dat e': %d, di 4LSA1CognomeNomeB.dat e':  %d\n"); //Rimossa , inutile alla fine
					break;
	//		case 10: printf("Il numero di record nel file e': %d\n", recordNelFile());
	//				break;
			default: printf("\nScelta non accettabile. Rifai.\n");
		}
		getchar();
	    getchar(); //Aggiunti entrambi i getchar
	}while (scelta!=0); // (scelta==0) diventa (scelta!=0)
}
void visualizzaLista(pNodo testa){
	if(testa!=NULL){
		while(testa!=NULL){
			printf("%d\t",testa->studenti);
			printf("%c\t\n",testa->classe);
			testa=testa->succ; //Aggiunto testa=testa->succ;
		}
		printf("\n"); //Precedentemente prima del while, ora spostata qui
	}
	else{
		printf("Lista vuota: nulla da visualizzare\n");
	}
}
void inserisciInTesta(pNodo* testa, char classe, int studenti){
	pNodo pNuovoNodo;
	pNuovoNodo=NULL;
//	pNuovoNodo.classe=(97+rand()%(115-6+1));
//	pNuovoNodo.studenti=100+rand()%(500-100+1));
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
		inserisciInTesta(testa, classe, studenti);
	}
	else{
		temp=*testa;
		pNuovoNodo=malloc(sizeof(nodo));
		if(pNuovoNodo!=NULL){
			pNuovoNodo->studenti=studenti;
			pNuovoNodo->classe=classe;
			pNuovoNodo->succ=NULL; //Aggiunta questa riga
			while(temp->succ!=NULL){
				temp=temp->succ;
			}
			temp->succ=pNuovoNodo;
			printf("Dati appesi: %c\t%d\n", pNuovoNodo->classe, pNuovoNodo->studenti); //Erano inseriti cognome e statura dall'altro file lol
		}
		else{
			printf("Errore creazione nodo.\n");
		}
	}
}
int calcoloSomma(pNodo testa){
	int somma;
	somma=0;
	if(testa!=NULL){    //Inserita tutta la funzione calcolo somma
		printf("Calcolo della somma in corso.\n");
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

float calcoloMedia(pNodo testa){  //Inserito il pNodo testa
	float media;
	int contatore=0;
	pNodo testaVecchia;
	testaVecchia=testa;
	media=0;   //Inserite tutte le inizzializzazione prima dell'If
	if(testa!=NULL){
		printf("Calcolo della media in corso.\n");
		while(testa!=NULL){
			testa=testa->succ;
			contatore++;
		}
		media=(float)calcoloSomma(testaVecchia)/contatore;  //Inserita tutta la funzione di calcolo della media
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
	if((testa!=NULL)&&(pFile!=NULL)){ //NULL era scritto null
		while(testa!=NULL){
			fwrite(testa, sizeof(nodo), 1, pFile);
			testa=testa->succ;
		}
		printf("La lista e' stata correttamente salvata nel file.\n"); //Aggiunta solo per controllare
		fclose(pFile);
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}
void caricaListaDalFile(pNodo* testa, char* nomeFile){  //Aggiunto * a pNodo
	nodo nodoTemp;
	FILE* pFile;
	nodoTemp.classe=' ';
	nodoTemp.studenti=0;
	nodoTemp.succ=NULL;
	pFile=NULL;
	pFile=fopen(nomeFile, "rb");  //Aggiunto pFile= altrimenti era solo fopen(nomeFile, "rb");
	if(pFile!=NULL){
			while((fread(&nodoTemp, sizeof(nodo), 1, pFile))>0){ //Mancava una ) dopo pFile
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
	nodoTemp.studenti=0; //Messo studenti al posto di Studenti
	nodoTemp.succ=NULL;
	pFile=fopen(nomeFile, "rb");
	if(pFile!=NULL){
			while((fread(&nodoTemp, sizeof(nodo), 1, pFile))>0){
				printf("%c\t",nodoTemp.classe);  //messa la %c al posto di %d dato che si tratta di un char
				printf("%d\n",nodoTemp.studenti);  //cambiato studente con studenti
			}	
		    fclose(pFile);
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
}
/* int recordNelFile(){
	
	
	}
	else{
		printf("Errore nell'apertura del file %s\n", nomeFile);
	}
	return nRecord;
} */ 
