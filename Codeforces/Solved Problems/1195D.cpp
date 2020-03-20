#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 1e5 + 5;
int L;
long long int A[MAXN];
long long power[MAXN];
int freq[25];
int N;
    
/*long long int power(long long x, long long y)
{
    long long p = 1;
    for(long long int i = 1; i <= y; ++i)
        p = (p * x) % MOD;
    return p;
}*/
    
long long int get(long long s, int cnt)
{
    int side = 0;
    vector <int> v;
    long long int cpy = s;
    int c = 0;
    while(cpy > 0)
    {
        cpy /= 10;
        c++;
    }
    cpy = s;
    int l1 = 0;
    int l2 = 0;
    while(l1 < c && l2 < cnt){
        if(side == 0){
            v.push_back(cpy % 10);
            cpy /= 10;
            l1++;
        }
        else{
            v.push_back(0);
            l2++;
        }
        side = 1 - side;
    }
    while(l1 < c){
        v.push_back(cpy % 10);
        cpy /= 10;
        l1++;
    }
    while(l2 < cnt){
        v.push_back(0);
        l2++;
    }
    long long sum = 0;
    for(int i = 0; i < (c + cnt); ++i){
        sum = (sum + ((v[i] * power[i]) % MOD)) % MOD;
    }
    return sum;
}
    
long long int get2(long long s, int cnt)
{
    int side = 1;
    vector <int> v;
    long long int cpy = s;
    int c = 0;
    while(cpy > 0)
    {
        cpy /= 10;
        c++;
    }
    cpy = s;
    int l1 = 0;
    int l2 = 0;
    while(l1 < c && l2 < cnt){
        if(side == 0){
            v.push_back(cpy % 10);
            cpy /= 10;
            l1++;
        }
        else{
            v.push_back(0);
            l2++;
        }
        side = 1 - side;
    }
    while(l1 < c){
        v.push_back(cpy % 10);
        cpy /= 10;
        l1++;
    }
    while(l2 < cnt){
        v.push_back(0);
        l2++;
    }
    long long sum = 0;
    for(int i = 0; i < (c + cnt); ++i){
        sum = (sum + ((v[i] * power[i]) % MOD)) % MOD;
    }
    return sum;
}
    
int main()
{
    power[0] = 1;
    for(int i = 1; i <= 25; ++i){
        power[i] = (power[i - 1] * 10) % MOD;
    }
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        long long cpy = A[i];
        int c = 0;
        while(cpy > 0){
            cpy = cpy / 10;
            c++;
        }
        L = max(L, c);
        freq[c]++;
    }
    long long res = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 1; j <= L; ++j){
            long long tmp = (get(A[i], j) + get2(A[i], j)) % MOD;
            res = (res + ((freq[j] * 1LL * tmp) % MOD)) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}