#include <stdio.h>
main()
{
	int risposta,punteggio,scelta;
	printf("\t\t\tGIOCO A QUIZ\n");
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t   DI FRANCESCO CORRADO    ") ;
    printf("\n\t\t________________________________________");
    printf("\n\t\t________________________________________");
    printf("\n\t\t > Inserisci e invia P per cominciare la partita");
    printf("\n\t\t > Inserisci e invia un altra lettera per uscire");
    printf("\n\t\t________________________________________\n\n");
    scanf("%c",&scelta);
    if(scelta==112)
    {
    	printf("\n\t\tCominciamo con il quiz allora!");
    	printf("\n\t\tDomanda 1");
    	printf("\n\n\n\t\tQuanti sono gli stati che fanno attualmente parte dell'unione Europea?");
		printf("\n\n\t\t1.27\t\t2.20\n\n\t\t3.22\t\t4.18\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==1)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 1.27");
		}
		printf("\n\n\t\tDomanda 2");
    	printf("\n\n\n\t\tLa parola genetliaco significa:");
		printf("\n\n\t\t1.Battesimo\t\t2.Compleanno\n\n\t\t3.Matrimonio\t\t4.Patrimonio genetico\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==2)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 2.Compleanno");
		}
		printf("\n\n\t\tDomanda 3");
    	printf("\n\n\n\t\tJohann Gutenberg è diventato famoso per..");
		printf("\n\n\t\t1.Aver tradotto e trascritto l'Iliade e l'Odissea\t\t2.Aver interpretato la scrittura cuneiforme\n\n\t\t3.Aver scoperto le rovine di Troia\t\t4.Aver migliorato la produttivita' industriale tedesca\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==4)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 4.Aver migliorato la produttivita' industriale tedesca");
		}
		printf("\n\n\t\tDomanda 4");
    	printf("\n\n\n\t\tIl nome del celeberrimo cavallo di Alessandro Magno");
		printf("\n\n\t\t1.Niceforo\t\t2.Bucefalo\n\n\t\t3.Menelao\t\t4.Alkis\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==2)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 2.Bucefalo");
		}
		printf("\n\n\t\tDomanda 5");
    	printf("\n\n\n\t\tI colori detti primari sono:");
		printf("\n\n\t\t1.Il blu il verde e il rosso\t\t2.Il rosso, il bianco e il blu\n\n\t\t3.Il giallo il rosso e il blu\t\t4.Il giallo il rosso e il verde\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==3)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 3.Il giallo il rosso e il blu");
		}
		printf("\n\n\t\tDomanda 6");
    	printf("\n\n\n\t\tLa parola Tartan si riferisce a");
		printf("\n\n\t\t1.Un caratteristico tessuto\t\t2.Una salsa a base di maionese\n\n\t\t3.Un piatto a base di carne cruda\t\t4.Un Comune svizzero\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==1)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 1.Un caratteristico tessuto");
		}
		printf("\n\n\t\tDomanda 7");
    	printf("\n\n\n\t\tLo scirocco e' un vento che proviene da:");
		printf("\n\n\t\t1.Ovest\t\t2.Sud\n\n\t\t3.Sud-ovest\t\t4.Sud-est\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==4)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 4.Sud-est");
		}
		printf("\n\n\t\tDomanda 8");
    	printf("\n\n\n\t\tL’aforisma 'Colui che potendo esprimere un concetto in dieci parole ne usa dodici, io lo ritengo capace delle peggiori azioni' è stato pronunciato da");
		printf("\n\n\t\t1.Dante Alighieri\t\t2.Lodovico Ariosto\n\n\t\t3.Giosue' Carducci\t\t4.Italo Calvino\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==3)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 3.Giosue' Carducci");
		}
		printf("\n\n\t\tDomanda 9");
    	printf("\n\n\n\t\tL’artista Frida Khalo era di nazionalita':");
		printf("\n\n\t\t1.Boliviana\t\t2.Messicana\n\n\t\t3.Ungherese\t\t4.Portoricana\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==2)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 2.Messicana");
		}
		printf("\n\n\t\tDomanda 10");
    	printf("\n\n\n\t\tQuale tra i seguenti animali non è un pesce:");
		printf("\n\n\t\t1.Delfino\t\t2.Sarago\n\n\t\t3.Cernia\t\t4.Gallinella\n");
		do
		{
			scanf("%d",&risposta);
		}
		while(risposta<0||risposta>5);
		if(risposta==1)
		{
			printf("\n\t\tRiposta esatta!");
			punteggio++;
		}
		else
		{
			printf("\n\t\tRisposta errata! La risposta corretta era 1.Delfino");
		}
		printf("\n\n\t\tIl quiz e' finito! Il tuo punteggio e' stato di %d/10",punteggio);
	}
	else
	{
		printf("\n\t\tProgramma arrestato con successo");
	}
	
}
