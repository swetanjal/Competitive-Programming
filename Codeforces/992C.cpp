#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
long long X, K;

long long fastmod(long long a, long long b)
{
	if(b == 0)return 1;
	if(b == 1)return a;
	long long tmp = (fastmod(a, b/2))%MOD;
	tmp = (tmp*tmp)%MOD;
	if((b%2)!=0)return (tmp*a)%MOD;
	return tmp;
}

int main()
{
	cin>>X>>K;
	if(X == 0){
		cout<<"0\n";
		return 0;
	}
	long long two_power_k = fastmod(2, K);
	X = X%MOD;
	long long aaa = ((((two_power_k*two_power_k)%MOD)*X)%MOD) - ((((two_power_k*(two_power_k-1+MOD))%MOD)*fastmod(2, MOD - 2))%MOD);
	if(aaa < 0 )
		aaa += MOD;
	aaa*=2;
	aaa = aaa%MOD;
	aaa = (aaa * fastmod(two_power_k, MOD - 2))%MOD;
	cout<<aaa<<endl;
	return 0;
}