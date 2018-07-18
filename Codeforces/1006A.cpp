#include "bits/stdc++.h"
using namespace std;

int N;

int main()
{
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		long long tmp;
		cin>>tmp;
		if((tmp%2) == 0)
			cout<<(tmp - 1);
		else
			cout<<(tmp);
		cout<<" ";
	}
	cout<<endl;
	return 0;
}