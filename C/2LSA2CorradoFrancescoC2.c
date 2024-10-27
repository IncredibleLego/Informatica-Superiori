#include <stdio.h>

main()
{
	int gio1,mes1,ann1,gio2,mes2,ann2,gio,mes,ann;
	printf("Inserisci la prima data:\n ");
	scanf("%d, %d, %d", &gio1, &mes1, &ann1);
	printf("\nInserisci la seconda data (maggiore della prima):\n ");
	scanf("%d, %d, %d", &gio2, &mes2, &ann2);
	printf("\n%d, %d, %d", &gio2, &mes2, &ann2);
	gio=gio1;
	mes=mes1;
	ann=ann1;
	while (!(gio==gio2 && mes==mes2 && ann==ann2));
	{
		printf("\n%d, %d, %d", &gio, &mes, &ann);
		gio=gio+1;
		if (gio==31)
	    {
			gio=1;
			mes=mes+1;
	   	} 
		if (mes==13)
		{
			mes=1;
			ann=ann+1;
		}
		
	}
	printf("\n%d, %d, %d", &gio, &mes, &ann);	
	
}

