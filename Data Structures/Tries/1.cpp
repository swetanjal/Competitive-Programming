/*
Problem: https://www.codechef.com/MAY17/problems/WSITES01/
*/
#include <bits/stdc++.h>
using namespace std;
int N; string S; char x;
int edges[200005][26];
int cnt_blocked[200005], cnt_unblocked[200005];
int blocked[200005],unblocked[200005];
vector <string> ans;
int cnt=0; int flag=0;
void dfs(int node)
{
	for(int i=0; i<26; i++)
	{
		if(edges[node][i]!=0)
		{
			dfs(edges[node][i]);
			cnt_blocked[node]+=cnt_blocked[edges[node][i]];
			cnt_unblocked[node]+=cnt_unblocked[edges[node][i]];
		}
	}
}
void insert()
{
	int node=0;
	int L=S.size();
	for(int i=0; i<L; i++)
	{
		int lol=S[i]-97;
		if(edges[node][lol]==0)
		{
			edges[node][lol]=(++cnt);
		}
		node=edges[node][lol];
	}
	if(x=='-')
	{
		cnt_blocked[node]+=1;
		blocked[node]+=1;
	}
	else
	{
		cnt_unblocked[node]+=1;
		unblocked[node]+=1;
	} 
}
void dfs1(int node, string pro)
{
	/*if(unblocked[node]>0)
	{
		flag=-1;
		return;
	}*/
	for(int i=0; i<26; i++)
	{
		if(edges[node][i])
		{
			if(cnt_blocked[edges[node][i]]!=0 && cnt_unblocked[edges[node][i]]!=0)
			dfs1(edges[node][i],pro+(char)(97+i));
			else if(cnt_unblocked[edges[node][i]]==0)
			{
				ans.push_back(pro+(char)(97+i));
			}
			else if(blocked[node]>0 && cnt_unblocked[edges[node][i]]!=0)
			{
				flag=-1;
				return;
			}
		}
	}
}
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cin>>x;
		cin>>S;
		insert();
	}
	dfs(0);
	dfs1(0,"");
	sort(ans.begin(),ans.end()); int K=ans.size();
	if(flag==-1)
	{
		cout<<flag<<endl;
		return 0;
	}
	cout<<K<<endl;
	for(int i=0; i<K; i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}  
