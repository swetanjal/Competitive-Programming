#include "bits/stdc++.h"
using namespace std;

int N;
long long M;
vector <long long> T;
vector <long long> lit;
vector <long long> unlit;

int main()
{
	cin>>N>>M;
	T.push_back(0);
	for(int i=1; i<=N; i++)
	{
		long long tmp;
		cin>>tmp;
		T.push_back(tmp);
	}
	T.push_back(M);
	lit.push_back(0);
	unlit.push_back(0);
	int L = T.size();
	for(int i=1; i<L; i++)
	{
		if((i%2) != 0)
		{
			lit.push_back(lit[i - 1] + T[i] - T[i -1]);
			unlit.push_back(unlit[i-1]);
		}
		else
		{
			unlit.push_back(unlit[i - 1] + T[i] - T[i -1]);
			lit.push_back(lit[i-1]);	
		}
	}
	long long ret = lit[L - 1];
	
	for(int i = 1; i<L; i++)
	{
		if((T[i] - T[i -1]) == 1)continue;
		if((i % 2) != 0)
		{
			ret = max(ret, lit[i - 1] + (T[i] - 1) - T[i - 1] + (unlit[L - 1] - unlit[i]));
		}
		else
		{
			ret = max(ret, lit[i - 1] + T[i] - (T[i - 1] + 1) + (unlit[L - 1] - unlit[i]));	
		}
	}
	cout<<ret<<endl;
	return 0;
}