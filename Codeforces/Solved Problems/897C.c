//What are you doing at the end of the world? Are you busy? Will you save us?
//What are you doing while sending "fi - 1"? Are you busy? Will you send "fi - 1"?
/*

What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? 
Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?

*/
#include <stdio.h>
long long dp[100005];
char X[]="What are you doing at the end of the world? Are you busy? Will you save us?";
char tmp1[]="What are you doing while sending \"";
char tmp2[]="\"? Are you busy? Will you send \"";
char tmp3[]="\"?";
char rec(int idx, long long f)
{
	if(idx==0 && f>75)return '.';
	if(idx==0)
		return X[f-1];
	if(f<=34)
		return tmp1[f-1];
	if(dp[idx-1]==-1 || (f>=35 && f<=(34+dp[idx-1])))
		return rec(idx-1,f-34);
	if((34+dp[idx-1]+1)<=f && f<=(34+dp[idx-1]+32))
		return tmp2[f-(34+dp[idx-1]+1)];
	if(f>=(67+(2*dp[idx-1])) && (f<=(68+(2*dp[idx-1]))))
		return tmp3[f-(67+(2*dp[idx-1]))];
	return rec(idx-1,f-(34+dp[idx-1]+32));
}
int main()
{
	dp[0]=75;
	//printf("%c\n", tmp3[0]);
	int i;
	for(i=1; i<56; i++)dp[i]=(2*dp[i-1])+68;
	for(i=56; i<=100000; i++)dp[i]=-1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		long long K;
		scanf("%d %lld",&N,&K);
		char zzz=rec(N,K);
		printf("%c", zzz);
	}
	printf("\n");
	return 0;
}