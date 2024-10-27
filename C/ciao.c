#include <stdio.h>

main()
{
	int i;
	
	struct book				// dichiarazione della struttura r7-12
	{
		char  name;
		float price;
		int   pages;
	};
	struct book b1,b2,b3,b4;	// variabili della struttura
	
	// dichiarazioni alternative
	
	struct book2
	{
		char  name;
		float price;
		int   pages;
	} c1,c2,c3,c4;
	
	struct
	{
		char  name;
		float price;
		int   pages;
	} d1,d2,d3,d4;
	
	/*
	in questo modo non si puo'
	struct
	{
		char  name;
		float price;
		int   pages;
	};
	struct e1,e2,e3,e4;
	*/
	
	// una struttura può essere inizializzata congiuntamente alla sua dichiarazione
	struct book3
	{
		char  name[10];
		float price;
		int   pages;
	};
	struct book3 f1={"physics",130.00,789};
	struct book3 f2={"chemistry",30.00,89};
	
	
	
	printf("\n inserisci titolo, prezzo e numero di pagine per 4 libri\n");
	scanf(" %c%f%d",&b1.name,&b1.price,&b1.pages);
	scanf(" %c%f%d",&b2.name,&b2.price,&b2.pages);
	scanf(" %c%f%d",&b3.name,&b3.price,&b3.pages);
	scanf(" %c%f%d",&b4.name,&b4.price,&b4.pages);
	
	printf("\n i valori inseriti sono:");
	printf("\n %c %f %d",b1.name,b1.price,b1.pages);
	printf("\n %c %f %d",b2.name,b2.price,b2.pages);
	printf("\n %c %f %d",b3.name,b3.price,b3.pages);
	printf("\n %c %f %d",b4.name,b4.price,b4.pages);
}
