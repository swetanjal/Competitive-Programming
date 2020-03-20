#include "bits/stdc++.h"
using namespace std;

const int MAXN = 55;

int N;
int P[MAXN];

int main()
{
	ifstream cin("interception.txt");
	ofstream cout("Interception.out");
	int T;
	cin>>T;
	for(int cases = 1; cases <= T; cases++)
	{
		cin>>N;
		for(int i = 0; i <= N; i++)
		{
			cin>>P[i];
		}
		if((N%2) == 0)
		{
			cout<<"Case #"<<cases<<": "<<"0"<<endl;
		}
		else{
			cout<<"Case #"<<cases<<": "<<"1"<<endl;
			cout<<"0.0"<<endl;
		}
	}
	return 0;
}