/*
ID: swetanj2
LANG: C++
TASK: holstein
*/
#include <bits/stdc++.h>
using namespace std;
int X[100];
int A[100][100];
int N,M;
int no=INT_MAX;
int ans[100];
void rec(int ind, int curr, int arr[], int indices[])
{
	if(ind==M)
	{
		int flag=0;
		//for(int i=0; i<N; i++)cout<<arr[i]<<" ";
		for(int i=0; i<N; i++)
		{
			if(arr[i]>=X[i])continue;
			else{
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(curr<no)
			{
				for(int i=0; i<curr; i++)ans[i]=indices[i];
				no=curr;
			}
			else
			if(curr==no)
			{
				int sum1=0; int sum2=0;
				for(int i=0; i<curr; i++){
					sum1+=indices[i];
					sum2+=ans[i];
				}
				if(sum1<sum2)
				{
					for(int i=0; i<curr; i++)ans[i]=indices[i];
				}
			}
		}
		return;
	}
	rec(ind+1,curr,arr,indices);
	int r[N]; int q[25];
	for(int i=0; i<25; i++)q[i]=-1;
	for(int i=0; i<curr; i++)q[i]=indices[i];
	q[curr]=ind;
	for(int i=0; i<N; i++)
	r[i]=arr[i]+A[ind][i];
	indices[curr]=ind;
	rec(ind+1,curr+1,r,q);
}
int main()
{
	ifstream cin("holstein.in");
	ofstream cout("holstein.out");
	cin>>N;
	for(int i=0; i<N; i++)cin>>X[i];
	cin>>M;
	for(int i=0; i<M; i++)
	for(int j=0; j<N; j++)cin>>A[i][j];
	for(int i=0; i<25; i++)ans[i]=10000000;
	int l[N];
	for(int i=0; i<N; i++)l[i]=0;
	int m[25];
	for(int i=0; i<25; i++)m[i]=-1;
	rec(0,0,l,m);
	cout<<no<<" ";
	for(int i=0; i<no-1; i++)
	cout<<(ans[i]+1)<<" ";
	cout<<(ans[no-1]+1)<<endl;
	return 0;
}
