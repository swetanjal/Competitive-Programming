#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 1e6 + 5;
int N;
set <int> F[MAXN];
vector <int> A[MAXN];

class ModularInverse{
private:
    long long MOD;
    long long x;
    long long y;
    long long extended_gcd(long long a, long long b)
    {
        if(b==0){
            x=1;
            y=0;
            return a;
        }
        long long g = extended_gcd(b, a % b);
        long long x1 = x;
        long long y1 = y;
        x = y1;
        y = x1 - ((a / b) * y1);
        return g;
    }
public:
    ModularInverse(long long m){
        MOD = m;
    }
    long long solve(long long a)
    {
        long long hcf = extended_gcd(max(a, MOD), min(a, MOD));
        if(a > MOD){
		    while(x < 0)x += MOD;
		    return x;
	    }
        else {
		    while(y < 0)y += MOD;
		    return y;
	    }
    }
};


int main()
{
    int maxK = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int k;
        cin >> k;
        maxK = max(maxK, k);
        for(int j = 1; j <= k; ++j){
            int tmp;
            cin >> tmp;
            A[i].push_back(tmp);
            F[tmp].insert(i);
        }
    }
    ModularInverse obj(MOD);
    long long den = obj.solve((((N * 1LL * N)) % MOD));
    long long int cnt = 0;
    for(int i = 1; i <= N; ++i){
        int l = A[i].size();
        for(int j = 0; j < l; ++j){
            cnt = (cnt + ((obj.solve(l) * 1LL * F[A[i][j]].size()) % MOD) * den) % MOD;
            cnt = cnt % MOD;
        }
    }
    cout << cnt << endl;
    return 0;
}