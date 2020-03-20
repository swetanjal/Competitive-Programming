#include <stdio.h>
int P,X,Y;
int chk(int S)
{
	int i=S/50;
	int cnt;
	for(cnt=1; cnt<=25; cnt++)
	{
		i=((i*96)+42)%475;
		if((26+i)==P)return 1;
	}
	return 0;
}
int main()
{
	scanf("%d %d %d", &P, &X, &Y);
	int i; int ANS=0;
	int copy=X;
	while(copy>=Y)
	{
		if(chk(copy))
		{
			printf("0\n");
			return 0;
		}
		copy-=50;
	}
	for(i=0; i<=500; i++)
	{
		if(chk(X+(50*i)))
		{
			ANS=(i/2)+(i%2);
			break;
		}
	}
	printf("%d\n", ANS);
	return 0;
}