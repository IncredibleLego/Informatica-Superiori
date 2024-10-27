#include <stdlib.h>
#include <stdio.h>
int main(){
	int altezza, area, base;
	printf("Calcolo area di un rettangolo dati in input base ed altezza.\n");
	printf("Base?");
	scanf("%d", &base);
	printf("Altezza?");
	scanf("%d", &altezza);
	area=base*altezza;
	printf("Area=%d\n", area);
	getchar();
	return 0;
}
