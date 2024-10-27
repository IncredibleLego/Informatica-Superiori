#include <stdio.h>

int funzione1(int giorno,int mese,int anno);
int funzione2(int giorno,int mese,int anno);

int main(){
	int giorno1, mese1, anno1, giorno2, mese2, anno2, data1, data2, giornimancanti;
	do{
		printf("Inserisci il primo giorno: ");
		scanf("%d", &giorno1);
	}while((giorno1<0)||(giorno1>30));
	do{
		printf("Inserisci il primo mese: ");
		scanf("%d", &mese1);
	}while((mese1<0)||(mese1>12));
	do{
		printf("Inserisci il primo anno: ");
		scanf("%d", &anno1);
	}while((anno1<0)||(anno1>9999));
	funzione1(giorno1,(mese1-1)*30,anno1*360);
	do{
		do{
		   printf("Inserisci il secondo giorno: ");
		   scanf("%d", &giorno2);
	    }while((giorno2<0)||(giorno2>30));
	    do{
		   printf("Inserisci il secondo mese: ");
		   scanf("%d", &mese2);
		}while((mese2<0)||(mese2>12));
		do{
			printf("Inserisci il secondo anno: ");
			scanf("%d", &anno2);
		}while((anno2<0)||(anno2>9999));
	    funzione2(giorno2,(mese2-1)*30,anno2*360);
	}while(data2<data1);
	giornimancanti=funzione2-funzione1;
	printf("%d", giornimancanti);
	while(giornimancanti>0)
	{
		giorno1=giorno1+1;
		if(giorno1==31){
			giorno1=1;
			mese1=mese1+1;
		}
		if(mese1==13){
			mese1=1;
			anno1=anno1+1;
		}
		giornimancanti=giornimancanti-1;
		printf("\n%d, %d, %d", giorno1, mese1, anno1);
	}
	
}
int funzione1(int giorno,int mese,int anno)
	{
		int data1=giorno+mese+anno;
		return data1;
	}
int funzione2(int giorno,int mese,int anno)
	{
		int data2=giorno+mese+anno;
		return data2;
	}
