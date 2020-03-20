#include <bits/stdc++.h>
using namespace std;
int T,N,K;
int D[100005];
int A[100005];
int S[100005];
int arr[100005];
int Z[100005];
void cal()
{
	int l=N+K;
	Z[0]=0;
	int L,R; L=0; R=0;
	for(int i=1; i<l; i++)
	{
		if(i>R)
		{
			L=i; R=i;
			while((R<l)&&(arr[R]==arr[R-L]))
			R++;
			Z[i]=R-L;
			R--;
		}
		else
		{
			int i1=i-L;
			if(Z[i1]<R-i+1)
			Z[i]=Z[i1];
			else
			{
				L=i;
				while((R<l)&&(arr[R]==arr[R-L]))
			    R++;
			    Z[i]=R-L;
			    R--;
			}
		}
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		for(int i=0; i<N; i++)cin>>A[i];
		for(int j=0; j<N-1; j++)D[j]=A[j+1]-A[j];
		for(int i=0; i<K; i++)cin>>S[i];
		for(int i=0; i<K; i++)arr[i]=S[i];
		arr[K]=-2;
		for(int i=0; i<N; i++)arr[K+i+1]=D[i];
		cal();
		int l=N+K;
		int cnt=0;
		for(int i=0; i<l; i++)if(Z[i]==K)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
