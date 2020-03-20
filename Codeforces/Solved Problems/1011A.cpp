#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int N, K;
char A[MAXN];

int main()
{
	cin>>N>>K;
	for(int i = 0; i < N; i++)
		cin>>A[i];
	int cnt = 0; int last = -2;
	sort(A, A + N);
	int ret = 0;
	for(int i = 0; i < N; i++)
	{
		if((A[i] - 'a') - last >= 2)
		{
			last = A[i] - 'a';
			cnt++;
			ret = ret + (A[i] - 'a') + 1;
			if(cnt == K)
				break;
		}
	}
	if(cnt == K)
	cout<<ret<<endl;
	else
		cout<<"-1\n";
	return 0;
}