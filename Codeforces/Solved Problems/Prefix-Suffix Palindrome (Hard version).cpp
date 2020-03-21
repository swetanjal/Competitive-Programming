// Codeforces Global Round 7
// 1326 D1, D2
#include "bits/stdc++.h"
using namespace std;
const long long MOD1 = 1e9 + 9;
const long long MOD2 = 1e9 + 7;
const long long p = 31;
const int MAXN = 1e6 + 5;
long long P1[MAXN];
long long P2[MAXN];
long long hash1, hash2, hash3, hash4;
int T, N;
string S;
int main(){
    P1[0] = 1;
    P2[0] = 1;
    for(int i = 1; i < MAXN; ++i) P1[i] = (P1[i - 1] * p) % MOD1;
    for(int i = 1; i < MAXN; ++i) P2[i] = (P2[i - 1] * p) % MOD2;
    cin >> T;
    while(T--){
        cin >> S;
        N = S.size();
        int l = 0; int r = N - 1;
        while(l <= r){
            if(l == r){
                break;
            }
            if(S[l] == S[r]){
                l++;
                r--;
            }
            else
                break;
        }
        if(l >= r){
            cout << S << endl;
            continue;
        }
        hash1 = ((S[l] - 'a' + 1) * P1[0]) % MOD1;
        hash2 = ((S[l] - 'a' + 1) * P1[0]) % MOD1;
        hash3 = ((S[l] - 'a' + 1) * P2[0]) % MOD2;
        hash4 = ((S[l] - 'a' + 1) * P2[0]) % MOD2;
        int ans1 = l;
        for(int i = l + 1; i <= r; ++i){
            hash1 = (hash1 + ((S[i] - 'a' + 1) * P1[i - l]) % MOD1) % MOD1;
            hash2 = ((hash2 * p) % MOD1 + ((S[i] - 'a' + 1) * P1[0]) % MOD1) % MOD1;

            hash3 = (hash3 + ((S[i] - 'a' + 1) * P2[i - l]) % MOD2) % MOD2;
            hash4 = ((hash4 * p) % MOD2 + ((S[i] - 'a' + 1) * P2[0]) % MOD2) % MOD2;
            if(hash1 == hash2 && hash3 == hash4)
                ans1 = i;
        }
        hash1 = ((S[r] - 'a' + 1) * P1[0]) % MOD1;
        hash2 = ((S[r] - 'a' + 1) * P1[0]) % MOD1;
        hash3 = ((S[r] - 'a' + 1) * P2[0]) % MOD2;
        hash4 = ((S[r] - 'a' + 1) * P2[0]) % MOD2;
        int c = 1;
        int ans2 = r;
        for(int i = r - 1; i >= l; --i){
            hash1 = (hash1 + ((S[i] - 'a' + 1) * P1[c]) % MOD1) % MOD1;
            hash2 = ((hash2 * p) % MOD1 + ((S[i] - 'a' + 1) * P1[0]) % MOD1) % MOD1;

            hash3 = (hash3 + ((S[i] - 'a' + 1) * P2[c]) % MOD2) % MOD2;
            hash4 = ((hash4 * p) % MOD2 + ((S[i] - 'a' + 1) * P2[0]) % MOD2) % MOD2;
            if(hash1 == hash2 && hash3 == hash4)
                ans2 = i;
            c++;
        }
        if((ans1 - l + 1) > (r - ans2 + 1)){
            for(int i = 0; i <= ans1; ++i)
                cout << S[i];
            for(int i = r + 1; i < N; ++i)
                cout << S[i];
            cout << endl;
        }
        else{
            for(int i = 0; i < l; ++i)
                cout << S[i];
            for(int i = ans2; i < N; ++i)
                cout << S[i];
            cout << endl;
        }
    }
    return 0;
}