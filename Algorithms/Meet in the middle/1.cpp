/*
Problem: https://www.codechef.com/MAY17/problems/CHEFCODE/
*/
#include <bits/stdc++.h>
using namespace std;
int N;
double contents[10000005]; int cnt;
double K,A[35];
map <double , double > M1;
map <double , double > M2;
void rec2(int ind, double prod, int flag)
{
	if(ind==N)
	{
		if(flag)
		{
			if(M2.find(prod)!=M2.end())M2[prod]++;
			else M2[prod]=1;
		}
		return;
	}
	if(prod>K)return;
	if(A[ind]<=K)
	rec2(ind+1,prod*A[ind],1);
	rec2(ind+1,prod,flag);
}
void rec1(int ind, double prod, int flag)
{
	if(ind==(N/2))
	{
		if(flag)
		{
			if(M1.find(prod)!=M1.end())M1[prod]++;
			else M1[prod]=1;
		}
		return;
	}
	if(prod>K)return;
	if(A[ind]<=K)
	rec1(ind+1,prod*A[ind],1);
	rec1(ind+1,prod,flag);
}
double search(double val)
{
	int l=0; int u=cnt-1; double ret=-1;
	while(u>=l)
	{
		int mid=(u+l)/2;
		if(contents[mid]>val)
		{
			u=mid-1;
		}
		else
		{
			ret=contents[mid];
			l=mid+1;
		}
	}
	return ret;
}
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)cin>>A[i];
	rec1(0,1,0);
	rec2((N/2),1,0);
	map <double , double> :: iterator it;
	double curr=0; double ans=0;
	for(it=M2.begin(); it!=M2.end(); ++it)
	{
		contents[cnt++]=it->first;
		if((it->first)<=K)ans+=M2[it->first];
		curr+=M2[it->first];
		M2[it->first]=curr;
	}
	sort(contents,contents+cnt);
	for(it=M1.begin(); it!=M1.end(); ++it)
	{
		if((it->first)<=K)ans+=M1[it->first];
		long long ty=search((long long)((K*1.0)/it->first));
		if(ty!=-1)
		ans+=(M1[it->first]*M2[ty]);
	}
	cout<<(long long)ans<<endl;
	return 0;
} 
