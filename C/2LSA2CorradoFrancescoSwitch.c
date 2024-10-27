#include <stdio.h>
// istruzione switch

main()
{
	int a,b,i;
	
	printf("\n\nFOR");
	for(i=0;i<=10;i++)
	{
		printf("\n%d",i);
	}
	
	printf("\n\nWHILE");
	a=1;
	while(a<=10)
	{
		printf("\n%d",a);
		a++;
	}
	
	printf("\nDO-WHILE");
	b=1;
	do
	{
		printf("\n%d",b);
		b++;
	}
	while(b<=10);
}
