#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e2 + 5;
int A[MAXN];
int N;
int main()
{
	cin>>N;
	int ret = 0;
	for(int i=1; i<=N; i++)
	{
		int tmp;
		cin>>tmp;
		A[tmp]++;
		ret = max(ret, A[tmp]);
	}
	cout<<ret<<endl;
	return 0;
}