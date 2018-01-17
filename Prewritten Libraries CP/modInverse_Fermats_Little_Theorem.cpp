#include "bits/stdc++.h"
using namespace std;
long long modExp(long long a, long long b, long long p)
{
	if(b==0){
		return 1;
	}
	if(b==1)return a;
	long long ttt=modExp(a,b/2,p);
	ttt=(ttt*ttt)%p;
	if((b%2)==0)return ttt;
	return (ttt*a)%p;
}
long long modInv(long long aaa, long long bbb)
{
	return modExp(aaa,bbb-2,bbb);
}
int main()
{
	long long A,B;
	cin>>A>>B;
	cout<<modInv(A,B)<<endl;
	return 0;
}