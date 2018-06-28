#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;

int N, K;
struct element{
	int idx;
	long long power;
	long long cost;
};

bool cmp(element a, element b)
{
	return a.power < b.power;
}

element A[MAXN];
long long ans[MAXN];

int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)
	{
		cin>>A[i].power;
		A[i].idx = i;
	}
	for(int i=0; i<N; i++)
	{
		cin>>A[i].cost;
	}
	sort(A, A+N, cmp);
	multiset <long long> S;
	S.insert(0);
	multiset <long long> :: iterator it;
	for(int i=0; i<N; i++)
	{		
		int c = 0;
		long long ret = A[i].cost;
		set <long long> :: iterator e = S.end();
		--e;	
		for(it = e; ; --it)
		{
			if(K == 0)break;
			ret = ret + *it;
			++c;
			if(c == K)
				break;
			if(it == S.begin())
				break;
		}
		S.insert(A[i].cost);
		ans[A[i].idx] = ret;
	}
	for(int i=0; i<N; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}