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
		printf("0 esci\n");
		printf("Scelta?");
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
			case 9: 
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
void scriviFile(char* nomeVeicoli, char* modo){
	FILE* pFile;
	pFile=NULL;
	veicolo vettura;
	vettura.marca=' ';
	vettura.modello=' ';
	vettura.potenza=0;
	vettura.prezzo=0;
	pFile=fopen(nomeVeicoli, modo);
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
		printf("Errore nell'apertura del file %s:\n", nomeVeicoli);
	}
	fclose(pFile);
}
void svuotaFile(char* nomeVeicoli){
	FILE* pFile;	
	pFile=fopen(nomeVeicoli, "wb");
	if(pFile!=NULL){
		printf("File %s svuotato.\n", nomeVeicoli);
		fclose(pFile);
	}
	else{
		printf("Errore durante l\'apertura del file.%s.\n", nomeVeicoli);
	}
}
void eliminaFile(char* nomeVeicoli){
	remove(nomeVeicoli);
	printf("file %s eliminato\n",nomeVeicoli);
}
void copiaFile(char* nomeVeicoliA, char* nomeVeicoliB, char* modo){
	FILE *pFileA, *pFileB;
	pFileA=NULL;
	pFileB=NULL;
	veicolo vettura;
	vettura.marca=' ';
	vettura.modello=' ';
	vettura.potenza=0;
	vettura.prezzo=0;
	pFileA=fopen(nomeVeicoliA, "rb");
	pFileB=fopen(nomeVeicoliB, modo);
	if((pFileA!=NULL)&&(pFileB!=NULL)){
		while(fread(&vettura, sizeof(vettura), 1, pFileA)>0){
			fwrite(&vettura, sizeof(vettura), 1, pFileB);
		}
		printf("%s copiato nel %s.\n", nomeVeicoliA, nomeVeicoliB);
		fclose(pFileA);
		fclose(pFileB);	
	}
	else{
		if(pFileA==NULL){
			printf("errore durante l\'apertura del %s\n", nomeVeicoliA);
		}
		if(pFileB==NULL){
			printf("errore durante l\'apertura del %s\n", nomeVeicoliB);
		}
	}
}

