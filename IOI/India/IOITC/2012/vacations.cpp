#include <bits/stdc++.h>
using namespace std;
/*IMPORTANT NOTE: array can be from 0.......N-1 ,
SQRT=(int)(sqrt(N));
BLOCKS=(N-1)/SQRT; 0,1,......BLOCKS..
BLOCK_SIZE=SQRT;
*/
struct element{
	int L;
	int R;
	int ind;
};
int BLOCK;
int A[30005],N,Q;
element X[200005];
int cnt[1000005],answer;
int ans[200005];
inline bool comp(element a, element b)
{
	if((a.L/BLOCK)!=(b.L/BLOCK))
	return (a.L/BLOCK)<(b.L/BLOCK);
	return a.R<b.R;
}
inline void add(int pos)
{
	cnt[A[pos]]++;
	if(cnt[A[pos]]==1)answer++;
}
inline void remove(int pos)
{
	cnt[A[pos]]--;
	if(cnt[A[pos]]==0)answer--;
}
int main()
{
	scanf("%d",&N);
	BLOCK=int(floor(sqrt(N)));
	for(int i=1; i<=N; i++)scanf("%d ",&A[i]);
	scanf("%d",&Q);
	for(int i=0; i<Q; i++)
	{
		scanf("%d %d",&X[i].L,&X[i].R);
		X[i].ind=i;
	}
	sort(X,X+Q,comp);
	int current_L=1; int current_R=0; answer=0;
	for(int i=0; i<Q; i++)
	{
		while(current_L>X[i].L)
		{
			add(current_L-1);
			current_L--;
		}
		while(current_R<X[i].R)
		{
			add(current_R+1);
			current_R++;
		}
		while(current_L<X[i].L)
		{
			remove(current_L);
			current_L++;
		}
		while(current_R>X[i].R)
		{
			remove(current_R);
			current_R--;
		}
		ans[X[i].ind]=answer;
	}
	for(int i=0; i<Q; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
