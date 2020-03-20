#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
map <int, int> DP[MAXN];
vector <int> edges[MAXN];
vector <int> factors[MAXN];
int N, u, v;
int A[MAXN];

void dfs1(int node, int parent)
{
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
        {
            dfs1(edges[node][i], node);
        }
    }
    for(int i = 0; i < factors[node].size(); ++i){
        DP[node][factors[node][i]] = 1;
        for(int j = 0; j < L; ++j){
            if(edges[node][j] != parent){
                if(DP[edges[node][j]].find(factors[node][i]) != DP[edges[node][j]].end())
                    DP[node][factors[node][i]] = max(DP[node][factors[node][i]], 1 + DP[edges[node][j]][factors[node][i]]);
            }
        }
    }
}

int res = 0;

void dfs2(int node, int parent)
{
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
            dfs2(edges[node][i], node);
    }
    for(int i = 0; i < factors[node].size(); ++i){
        vector <int> tmp;
        for(int j = 0; j < L; ++j){
            if(edges[node][j] != parent)
                if(DP[edges[node][j]].find(factors[node][i]) != DP[edges[node][j]].end())
                    tmp.push_back(DP[edges[node][j]][factors[node][i]]);
        }
        sort(tmp.begin(), tmp.end());
        if(tmp.size() == 0){

            res = max(res, 1);
        }
        else if(tmp.size() == 1){
            res = max(res, 1 + tmp[0]);
        }
        else{
            res = max(res, 1 + tmp[tmp.size() - 1] + tmp[tmp.size() - 2]);
        }
    }
}


int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i <= N; ++i){
        int copy = A[i];
        for(int j = 2; j * j <= copy; ++j){
            int cnt = 0;
            while((copy % j) == 0)
            {
                if(cnt == 0){
                    factors[i].push_back(j);
                }
                copy /= j;
                cnt++;
            }
        }
        if(copy >= 2)
            factors[i].push_back(copy);
    }
    for(int i = 1; i < N; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs1(1, -1);
    //cout << DP[2][2] << endl;
    dfs2(1, -1);
    cout << res << endl;
    return 0;
}