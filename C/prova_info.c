#include <stdio.h>
#include <string.h>

main()
{
	int n;
	printf("Inserisci la dimensione della stringa: ");
	scanf("%d", &n);
	char str[n];
	printf("Inserire il nome nella stringa: ");
	scanf(" %[^\n]s", str);
	printf("Il nome inserito e' %s", str);
}
