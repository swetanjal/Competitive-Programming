#include "bits/stdc++.h"
using namespace std;
const int MAXN = 15;
int N;
long long A[MAXN];
long long cum = 0;
int ans = -1;
vector <int> ANS;

void rec(int ind, vector <int> X)
{
	if(ind == N)
	{
		if(ans != -1 || X.size() == N || X.size() == 0)
			return;
		int L = X.size();
		long long S = 0;
		for(int i=0; i<L; i++)
			S += A[X[i]];
		if(S != (cum - S))
		{
			ans = L;
			for(int i=0; i<L; i++)
				ANS.push_back(X[i]);
		}
		return;
	}
	rec(ind + 1, X);
	vector <int> tmp;
	int L = X.size();
	for(int i=0; i<L; i++)
		tmp.push_back(X[i]);
	tmp.push_back(ind);
	rec(ind + 1, tmp);
}

int main()
{
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>A[i];
		cum += A[i];
	}
	vector <int> y;
	rec(0, y);
	if(ans == -1)
		cout<<ans<<endl;
	else
	{
		cout<<ans<<endl;
		for(int i=0; i<ans; i++)
			cout<<(ANS[i]+1)<<" ";
		cout<<endl;
	}
	return 0;
}