//Autore: Francesco Corrado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s_veicolo{
	char marca;
	char modello;
	int potenza;
	int prezzo;
};
typedef struct s_veicolo veicolo;

void menu(char*, char*);
void leggiFile(char*);
void scriviFile(char*, char*);
void svuotaFile(char*);
void eliminaFile(char*);
void copiaFile(char*, char*, char*);
void mediaFile(char*, char*);
void minMax(char*, char*);


int main(){
	menu("veicoliA.dat", "veicoliB.dat");
	srand(time(NULL));
	return 0;
}

void menu(char* fileA, char* fileB){
	int scelta;
	scelta=0;
	do{
	//	printf("\e[1;1H\e[2J"); 
		system("cls"); 
		printf("1 visualizza i file: veicoliA. dat e veicoliB.dat\n");
		printf("2 scrivere un veicolo, distruggendo l'eventuale contenuto, nel file veicoliA.dat\n");
		printf("3 appendere un veicolo nel file veicoliA.dat\n");
		printf("4 svuotare i file veicoliA.dat e veicoliB.dat\n");
		printf("5 eliminare i file veicoliA.dat e veicoliB.dat\n");
		printf("6 copiare il file veicoliA.dat nel file veicoliB.dat\n");
		printf("7 appendi il file veicoliA.dat nel file veicoliB.dat\n");
		printf("8 appendere il file veicoliB.dat nel file veicoliA.dat\n");
		printf("9 calcolare e visualizzare la media dei prezzi dei veicoli contenuti nei file veicoliA.dat e veicoliB.dat\n");
		printf("10 calcolare e visualizzare il min ed il max delle potenze dei veicoli contenuti nel file veicoliA.dat e veicoliB.dat\n");
		printf("0 esci\n");
		printf("Scelta? ");
		scanf("%d", &scelta);
		switch(scelta){
			case 0: printf("Grazie, arrivederci\n");
					break;
			case 1: leggiFile(fileA);
					leggiFile(fileB);
					break;
			case 2: scriviFile(fileA, "wb");
					break;
			case 3: scriviFile(fileA, "ab");
					break;
			case 4: svuotaFile(fileA);
					svuotaFile(fileB);
					break;
			case 5: eliminaFile(fileA);
					eliminaFile(fileB);
					break;
			case 6: copiaFile(fileA, fileB, "wb");
					break;
			case 7: copiaFile(fileA, fileB, "ab");
					break;
			case 8: copiaFile(fileB, fileA, "ab");
					break;
			case 9: mediaFile(fileA, fileB);
					break;
			case 10: minMax(fileA, fileB);
			        break;
			default: printf("La scelta non è accettabile, devi rifare.\n");
		}
		getchar();
		getchar();
	}while(scelta!=0);
}

