#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
long long B[MAXN];
long long G[MAXN];
int N, M;
map <long long, int> H;
int main()
{
    cin >> N >> M;   
    for(int i = 0; i < N; ++i){
        cin >> B[i];
        H[B[i]] = 1;
    }
    for(int i = 0; i < M; ++i)
        cin >> G[i];
    sort(B, B + N);
    sort(G, G + M);
    if(G[0] < B[N - 1]){
        cout << "-1\n";
        return 0;
    }
    long long res = 0;
    for(int i = 0; i < N; ++i)
        res = res + (B[i] * 1LL *M);
    int curr = N - 1;
    int cnt = 0;
    for(int i = M - 1; i >= 0; i--){
        if(H.find(G[i]) == H.end())
            res += (G[i] - B[curr]);
        cnt = cnt + 1;
        if(cnt == (M - 1)){
            cnt = 0;
            curr = curr - 1;
        }
    }    
    cout << res << endl;
    return 0;
}