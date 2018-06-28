#include "bits/stdc++.h"
using namespace std;
const int MAXN = 4e5 + 5;
int N,K;
int freq[26];
int take[26];
char S[MAXN];
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)
	{
		cin>>S[i];
		freq[S[i] - 'a']++;
	}
	int cnt = 0;
	while(K > 0)
	{
		if(freq[cnt] < K)
		{
			take[cnt] = freq[cnt];
			K -= freq[cnt];
			cnt++;
		}
		else
		{
			take[cnt] = K;
			K = 0;

		}
	}
	for(int i=0; i<N; i++)
	{
		if(take[S[i]-'a'] > 0)
		{
			take[S[i]-'a']--;
			S[i]=' ';	
		}
	}
	for(int i=0; i<N; i++)
		if(S[i]!=' ')cout<<S[i];
	cout<<endl;
	return 0;
}