void leggiFile(char* nFile){
	FILE* pFile;
	pFile=NULL;
	veicolo vettura;
	vettura.marca=' ';
	vettura.modello=' ';
	vettura.potenza=0;
	vettura.prezzo=0;
	pFile=fopen(nFile, "rb");
	if(pFile!=NULL){
		printf("Visualizza file %s:\n", nFile);
		while(fread(&vettura, sizeof(vettura), 1, pFile)>0){
			printf("%c\t", vettura.marca);
			printf("%c\t", vettura.modello);
			printf("%d\t", vettura. potenza);
			printf("%d\n", vettura.prezzo);
		}
	}
	else
	{
		printf("Errore nell'apertura del file %s:\n", nFile);
	}
	fclose(pFile);
}
void scriviFile(char* nFile, char* modo){
	FILE* pFile;
	pFile=NULL;
	veicolo vettura;
	vettura.marca=' ';
	vettura.modello=' ';
	vettura.potenza=0;
	vettura.prezzo=0;
	pFile=fopen(nFile, modo);
	if(pFile!=NULL){
		srand(time(0));
		vettura.marca=(65+rand()%(90-65+1));
		vettura.modello=(97+rand()%(122-97+1));
		vettura.potenza=(10+rand()%(90-10+1));
		vettura.prezzo=(1000+rand()%(5000-1000+1));
		fwrite(&vettura, sizeof(vettura), 1, pFile);
		printf("File scritto\n");
	}
	else
	{
		printf("Errore nell'apertura del file %s:\n", nFile);
	}
	fclose(pFile);
}
void svuotaFile(char* nFile){
	FILE* pFile;	
	pFile=fopen(nFile, "wb");
	if(pFile!=NULL){
		printf("File %s svuotato.\n", nFile);
		fclose(pFile);
	}
	else{
		printf("Errore durante l\'apertura del file.%s.\n", nFile);
	}
}
void eliminaFile(char* nFile){
	remove(nFile);
	printf("file %s eliminato\n",nFile);
}
void copiaFile(char* nFileA, char* nFileB, char* modo){
	FILE *pFileA, *pFileB;
	pFileA=NULL;
	pFileB=NULL;
	veicolo vettura;
	vettura.marca=' ';
	vettura.modello=' ';
	vettura.potenza=0;
	vettura.prezzo=0;
	pFileA=fopen(nFileA, "rb");
	pFileB=fopen(nFileB, modo);
	if((pFileA!=NULL)&&(pFileB!=NULL)){
		while(fread(&vettura, sizeof(vettura), 1, pFileA)>0){
			fwrite(&vettura, sizeof(vettura), 1, pFileB);
		}
		printf("%s copiato nel %s.\n", nFileA, nFileB);
		fclose(pFileA);
		fclose(pFileB);	
	}
	else{
		if(pFileA==NULL){
			printf("errore durante l\'apertura del %s\n", nFileA);
		}
		if(pFileB==NULL){
			printf("errore durante l\'apertura del %s\n", nFileB);
		}
	}
}
void mediaFile(char* nFileA, char* nFileB){
	FILE *pFileA;
	FILE *pFileB;
	veicolo autoA;
	veicolo autoB;
	int somma;
	int n;
	pFileA=NULL;
	pFileB=NULL;
	autoA.prezzo=0;
	autoB.prezzo=0;
	somma=0;
	n=0;                                 //n serve per calcolare quanti prezzi sono presenti nei file e parte da zero
	pFileA=fopen(nFileA, "rb");
	pFileB=fopen(nFileB, "rb");
	float media=0.0;
	if((pFileA!=NULL)&&(pFileB!=NULL)){
			while(fread(&autoA, sizeof(autoA), 1, pFileA)>0){
				somma=somma+autoA.prezzo;
				n++;                                  //aumenta di uno ogni volta che c'è un prezzo
		}
		while(fread(&autoB, sizeof(autoB), 1, pFileB)>0){
			somma=somma+autoB.prezzo;
			n++;
		}
		media=somma/n;                                              //calcolo media
		printf("La media dei prezzi presenti nei file %s e %s e\' pari a: %0.2f\n", nFileA, nFileB, media);                          //%0.2f significa due cifre significative dopo lo zero
		fclose(pFileA);
		fclose(pFileB);	
	}
	else{
		if(pFileA==NULL){
			printf("Errore durante l\'apertura del file %s\n", nFileA);
		}
		if(pFileB==NULL){
			printf("Errore durante l\'apertura del file %s\n", nFileB);
		}
	}
}
void minMax(char* nFileA, char* nFileB){
	FILE *pFileA;
	FILE *pFileB;
    veicolo autoA;
    veicolo autoB;
    int min, max;
	pFileA=NULL;
	pFileB=NULL;
	autoA.potenza=0;
	autoB.potenza=0;
	min=91, max=9;                       //min=91 e max=9 perchè così sono sicuro che il primo numero controllato sia settato sia come minimo che come massimo (dato che il range per creare i numeri è 10-90)
	pFileA=fopen(nFileA, "rb");
	pFileB=fopen(nFileB, "rb");
	if((pFileA!=NULL)&&(pFileB!=NULL)){
			while(fread(&autoA, sizeof(autoA), 1, pFileA)>0){
				if(autoA.potenza>max){
					max=autoA.potenza;
				}
				if(autoA.potenza<min){
					min=autoA.potenza;
				}
		}
		while(fread(&autoB, sizeof(autoB), 1, pFileB)>0){
			if(autoB.potenza>max){
					max=autoB.potenza;
				}
				if(autoB.potenza<min){
					min=autoB.potenza;
				}
		}
		printf("Il minimo contenuto nei file %s e %s e\': %d",nFileA, nFileB, min);
		printf("\nIl massimo contenuto nei file %s e %s e\': %d",nFileA,nFileB, max);
		fclose(pFileA);
		fclose(pFileB);	
	}
	else{
		if(pFileA==NULL){
			printf("Errore durante l\'apertura del file %s\n", nFileA);
		}
		if(pFileB==NULL){
			printf("Errore durante l\'apertura del file %s\n", nFileB);
		}
	}
}
