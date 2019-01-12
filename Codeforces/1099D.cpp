#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
vector <int> edges[MAXN];
long long int A[MAXN];
long long int res[MAXN];
int impossible;

void dfs(int node, int parent, int level)
{
    if((level % 2) == 1 && A[node] < 0)
    {
        //cout << level << node << endl;
        impossible = 1;
        return;
    }
    if((level % 2) == 0 && A[node] >= 0)
    {
        //cout << level << node << endl;
        impossible = 1;
        return;
    }
    int L = edges[node].size();
    if(A[node] == -1){
        long long tmp = 1000000000000000000;
        for(int i = 0; i < L; ++i){
            if(edges[node][i] != parent){
                tmp = min(tmp, A[edges[node][i]] - A[parent]);
            }
        }
        if(tmp == 1000000000000000000)
            tmp = 0;
        res[node] = tmp;
        A[node] = A[parent] + res[node];
        for(int i = 0; i < L; ++i){
            if(edges[node][i] != parent)
                dfs(edges[node][i], node, level + 1);
        }
    }
    else if(node != 1){
        res[node] = A[node] - A[parent];
        for(int i = 0; i < L; ++i)
            if(edges[node][i] != parent)
                dfs(edges[node][i], node, level + 1);
    }
    else{
        for(int i = 0; i < L; ++i)
            if(edges[node][i] != parent)
                dfs(edges[node][i], node, level + 1);
    }
    return;
}

int main()
{
    cin >> N;
    for(int i = 2; i <= N; ++i){
        int p;
        cin >> p;
        edges[i].push_back(p);
        edges[p].push_back(i);
    }
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    res[1] = A[1];
    dfs(1, -1, 1);
    for(int i = 1; i <= N; ++i){
        if(res[i] < 0)
        {
            impossible = 1;
            break;
        }
    }
    if(impossible)
        cout << "-1\n";
    else{
        long long sum = 0;
        for(int i = 1; i <= N; ++i){
            sum += res[i];
        }
        cout << sum << endl;
    }
    return 0;
}