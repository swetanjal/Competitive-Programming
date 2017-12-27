/*
ID: swetanj2
LANG: C++
TASK: hamming
*/
#include <bits/stdc++.h>
using namespace std;
int N,B,D;
int A[256];
int ans[65];
int x;
bool hamming(int p, int s)
{
	int v=p^s;
	//cout<<v<<endl;
	int o=0;
	while(v>0)
	{
		int q=v/2;
		int dig=v%2;
		if(dig)o++;
		v=q;
	}
	if(o>=D)return true;
	return false;
}
bool tryadd(int s, int a[], int tot)
{
	int flag=0;
	for(int i=0; i<tot; i++)
	{
		if(hamming(a[i],s))continue;
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)return false;
	return true;
}
void chk(int a[])
{
	for(int i=0; i<N; i++)ans[i]=a[i];
}
int main()
{
	ifstream cin("hamming.in");
	ofstream cout("hamming.out");
	cin>>N>>B>>D;
	int fl=0;
	x=pow(2,B);
	for(int i=0; i<x; i++)A[i]=i;
	for(int i=0; i<N; i++)ans[i]=0;
	for(int i=0; i<x; i++)
	{
		int arr[N];
		arr[0]=i; int curr=1;
		for(int j=i+1; j<x; j++)
		{
			if(tryadd(j,arr,curr))
			{
				arr[curr++]=j;
			}
			if((curr==N)&&(fl==0))
			{
				chk(arr);
				fl=1;
				break;
			}
		}
		if(fl)break;
	}
	int lol=N/10;
	int bol=N%10;
	int curr=0;
	for(int i=1; i<=lol; i++)
	{
		for(int i=1; i<=9; i++)
		{
			cout<<ans[curr++]<<" ";
		}
		cout<<ans[curr++]<<endl;
	}
	for(int i=1; i<bol; i++){
		cout<<ans[curr++]<<" ";
	}
	if(bol!=0)cout<<ans[curr++]<<endl;
	return 0;
}
