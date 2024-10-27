// Autore: Corrado Francesco		<------ compilare
// classe: 3LSA2

// calcolo dei numeri primi

#include <stdio.h>

int inputMassimo(void);												// <------- non modificare
int trovaNumeri(int *array, int dimensioneArray);					// <------- non modificare
void primi(int *array, int dimensioneArray, int* arrayIniziale);	// <------- non modificare
void output(int *array, int dimensioneArray, int massimo);			// <------- non modificare

main()
{
	int nMassimo, nPrimi; //Dichiaro nPrimi che verrà utilizzato dopo

	// DEFINIZIONE DEL NUMERO MASSIMO FINO A CUI CALCOLARE I NUMERI PRIMI
	printf("\n CALCOLO DEI NUMERI PRIMI");
	nMassimo=inputMassimo();
	int numeriTrovati[nMassimo];  //Inverto le due righe a causa dell'impossibilità nel dichiarare l'array senza avere prima assegnato un valore alla variabile nMassimo
	
	// RICERCA DEI NUMERI PRIMI FINO AL VALORE MASSIMO IMPOSTATO
	nPrimi=trovaNumeri(numeriTrovati,nMassimo);  //Assegna a nPrimi il valore di trovaNumeri che ritornerà la quantità totale di numeri primi, inoltre rimuovo la & essendo dato che è sbagliata sintatticamente

	// ARRAY (RIDIMENSIONATO) NUMERI PRIMI
	int numeriPrimi[nPrimi];  //Anche qui inverto le due righe in modo tale da dichiarare l'array per poi utilizzarlo nell'istruzione successiva
	primi(numeriPrimi, nPrimi, numeriTrovati); //Rimuovo l'assegnazione a nPrimi avendola fatta in precedenza, e rimuovo anche i due [0] errati

	// OUTPUT
	output(numeriPrimi, nPrimi, nMassimo);

	printf("\n\n");
}

int inputMassimo(void)
{
	int max;
	do
	{
		printf("\n Inserisci il numero massimo fin dove cercare i numeri primi : ");
		scanf("%d",&max);	
	}
	while(!(max>2));
	return max;
}

int trovaNumeri(int *array, int dimensioneArray)
{
	int pos=0;  //Assegno a pos il valore 0 per inizializzarlo
	int num;
	int check;
	int k;
	int trovati=0;  //Assegno a trovati il valore 0 per inizializzarlo
	printf("\n");  
	for(num=2;num<dimensioneArray+1;num++)
	{
		check=0;
		k=2;
		while((check==0)&&(k<num))  //Check deve essere posto uguale a 0, altrimenti il while viene saltato essendo check inizializzato a 0
		{
			if((num%k)==0){check=1;}  //Pongo check=1 dentro parentesi graffa, così che essa sia eseguito solo in caso in cui il numero non sia primo e quindi non viene considerato successivamente
			k++;
		}
		if(check==0)
		{
			trovati++;
			array[pos]=num;
			pos++;
		}
	}
	return trovati;  //Inserisco il valore "trovati" da ritonare al main tramite il return vuoto, che servirà nello main per determinare la lunghezza dell'array
}

void primi(int *array, int dimensioneArray, int* arrayIniziale)
{
	int k;
	for(k=0;k<dimensioneArray;k++) //Rimuovo -1 per il corretto funzionamento dell'output
	{
		array[k]=arrayIniziale[k]; //Rimuovo +1 per il corretto funzionamento dell'output
	}
}

void output(int *array, int dimensioneArray, int massimo)
{
	// questa funzione utilizza i puntatori
	int k;
	printf(" Tra 2 e %d sono presenti %d numeri primi :\n", dimensioneArray, massimo);
	for(k=0;k<dimensioneArray;k++)  //Rimuovo * da dimensioneArray in quanto non sto chiamando il puntatore della variabile ma la variabile stessa
	{
		printf(" %d",*(array+k)); //Pongo (array+k) tra parentesi e aggiungo *, per utilizzare i puntatori
	}
}
