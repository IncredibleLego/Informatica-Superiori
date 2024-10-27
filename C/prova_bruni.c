#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUANTI 2
struct s_auto{
	char marca;
	char modello;
	int potenza;
	int prezzo;
};
typedef struct s_auto car;
void menu(char*, char*, int);
void inizializzaTabella(car*, int);

main(){
	menu("fileStruct.dat", "fileCopia.dat", QUANTI);
	return 0;
}

void menu(char* fileS, char* fileC, int quanti){
	int scelta=0;
	auto autoA[quanti], autoB[quanti];
	inizializzaTabella(autoA, quanti);
	inizializzaTabella(autoB, quanti);
}

void inizializzaTabella(car* a, int quanti){
	int i;
	i=0;
	for(i=0;i<quanti;i++){
		a[i].marca=' ';
		a[i].modello=' ';
		a[i].potenza=0;
		a[i].prezzo=0;
	}
}
