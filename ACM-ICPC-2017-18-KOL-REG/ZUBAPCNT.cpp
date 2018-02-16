#include "bits/stdc++.h"
using namespace std;
const long long MOD=1e9+7;
const long long MAXM=1e5+5;
long long T26[MAXM];
long long T25[MAXM];
string S;
int N,M,T;
int main()
{
	T26[0]=1; T25[0]=1;
	for(int i=1; i<MAXM; i++)
	{
		T25[i]=(T25[i-1]*25)%MOD;
		T26[i]=(T26[i-1]*26)%MOD;
	}
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		cout<<"Case "<<i<<":\n";
		cin>>N>>M;
		while(M--)
		{
			cin>>S;
			int L=S.size();
			if(L>N){
				cout<<"0\n";
				continue;
			}
			long long prod=((N-L+1)*(T26[N-L]))%MOD;
			cout<<prod<<endl;
		}
	}
	return 0;
}