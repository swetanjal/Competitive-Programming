#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e6 + 5;
int T, N, K, L, cnt;
string S;
int edges[MAXN][26];
int ending[MAXN];
int res;

int dfs(int node, int depth)
{
    int rem = ending[node];
    for(int i = 0; i < 26; ++i){
        if(edges[node][i] > 0)
            rem += dfs(edges[node][i], depth + 1);
    }
    res = res + (rem / K) * depth;
    rem = rem % K;
    return rem;
}

void insert(){
    int node = 0;
    for(int i = 0; i < L; ++i){
        int tmp = S[i] - 'A';
        if(edges[node][tmp] == 0){
            edges[node][tmp] = (++cnt);
        }
        node = edges[node][tmp];
    }
    ending[node] += 1;
}

int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> N >> K;
        cnt = 0; res = 0;
        for(int i = 0; i < N; ++i){
            cin >> S;
            L = S.size();
            insert();
        }
        dfs(0, 0);
        cout << "Case #" << cases << ": " << res << endl;
        for(int i = 0; i <= cnt; ++i){
            for(int j = 0; j < 26; ++j)
                edges[i][j] = 0;
            ending[i] = 0;
        }
    }
    return 0;
}