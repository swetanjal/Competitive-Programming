#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,M;
	cin>>N>>M;
	int X[N],Y[N];
	for(int i=0; i<N; i++)
	{
		cin>>X[i]>>Y[i];
	}
	if(X[0]!=0){
		cout<<"NO\n";
		return 0;
	}
	int pt=Y[0];
	for(int i=1; i<N; i++)
	{
		if(X[i]>=X[i-1] && X[i]<=pt)
		{
			pt=max(pt,Y[i]);
		}
	}
	if(pt>=M)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}