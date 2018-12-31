#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
const long long MOD = 998244353;
long long N;
long long DP[MAXN];
// Mod Inverse Code
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
/*****************************************/
int main()
{
    cin >> N;
    DP[0] = 1;
    for(long long int i = 1; i < MAXN; ++i)
        DP[i] = (DP[i - 1] * i) % MOD;
    long long res = DP[N];
    for(long long int i = 2; i < N; ++i){
        res = (res +  ((((DP[N] * (DP[i] - 1)) % MOD) * modInv(DP[i], MOD)) % MOD)) % MOD;
    }
    cout << res << endl;
    return 0;
}