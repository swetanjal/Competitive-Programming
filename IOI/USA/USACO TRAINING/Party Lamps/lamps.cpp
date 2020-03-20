/*
ID: swetanj2
LANG: C++
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;
struct element{
	int arr[200];
	double sum;
};
int N;
int A[200];
int hash[200];
element ans[1000];
int cnt=0;
int C,lmb;
map <double, short> hah;
void rec(int ind, int temp[])
{
	if(ind==4)
	{
		for(int i=0; i<200; i++)A[i]=1;
		int size=0;
		if(temp[0]==1)
		{
			size++;
			for(int i=1; i<=N; i++)A[i]=!A[i];
		}
		if(temp[1]==1)
		{
			size++;
			for(int i=2; i<=N; i+=2)A[i]=!A[i];
		}
		if(temp[2]==1)
		{
			size++;
			for(int i=1; i<=N; i+=2)A[i]=!A[i];
		}
		if(temp[3]==1)
		{
			size++;
			for(int i=1; i<=N; i+=3)A[i]=!A[i];
		}
		if(size>C)return;
		//lets check
		for(int i=1; i<=N; i++)
		{
			if(hash[i]==A[i] || hash[i]==-1)continue;
			return ;
		}
		if((C==2)&& (size==1) && (temp[3]==1))return;
		
			ans[cnt].sum=0.0;
			for(int i=1; i<=N; i++){
				ans[cnt].arr[i]=A[i];
				ans[cnt].sum+=(A[i]*pow(2,N-i));
			}
		    if(hah.find(ans[cnt].sum)==hah.end())
			{
				hah[ans[cnt].sum]=1;
				cnt++;
			}
		return;
	}
	int curr[4];
	for(int i=0; i<ind; i++)curr[i]=temp[i];
	curr[ind]=0;
	rec(ind+1,curr);
	for(int i=0; i<ind; i++)curr[i]=temp[i];
	curr[ind]=1;
	rec(ind+1,curr);
}
bool compare(element a, element b)
{
	return a.sum<b.sum;
}
int main()
{
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");
	cin>>N>>C;
	cin>>lmb;
	for(int i=1; i<=N; i++)hash[i]=-1;
	while(lmb!=-1)
	{
		hash[lmb]=1;
		cin>>lmb;
	}
	cin>>lmb;
	while(lmb!=-1)
	{
		hash[lmb]=0;
		cin>>lmb;
	}
	int tmp[4];
	tmp[0]=0; tmp[1]=0; tmp[2]=0; tmp[3]=0;
	rec(0,tmp);
	if(cnt==0)cout<<"IMPOSSIBLE"<<endl;
	sort(ans,ans+cnt,compare);
	for(int j=0; j<cnt; j++)
	{
		for(int i=1; i<=N; i++)
		cout<<ans[j].arr[i];
		cout<<endl;
	}
	return 0;
}
