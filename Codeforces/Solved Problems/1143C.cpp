#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, root;
int C[MAXN];
vector <int> edges[MAXN];
vector <int> res;

void dfs(int node, int parent){
    int L = edges[node].size();
    int ret = C[node];
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent){
            ret = ret & C[edges[node][i]];
            dfs(edges[node][i], node);
        }
    }
    if(ret){
        res.push_back(node);
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int p;
        cin >> p >> C[i];
        if(p == -1){
            root = i;
        }
        else{
            edges[p].push_back(i);
            edges[i].push_back(p);
        }
    }
    dfs(root, -1);
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    if(res.size() == 0)
        cout << "-1";
    cout << endl;
    return 0;
}