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

int main(){
	menu("veicoliA.dat", "veicoliB.dat");
	srand(time(NULL));
	return 0;
}

void menu(char* nomeFile1, char* nomeFile2){
	int scelta;
	scelta=0;
	do{
		printf("\e[1;1H\e[2J"); 
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
		switch (scelta){
			case 0: printf("Grazie, arrivederci\n");
			        break;
			case 1: leggiFile(nomeFile1);
			        leggiFile(nomeFile2);
			        break;
			case 2: scriviFile(nomeFile1, "w");
			        break;
			case 3: scriviFile(nomeFile1, "a");
			        break;
			case 4: svuotaFile(nomeFile1);
			        svuotaFile(nomeFile2);
			        break;
			case 5: eliminaFile(nomeFile1);
			        eliminaFile(nomeFile2);
			        break;
			case 6: copiaFile(nomeFile1, nomeFile2, "wb");
			        break;
			case 7: copiaFile(nomeFile1, nomeFile2, "ab");
			        break;
			case 8: copiaFile(nomeFile2, nomeFile1, "ab");
			        break;
			default: printf("Scelta non accettabile, rifai");
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
		printf("File %s:\n", pFile);
		while(fread(&vettura, sizeof(vettura), 1, pFile)>0){
			printf("%c\t", vettura.marca);
			printf("%c\t", vettura.modello);
			printf("%d\t", vettura.potenza);
			printf("%d\n", vettura.prezzo);
		}
	}else{
		printf("Impossibile aprire il file %s\n", pFile);
	}
	fclose(pFile);
}

void scriviFile(char* nFile, char* modo){
	FILE* pFile;
	pFile=NULL;
	veicolo vettura;
	pFile=fopen(nFile, modo);
	if(pFile!=NULL){
		srand(time(0));
		vettura.marca=(65+rand()%(90-65+1));
		vettura.modello=(97+rand()%(122-97+1));
		vettura.potenza=(10+rand()%(90-10+1));
		vettura.prezzo=(1000+rand()%(5000-1000+1));
		fwrite(&vettura, sizeof(vettura), 1, pFile);
		printf("La scrittura del file e' avvenuta con successo\n");
	}else{
		printf("Impossibile aprire il file %s\n", pFile);
	}
	fclose(pFile);
}

void svuotaFile(char* nFile){
	FILE* pFile;
	pFile=NULL;
	pFile=fopen(nFile, "wb");
	if(pFile!=NULL){
		printf("Il file %s e' stato svuotato con successo\n", nFile);
		fclose(pFile);
	}else{
		printf("Impossibile aprire il file %s\n", pFile);
	}
}

void eliminaFile(char* nFile){
	remove(nFile);
	printf("Il file %s e' stato eliminato con successo", nFile);
}

void copiaFile(char* nFile1, char* nFile2, char* modo){
	FILE* pFile;
	FILE* pFile2;
	pFile=NULL;
	pFile2=NULL;
	veicolo vettura;
	pFile=fopen(nFile1, "rb");
	pFile2=fopen(nFile2, modo);
	if((pFile!=NULL)&&(pFile2!=NULL)){
		while(fread(&vettura, sizeof(vettura), 1, pFile)>0){
			fwrite(&vettura, sizeof(vettura), 1, pFile2);
		}
		printf("Il file %s e' stato copiato nel file %s con successo", pFile, pFile2);
		fclose(pFile);
		fclose(pFile2);
	}else{
		if(pFile==NULL){
			printf("Impossibile aprire il file %s\n", pFile);
		}
		if(pFile2==NULL){
			printf("Impossibile aprire il file %s\n", pFile2);
		}
	}
}



