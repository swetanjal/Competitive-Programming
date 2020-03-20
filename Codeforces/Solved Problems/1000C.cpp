#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;

struct point{
	long long l;
	long long r;
};
int N;
point A[MAXN];

long long cnt[MAXN];

bool comp(point a, point b)
{
	if(a.l == b.l)
		return a.r < b.r;
	return a.l < b.l;
}
//
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>A[i].l>>A[i].r;
	if(N == 1)
	{
		cout<<(A[0].r - A[0].l + 1)<<endl;
		return 0;
	}
	sort(A, A + N, comp);
	multiset <long long> S;
	S.insert(A[0].r);
	long long unproc = A[0].l;
	for(int i = 1; i < N; i++)
	{
		while(!S.empty() && (*S.begin()) < A[i].l)
		{
			cnt[S.size()] += (*S.begin()) - unproc + 1;
			unproc = (*S.begin())+1;
			S.erase(*S.begin());
		}
		cnt[S.size()] += (A[i].l - unproc);
		S.insert(A[i].r);
		unproc = A[i].l;
	}
	while(!S.empty())
	{
		cnt[S.size()] += (*S.begin()) - unproc + 1;
		unproc = (*S.begin())+1;
		S.erase(*S.begin());
	}
	for(int i=1; i<=N; i++)cout<<cnt[i]<<" ";
		cout<<endl;
	return 0;
}