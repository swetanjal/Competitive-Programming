/*
The problem essentially reduces to given an array B of size N compute how many numbers are there in a given range between lth index and the rth index.
This can be solved in O((log N)^2) using merge sort tree.
Refer: https://www.commonlounge.com/discussion/d871499b49e443259cfbea9b16f9b958
Problem: https://www.codechef.com/problems/PRMQ/
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> primes; int sz;
int l,r,x,y;
int lower_limit;
int B[100005];
int prime[1000005];
int idx[1000005];
int A[100005],N,Q;
int dp[100005][205];
vector <int> tree[500005];
inline void build(int node, int L, int R)
{
	if(L==R)
	{
		tree[node].push_back(B[L]);
		return;
	}
	int mid = (L+R)/2;
	build((2*node)+1,L,mid);
	build((2*node)+2,mid+1,R);
	int left_child = 0; int right_child = 0;
	int left_lim = tree[(2*node)+1].size(); int right_lim = tree[(2*node)+2].size();
	while(!(left_child==left_lim && right_child==right_lim))
	{
		if(left_child==left_lim)
		{
			tree[node].push_back(tree[(2*node)+2][right_child++]);
		}
		else if(right_child==right_lim)
		{
			tree[node].push_back(tree[(2*node)+1][left_child++]);
		}
		else
		{
			if(tree[(2*node)+1][left_child] < tree[(2*node)+2][right_child] )
			tree[node].push_back(tree[(2*node)+1][left_child++]);
			else tree[node].push_back(tree[(2*node)+2][right_child++]);
		}
	}
}
inline int query(int node, int low, int high, int qlow, int qhigh)
{
	if(qlow>high || low>qhigh)
	return 0;
	else if(qlow<=low && high<=qhigh)
	{
		/*Binary Search*/
		int lo = 0; int hi = tree[node].size()-1;
		int m; int pos =-1;
		while(hi>=lo)
		{
			m=(hi+lo)/2;
			if(tree[node][m]>=x && tree[node][m]<=y)
			{
				pos= m;
				hi = m-1;
			}
			else if(tree[node][m]<x)lo = m+1;
			else hi =m-1;
		}
		if(pos==-1)return 0;
		lo=0; hi = tree[node].size()-1;
		int pos1 = -1;
		while(hi>=lo)
		{
			m = (hi+lo)/2;
			if(tree[node][m]>=x && tree[node][m]<=y)
			{
				pos1 = m;
				lo = m+1;
			}
			else if(tree[node][m]<x)lo = m+1;
			else hi = m-1;
		}
		return (pos1-pos+1);
	}
	int mid=(high+low)/2;
	return query((2*node)+1, low,mid,qlow,qhigh)+query((2*node)+2, mid+1, high, qlow, qhigh);
}
inline void calc(int X, int ind){
	if(X==1)return;
	if(prime[X]>1000){
		B[ind-1]=prime[X];
	}
	else dp[ind][idx[prime[X]]]++;
	calc(X/prime[X],ind);
}
inline int lower()
{
	int low = 0; int high = sz-1; int mid; int pos = -1;
	while(high>=low){
		mid = (high+low)/2;
		if(primes[mid]>=x && primes[mid]<=y){
			pos = mid;
			high = mid-1;
		}
		else if(primes[mid]<x){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return pos;
}
inline int upper()
{
	int low = lower_limit-1; int high = sz-1; int mid; int pos = -1;
	while(high>=low){
		mid = (high+low)/2;
		if(primes[mid]>=x && primes[mid]<=y){
			pos = mid;
			low = mid+1;
		}
		else if(primes[mid]<x){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return pos;
}
int main()
{
	for(int i=1; i<=1000000; i++)prime[i]=i;
	for(int i=2; i<=1000000; i++)
	{
		if(prime[i]==i){
			for(int j=i+i; j<=1000000; j+=i){
				if(prime[j]==j)prime[j]=i;
			}
		}
	}
	for(int i=2; i<=1000; i++)if(prime[i]==i)primes.push_back(i);
	sz=primes.size();
	for(int i=0; i<sz; i++)idx[primes[i]]=i+1;
	scanf("%d",&N);
	for(int i=0; i<=N; i++)B[i]=100000000;
	for(int i=1; i<=N; i++)scanf("%d",&A[i]);
	for(int i=1; i<=N; i++)calc(A[i],i);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=sz; j++){
			dp[i][j]=dp[i][j]+dp[i-1][j];
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=sz; j++){
			dp[i][j]=dp[i][j]+dp[i][j-1];
		}
	}
	build(0,0,N-1);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d %d %d %d", &l , &r, &x, &y);
		lower_limit=lower()+1;
		int answer=0;
		if(lower_limit!=0)
		{
			int upper_limit=upper()+1;
			answer = (dp[r][upper_limit]-dp[l-1][upper_limit])-(dp[r][lower_limit-1]-dp[l-1][lower_limit-1]);
		}
		l = l-1; r= r-1;
		/*B is 0 indexed*/
		answer = answer + query(0,0,N-1,l,r);
		printf("%d\n",answer);
	}
	return 0;
}  
