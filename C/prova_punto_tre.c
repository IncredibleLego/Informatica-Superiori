#include <stdio.h>
#include <string.h>

main()
{
	char mtr[4][5]={
	{'t','o','m','m','y'},
	{'_','s','e','i','_'},
	{'_','u','n','_','_'},
	{'c','l','o','w','n'},
	};
	int i, k;
	for (i=0;i<4;i++)
	{
		for(k=0;k<5;k++)
		{
			printf("%c", mtr[i][k]);
		}
		printf("\n");
	}
	printf("\n\nArray con i valori della matrice: ");
	char stringa[20];
	char stringa2[20];
	char stringa3[20];
	char stringa4[20];
	for(i=0;i<5;i++)
	{
	  stringa[i]=mtr[0][i];
	}

	for(i=0;i<5;i++)
	{
		printf("%c", stringa[i]);
	}
	for(i=0;i<5;i++)
	{
	  stringa2[i]=mtr[1][i];
	}

	for(i=0;i<5;i++)
	{
		printf("%c", stringa2[i]);
	}
	for(i=0;i<5;i++)
	{
	  stringa3[i]=mtr[2][i];
	}

	for(i=0;i<5;i++)
	{
		printf("%c", stringa3[i]);
	}
	for(i=0;i<5;i++)
	{
	  stringa4[i]=mtr[3][i];
	}

	for(i=0;i<5;i++)
	{
		printf("%c", stringa4[i]);
	}
}
