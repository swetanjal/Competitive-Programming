#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e3 + 5;
int T, N;
int sp;
vector <int> edges[MAXN];

int dfs(int node, int parent)
{
    if(node == sp)
    {
        int parity = 0;
        int l = edges[node].size();
        int flag = 0;
        for(int i = 0; i < l; ++i)
        {
            if(edges[node][i] != parent){
                int t = dfs(edges[node][i], node);
                parity += (t % 2);
                flag++;
            }
        }
        if(flag <= 1)
            return 1;
        parity %= 2;
        if(parity == 0)
            return 2;
        else
            return 1;
    }
    else{
        int tot = 0;
        int l = edges[node].size();
        for(int i = 0; i < l; ++i){
            if(edges[node][i] != parent)
            {
                tot += dfs(edges[node][i], node);
            }
        }
        tot += 1;
        return tot;
    }
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> sp;
        for(int i = 1; i <= N; ++i)
            edges[i].clear();
        
        for(int i = 1; i < N; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        int p = dfs(sp, -1);
        if(p == 1)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
    }
    return 0;
}