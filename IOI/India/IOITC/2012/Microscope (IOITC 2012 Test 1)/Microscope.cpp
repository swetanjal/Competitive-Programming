#include <bits/stdc++.h>
using namespace std;
struct element{
	int x;
	int y;
}; 
int R,C,K,M,N;
element A[100005];
int main()
{
	cin>>M>>N>>R>>C>>K;
	for(int i=0; i<K; i++)cin>>A[i].x>>A[i].y;
	int lower_x=0; int lower_y=0;
	int upper_x=R-1; int upper_y=C-1;
	long long ret=0;
	for(int i=0; i<K; i++)
	{
		int tmp;
		if((A[i].x>=lower_x)&&(A[i].x<=upper_x))tmp=0;
		else
		if(A[i].x<lower_x)
		{
			tmp=(lower_x-A[i].x);
			lower_x=A[i].x;
			upper_x=upper_x-tmp;
			ret+=tmp;
		}
		else
		if(A[i].x>upper_x)
		{
			tmp=(A[i].x-upper_x);
			upper_x=A[i].x;
			lower_x=lower_x+tmp;
			ret+=tmp;
		}
		if((A[i].y>=lower_y)&&(A[i].y<=upper_y))tmp=0;
		else
		if(A[i].y<lower_y)
		{
			tmp=(lower_y-A[i].y);
			lower_y=A[i].y;
			upper_y=upper_y-tmp;
			ret+=tmp;
		}
		else
		if(A[i].y>upper_y)
		{
			tmp=(A[i].y-upper_y);
			upper_y=A[i].y;
			lower_y=lower_y+tmp;
			ret+=tmp;
		}
	}
	cout<<ret<<endl;
	return 0;
}
