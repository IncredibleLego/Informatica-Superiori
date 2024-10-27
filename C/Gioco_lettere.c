//Autore Francesco Corrado 27/07/2021

#include <stdio.h>
#include <string.h>

//Il programma genera delle lettere casuali e chiede all'utente di creare una parola con le lettere generate, l'utente vince se ci riesce

main()
{
	char risposta;
	printf("--------------------------------");
	printf("\n\n         WORDS GAME");
	printf("\n\n         Vuoi giocare?");
	do
	{
		printf("\n\n   (Inserire S per si e N per no)\n          ");
	    scanf("%c", &risposta);
	    if(!((risposta=='S')||(risposta=='N')))
	    {
	    	printf("\nLa risposta inserita e' invalida");
		}
	}
	while(!((risposta=='S')/*||(risposta=='N'))*/);
	if(risposta == 'S')
	{
		printf("\n\n  Bene cominciamo!");
	}
	else
	{
		printf("\n\n  Programma terminato.");
	}
}
