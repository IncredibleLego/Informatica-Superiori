#include <stdlib.h>
#include <stdio.h>
int main(){
	int area, lato;
	printf("Calcolo area di un quadrato dato in input il lato.\n");
	printf("Lato?");
	scanf("%d", &lato);
	area=lato*lato;
	printf("Area=%d\n", area);
	getchar();
	return 0;
}
