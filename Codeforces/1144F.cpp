#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
vector <int> edges[MAXN];
vector <int> u;
vector <int> v;
map < pair <int, int> , int > DP;
int tree = 1;
int N, M;
bool visited[MAXN];
void dfs(int node, int parent, int parity){
    if(visited[node])
        return;
    visited[node] = true;
    int L = edges[node].size(); 
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent){
            DP[make_pair(node, edges[node][i])] = parity;
            DP[make_pair(edges[node][i], node)] = 1 - parity;
            dfs(edges[node][i], node, 1 - parity);
        }
    }
}
int color[MAXN];
int chk(int node, int c){
    if(color[node] != -1){
        if(color[node] == c)
            return true;
        return false;
    }
    color[node] = c;
    int L = edges[node].size();
    bool ret = true;
    for(int i = 0; i < L; ++i){
        ret = ret & chk(edges[node][i], 1 - c);
        if(ret == false)
            return false;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int x, y;
        cin >> x >> y;
        u.push_back(x);
        v.push_back(y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i = 1; i <= N; ++i)
        color[i] = -1;
    if(chk(1, 0)){
        cout << "YES\n";
        for(int i = 1; i <= N; ++i)
            visited[i] = false;
        dfs(1, -1, 0);
        for(int i = 0; i < M; ++i){
            cout << DP[make_pair(u[i], v[i])];
        }
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}