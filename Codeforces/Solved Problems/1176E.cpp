#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int T, N, M, u, v;

vector <int> edges[MAXN];
int parent[MAXN];
int sz[MAXN];
vector <int> B;
vector <int> W;
int color[MAXN];

int root(int node)
{
	if(parent[node] == node)return node;
	return parent[node] = root(parent[node]);
}

void _union(int a, int b)
{
	if(a==b)return;
	a = root(a);
	b = root(b);
	if(sz[a]<sz[b]){
		sz[b]+=sz[a];
		parent[a] = parent[b];
	}
	else
	{
		sz[a]+=sz[b];
		parent[b] = parent[a];
	}
}

void dfs(int node, int c){
    if(color[node] != -1)
        return;
    int L = edges[node].size();
    color[node] = c;
    if(c == 0)
        W.push_back(node);
    else
        B.push_back(node);
    for(int i = 0; i < L; ++i){
        dfs(edges[node][i], 1 - c);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        B.clear();
        W.clear();
        for(int i = 1; i <= N; ++i)
            edges[i].clear();
        
        for(int i=1; i<=N; i++)sz[i] = 1, parent[i] = i, color[i] = -1;
        
        for(int i = 1; i <= M; ++i){
            cin >> u >> v;
            if(root(u) == root(v))
                continue;
            _union(u, v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        dfs(1, 0);
        if(W.size() <= (N / 2)){
            int l = W.size();
            cout << l << endl;
            int cnt = 0;
            for(int i = 0; i < l; ++i){
                cout << W[i] << " ";
                cnt++;
            }
        }
        else{
            int l = B.size();
            cout << l << endl;
            int cnt = 0;
            for(int i = 0; i < l; ++i){
                cout << B[i] << " ";
                cnt++;
            }
        }
        cout << endl;
    }
    return 0;
}