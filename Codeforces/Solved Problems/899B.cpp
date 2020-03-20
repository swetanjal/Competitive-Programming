#include <bits/stdc++.h>
using namespace std;
int main()
{
	int C1[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int C2[]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int C3[]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int C4[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
	int N;
	cin>>N;
	int A[N];
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<12; i++)
	{
		int c=0;
		for(int j=i; ; j++)
		{
			if(A[c]==C1[j])
				c++;
			else
				break;
			if(c==N)break;
		}
		if(c==N){
			cout<<"YES\n";
			return 0;
		}
	}
	for(int i=0; i<12; i++)
	{
		int c=0;
		for(int j=i; ; j++)
		{
			if(A[c]==C2[j])
				c++;
			else
				break;
			if(c==N)break;
		}
		if(c==N){
			cout<<"YES\n";
			return 0;
		}
	}
	for(int i=0; i<12; i++)
	{
		int c=0;
		for(int j=i; ; j++)
		{
			if(A[c]==C3[j])
				c++;
			else
				break;
			if(c==N)break;
		}
		if(c==N){
			cout<<"YES\n";
			return 0;
		}
	}
	for(int i=0; i<12; i++)
	{
		int c=0;
		for(int j=i; ; j++)
		{
			if(A[c]==C4[j])
				c++;
			else
				break;
			if(c==N)break;
		}
		if(c==N){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}