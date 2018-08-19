#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int net = 0;
	for(int i = 0; i < N; i++)
		cin>>A[i];
	for(int i = 0; i < N; i++)
	{
		int x;
		cin>>x;
		net = net + (x - A[i]);
	}
	if(net <= 0)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}