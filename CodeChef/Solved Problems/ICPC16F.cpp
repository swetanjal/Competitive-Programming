#include <bits/stdc++.h>
using namespace std;
struct element{
	int node;
	int value;
};
bool comp(element a, element b)
{
	return a.value<b.value;
}
void solve()
{
	int N,M,d,D;
	int i,j;
	scanf("%d%d%d%d",&N,&M,&d,&D);
	if(d>N)
	{
		printf("%d\n", -1);
		return;
	}
	if(!((N*d)<=M && M<=(N*D)))
	{
		printf("%d\n", -1);
		return;
	}
	element A[N];
	for(i=0; i<N; i++)
	{
		A[i].node=i;
		A[i].value=0;
	}
	for(i=0; i<N; i++)
	{
		int edges=min(D,M-(d*(N-i-1)));
		int cnt=0;
		sort(A,A+N,comp);
		for(j=0; j<N; j++)
		{
			A[j].value++;
			printf("%d %d\n",(i+1),(A[j].node+1));
			cnt++;
			if(cnt==edges)break;
		}
		M-=edges;
	}
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}