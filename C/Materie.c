//Autore: Franesco Corrado

#include <stdio.h>
#include <string.h>

main()
{
	printf("Il programma chiede che giorno e' e la materia e restituisce \ncome output se la materia e' presente quel giorno oppure no");
	char giorno[4];
	char materia[20];
	int ing, rel, mate, filo, arte, ita, fis, scie, sto, info, mot;
	printf("\n\nInserire il giorno (lun mar mer gio ven sab dom): ");
	scanf(" %[^\n]s", giorno);
	printf("\n\nInserire la materia fra le seguenti (in minuscolo): \n Inglese\n Religione\n Matematica\n Filosofia\n Arte\n Italiano\n Fisica\n Scienze\n Storia\n Informatica\n Motoria");
	scanf(" %[^\n]s", materia);
	if(giorno=="lun")
	{
		ing=1;
		rel=1;
		mate=1;
		filo=1;
	}
	if(giorno=="mar")
	{
		arte=1;
		mate=1;
		ing=1;
		ita=1;
	}
	if(giorno=="mer")
	{
		ing=1;
		mate=1;
		fis=1;
		scie=1;
	}
	if(giorno=="gio")
	{
		scie=1;
		arte=1;
		ita=1;
		fis=1;
		sto=1;
	}
	if(giorno=="ven")
	{
		scie=1;
		fis=1;
		mate=1;
		ing=1;
		mot=1;
	}
	if(giorno=="sab")
	{
		sto=1;
		ita=1;
		scie=1;
		filo=1;	
	}
	if(materia=="inglese")
	{
		if(ing=1)
		{
			printf("\n\n La materia inglese e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia inglese non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="religione")
	{
		if(rel=1)
		{
			printf("\n\n La materia religione e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia religione non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="matematica")
	{
		if(mate=1)
		{
			printf("\n\n La materia matematica e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia matematica non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="filosofia")
	{
		if(filo=1)
		{
			printf("\n\n La materia filosofia e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia filosofia non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="arte")
	{
		if(arte=1)
		{
			printf("\n\n La materia arte e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia arte non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="italiano")
	{
		if(ita=1)
		{
			printf("\n\n La materia italiano e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia italiano non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="fisica")
	{
		if(fis=1)
		{
			printf("\n\n La materia fisica e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia fisica non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="scienze")
	{
		if(scie=1)
		{
			printf("\n\n La materia scienze e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia scienze non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="storia")
	{
		if(sto=1)
		{
			printf("\n\n La materia storia e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia storia non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="informatica")
	{
		if(info=1)
		{
			printf("\n\n La materia informatica e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia informatica non e' presente nella giornata di %d", giorno);
		}
	}
	if(materia=="motoria")
	{
		if(mot=1)
		{
			printf("\n\n La materia motoria e' presente nella giornata di %d", giorno);
		}
		else
		{
			printf("\n\n La materia motoria non e' presente nella giornata di %d", giorno);
		}
	}
}
