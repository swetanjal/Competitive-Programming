#include <bits/stdc++.h>
using namespace std;
int N,K,A[1005];
int search(int S)
{
	int l=0; int u=N-1; int m; int pos=-1;
	while(u>=l)
	{
		m=(u+l)/2;
		if(A[m]<=S)
		{
			pos=m;
			l=m+1;
		}
		else
		{
			u=m-1;
		}
	}
	return pos;
}
int main()
{
	ifstream cin("diamond.in"); ofstream cout("diamond.out");
	cin>>N>>K;
	for(int i=0; i<N; i++)cin>>A[i];
	sort(A,A+N);
	int ret=0;
	for(int i=0; i<N; i++)
	{
		int lol=search(A[i]+K);
		if(lol!=-1)
		{
			ret=max(ret,lol-i+1);
		}
	}
	cout<<ret<<endl;
	return 0;
}
