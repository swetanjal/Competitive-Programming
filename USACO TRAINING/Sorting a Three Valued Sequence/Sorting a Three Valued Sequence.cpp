/*
ID: swetanj2
LANG: C++
TASK: sort3
*/
#include <bits/stdc++.h>
using namespace std;
int A[1000];
int S[1000];
int N,flag,ans;
void swap(int i, int j)
{
	int t=A[i];
	A[i]=A[j];
	A[j]=t;
}
int main()
{
	ifstream cin("sort3.in");
	ofstream cout("sort3.out");
	cin>>N;
	ans=0;
	for(int i=0; i<N; i++){
		cin>>A[i];
		S[i]=A[i];
	}
	sort(S,S+N);
	//doing the best swaps possible i.e a single swap places both the elements in place.
	for(int i=0; i<N; i++)
	{
		if(S[i]==A[i])continue;
		flag=-1;
		for(int j=0; j<N; j++)
		{
			if((A[i]==S[j])&&(A[j]==S[i]))
			{
				flag=j;
				break;
			}
		}
		if(flag==-1)continue;
		swap(i,flag);
		ans++;
	}
	//putting the rest of the elements in place without using the best swaps.
	for(int i=0; i<N; i++)
	{
		if(S[i]==A[i])continue;
		flag=-1;
		for(int j=0; j<N; j++)
		{
			if(S[j]==A[j])continue;
			if(S[i]==A[j]){
				flag=j;
				break;
			}
		}
		if(flag!=-1)
		{
			swap(flag,i);
		    ans++;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
