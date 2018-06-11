#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;

int T;
int N,M;

struct element{
	int l;
	int r;
};

element R[MAXN];

bool comp(element a, element b)
{
	if(a.l == b.l)
		return a.r>b.r;
	return a.l<b.l;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		int exists[N+1]={0};
		int A[N+1];
		for(int i=1; i<=N; i++)
			cin>>A[i];
		for(int i=0; i<M; i++)
		{
			cin>>R[i].l>>R[i].r;
		}
		sort(R, R+M, comp);
		int rig = R[0].r;
		int comp = 1;
		for(int i=R[0].l; i<=R[0].r; i++)
			exists[i] = comp;
		for(int i=1; i<M; i++)
		{
			if(R[i].l > rig)
			{
				++comp;
				for(int j=R[i].l; j<=R[i].r; j++)
					exists[j] = comp;
				rig = R[i].r;
			}
			if(R[i].r >= rig && R[i].l<=rig)
			{
				for(int j=rig; j<=R[i].r; j++)
					exists[j]  = comp;
				rig = R[i].r;
			}
		}
		int flag = 1;
		/*int cum[N+1] = {0};
		for(int i=1; i<=N; i++)
			cum[i] = cum[i-1] + exists[i];*/
		for(int i=1; i<=N; i++)
		{
			if(i == A[i])continue;
			if( exists[i] == exists[A[i]])
				continue;
			else
			{
				//cout<<"Wait!"<<" "<<i<<endl;
				flag = 0;

			}
		}
		if(flag)cout<<"Possible\n";
		else cout<<"Impossible\n";
	}
	return 0;
}