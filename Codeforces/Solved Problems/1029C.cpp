#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
struct element{
	int l;
	int r;
};
int N;
element A[MAXN];
element DP1[MAXN];
element DP2[MAXN];
bool comp(element a, element b)
{
	if(a.l != b.l)
		return a.l < b.l;
	return a.r < b.r;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i].l >> A[i].r;
	}
	DP1[0].l = A[0].l;
	DP1[0].r = A[0].r;
	DP2[N - 1].l = A[N - 1].l;
	DP2[N - 1].r = A[N - 1].r;
	for(int i = 1; i < N; i++)
	{
		DP1[i].l = max(DP1[i - 1].l, A[i].l);
		DP1[i].r = min(DP1[i - 1].r, A[i].r);
	}
	for(int i = N - 2; i >= 0; i--)
	{
		DP2[i].l = max(DP2[i + 1].l, A[i].l);
		DP2[i].r = min(DP2[i + 1].r, A[i].r);	
	}
	if(N == 1)
	{
		cout << "1\n";
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < N; i++)
	{
		if(i == 0)
		{
			ret = max(ret, DP2[1].r - DP2[1].l); 
		}
		else if(i == (N - 1))
		{
			ret = max(ret, DP1[N - 2].r - DP1[N - 2].l);
		}
		else
		{
			int left = max(DP1[i - 1].l, DP2[i + 1].l);
			int right = min(DP1[i - 1].r, DP2[i + 1].r);
			ret = max(ret, right - left);
		}
	}
	cout << ret << endl;
	return 0;
}