#include <stdio.h>
int main()
{
	int a=1;
	int n=1;
	while((a<<=1))
	{
		n+=1;
	}
	printf("Megoldas:%d%s",n,"\n");
}

Olyan programot kellet írnunk amely megadja hogy hány biten tároljuk az adott egész számot.Ezt a bitek shiftelésével oldotuk meg egy while ciklusban ami addig fut mig el nem éri az egyest.A ciklus minden egyes periodusában növeljük az n-t ami a végén a bitek számat fogja megadni.  
