/* I am a n00b at Math :P */
#include <stdio.h>
int main()
{
	char S[1000005];
	scanf("%s",S);
	int i=0;
	int rem=0;
	for(i=0; ; i++)
	{
		if(S[i]=='\0')break;
		int dig=S[i]-48;
		int num=(10*rem)+dig;
		rem=num%4;
	}
	
	int two[]={1,2,4,3};
	int three[]={1,3,4,2};
	int four[]={1,4,1,4};
	int sum=1+two[rem]+three[rem]+four[rem];
	sum%=5;
	printf("%d\n", sum);
	return 0;
}