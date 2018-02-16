#include "bits/stdc++.h"
using namespace std;
const long long MOD=1e9+7;
const int MAXK=1e3+5;
int DP[MAXK];
long long freq[MAXK];
long long PAS[MAXK][MAXK];
int rec(int n)
{
	if(DP[n]!=-1)return DP[n];
	if(n==1)return 0;
	int cnt=0;
	while(n>0)
	{
		cnt=cnt+(n%2);
		n=n/2;
	}
	return 1+rec(cnt);
}
int main()
{
	string S; int K;
	cin>>S;
	cin>>K;
	if(K==0){
		cout<<"1\n";
		return 0;
	}
	for(int i=0; i<MAXK; i++)DP[i]=-1;
	int L=S.size();
	for(int i=0; i<MAXK; i++)PAS[i][0]=1;
	for(int i=1; i<MAXK; i++)
	{
		for(int j=1; j<=i; j++)
		{
			PAS[i][j]=(PAS[i-1][j]+PAS[i-1][j-1])%MOD;
		}
	}
	int cum=0;
	for(int i=0; i<L; i++)
	{
		if(S[i]=='0')continue;
		for(int j=1; j<=1000; j++)
		{
			int ccc=j-cum;
			if(ccc<0)continue;
			int nnn=L-i-1;
			if(nnn>=ccc){
				freq[j]=(freq[j]+PAS[nnn][ccc])%MOD;
			}
		}
		cum=cum+(S[i]-48);
	}
	freq[cum]++;
	freq[1]--;
	long long ANS=0;
	for(int i=1; i<=1000; i++){
		//cout<<rec(i)<<endl;
		if(rec(i)==(K-1))
			ANS=(ANS+freq[i])%MOD;
	}
	cout<<ANS<<endl;
	return 0;
}