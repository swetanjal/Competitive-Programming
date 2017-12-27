#include <bits/stdc++.h>
using namespace std;
int N ; long long K;
long long A[100005];
bool chk(long long X)
{
	long long curr=0;
	for(int i=0; i<N; i++)
	{
		if(A[i]<X)return false;
		long long tm=A[i]-curr;
		curr=curr+max(tm,X);
		if(curr>K)return false;
	}
	return true;
}
long long search()
{
	long long pos=-1; long long l=0; long long u=1000000000; long long m;
	while(u>=l)
	{
		m=(u+l)/2;
		if(chk(m)){
			l=m+1;
			pos=m;
		}
		else
		{
			u=m-1;
		}
	}
	if(pos==-1)return 0;
	return pos;
}
int main()
{
	ifstream cin("fence.in");
	ofstream cout("fence.out");
	cin>>N>>K;
	for(int i=0; i<N; i++)cin>>A[i];
	sort(A,A+N);
	cout<<search()<<endl;
	return 0;
}
