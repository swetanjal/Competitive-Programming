#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
int N,K; 
map < vector <int> , long long > memo;
long long rec(vector <int> S)
{
	if(S.empty())return 1;
	if(S.size()>K)return 0;
	sort(S.begin(),S.end());
	if(memo.find(S)!=memo.end())return memo[S];
	int L=S.size();
	memo[S]=0;
	for(int i=0; i<L; i++)
	{
		for(int j=1; j<=S[i]; j++)//removing the jth student of the ith group.
		{
			int left_group=j-1;
			int right_group=S[i]-j;
			vector <int> X;
			X=S;
			if(left_group!=0 && right_group!=0)
			{
				X[i]=left_group;
				X.push_back(right_group);
			}
			else if(left_group!=0)
			{
				X[i]=left_group;
			}
			else if(right_group!=0)
			{
				X[i]=right_group;
			}
			else
			{
				X.erase(X.begin()+i);
			}
			memo[S]+=rec(X);
			memo[S]=memo[S]%MOD;
		}
	}
	return memo[S];
}
int main()
{
	scanf("%d %d", &N, &K);
	vector <int> lol;
	lol.push_back(N-1);
	long long ans=(N*rec(lol))%MOD;
	printf("%lld\n",ans);
	return 0;
}
