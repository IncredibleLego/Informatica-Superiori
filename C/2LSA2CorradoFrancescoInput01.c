#include <stdio.h>
main()
{
	int a,b,c;
	printf("\nInserisci il valori");
	scanf("%d%d", &a,&b);
	printf("Il valore di A=%d e di B=%d",a,b);
	c=b;
	b=a;
	a=c;
	printf("\nI valori scambaiti sono A=%d e B=%d",a,b);
	
	
	
}
