#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;

int exists[MAXN];
int N;

int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		int t;
		cin>>t;
		exists[t + 100000] = 1;
	}
	int cnt = 0;
	for(int i=0; i<=200000; i++)
	{
		if(i == 100000)continue;
		cnt+=exists[i];
	}
	cout<<cnt<<endl;
	return 0;
}