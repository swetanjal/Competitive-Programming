#include "bits/stdc++.h"
using namespace std;

int N, K, T;

int A[256];

void upd(int st, int en)
{
	for(int i=st; i<=en; i++)
		A[i] = st;
}

int st(int X)
{
	for(int i=0; i<256; i++)
		if(A[i] == X)return i;
}

int main()
{
	cin>>N>>K;
	for(int i=0; i<256; i++)A[i] = -1;
	for(int i=0; i<N; i++){
		cin>>T;
		if(A[T]!=-1){
			cout<<A[T]<<" ";
			continue;
		}
		int end_idx = -1;
		//find the previous segment
		for(int j = T; j>=0; j--)
		{
			if(A[j]!=-1)
			{
				end_idx = j;
				break;
			}
		}
		if(end_idx == -1)
		{
			upd(max(0, T-K+1), T);
		}
		else
		{
			int st_idx = st(A[end_idx]);
			if((T-st_idx+1) <=K)
				upd(st_idx,T);
			else
				upd(max(T-K+1 , end_idx + 1), T);
		}
		cout<<A[T]<<" ";
	}
	cout<<endl;
}