#include <stdio.h>
main()

{
	int numero, valIniziale,numAggiunto,numAggiuntoDue;
	printf ("Chiede di inserire un valore e trova un valore che aggiunto al primo dia 100 se possibile, e se possibile anche 1000");
	printf ("\nInserisci ora il numero iniziale: ");
	scanf("%d",&numero);
	numAggiunto=0;
	for(valIniziale=numero;valIniziale>-1;numAggiunto=numAggiunto+1)               
	{
		if(numAggiunto+valIniziale>100)
		     printf("Il valore inserito e maggiore di 100");
		     break;
	    if(100-valIniziale==numAggiunto)
		 {
			for(numAggiuntoDue=numAggiunto;valIniziale>99;numAggiuntoDue=numAggiuntoDue+1)
			{
				if(valIniziale+numAggiuntoDue==1000)
				 continue;
			}
			printf("\nI valori necessari sono: %d per ottenere 100 e %d per ottenere 1000", &numAggiunto,&numAggiuntoDue);
		 }
	}
	
	
}
