//Autore: Francesco Corrado

#include <stdio.h>

main()
{
	char name[]={'p', 'r', 'o', 'v', 'a','\0'};
	char name2[]="prova";
	
	int i;
	
	printf("\n");
	for(i=0;i<6;i++) printf("%c", name2[i]);
	
	i=0;
	while(name2[i]!='\0')
	{
		printf("%c", name2[i]);
		i++;
	}
	
	printf("\n\n");
}
