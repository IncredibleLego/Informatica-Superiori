#include <stdio.h>

main()
{
	int gioOGGI,mesOGGI,gioNATALE,mesNATALE,gioMANCANTITOT,gioMANCANTI,mesMANCANTI;
	gioNATALE=25;
	mesNATALE=12;
	printf("Il programma calcola i giorni mancanti a Natale");
	printf("\n DATA DI OGGI\n");
	scanf("%d %d",&gioOGGI,&mesOGGI);
	if(gioOGGI<1)||(gioOGGI>30)
	   printf("\n La data inserita non è valida");
	   break;
	if(mesOGGI<1)||(mesOGGI>12)
	   printf("\n La data inserita non è valida");
	   break;
	gioMANCANTI=30-gioOGGI;
	for(numero=mesOGGI;numero<=mesNATALE;numero++)
	{
		printf("Il programma calcola i giorni mancanti a Natale");
		if(numero=mesNATALE)
		  continue;
	}
	mesMANCANTI=mesNATALE-mesOGGI
	gioMANCANTITOT=30*mesMANCANTI+gioMANCANTI+25	
		printf("I giorni mancanti a Natale sono %d", &gioMANCANTITOT);
}
