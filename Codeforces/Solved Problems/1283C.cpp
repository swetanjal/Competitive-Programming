#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
vector <int> edges[MAXN];
vector <int> A[MAXN];
vector <int> a[MAXN];
int cnt;
int visited[MAXN];
int F[MAXN];
void dfs(int node)
{
    int l = edges[node].size();
    if(l < 2){
        a[cnt].push_back(node);
    }
    visited[node] = 1;
    for(int i = 0; i < l; ++i){
        if(visited[edges[node][i]] == 0)
            dfs(edges[node][i]);
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int tmp;
        cin >> tmp;
        F[i] = tmp;
        if(tmp == 0)
            continue;
        edges[tmp].push_back(i);
        edges[i].push_back(tmp);
    }
    for(int i = 1; i <= N; ++i){
        if(visited[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    int c = 0;
    for(int i = 0; i < cnt; ++i){
        if(a[i].size() == 1){
            A[c].push_back(a[i][0]);
            A[c].push_back(a[i][0]);
            c++;
        }
        else if(a[i].size() == 2){
            if(F[a[i][1]] == 0){
                A[c].push_back(a[i][0]);
                A[c].push_back(a[i][1]);
            }
            else{
                A[c].push_back(a[i][1]);
                A[c].push_back(a[i][0]);
            }
                
            c++;
        }
    }
    for(int i = 0; i < c-1; ++i){
        //cout << A[i][0] << " " << A[i][1] << endl;
        
        if(F[A[i][1]] == 0)
            F[A[i][1]] = A[i + 1][0];
        else
            F[A[i + 1][0]] = A[i][1];
    }

    if(F[A[c - 1][1]] == 0)
        F[A[c - 1][1]] = A[0][0];
    else
        F[A[0][0]] = A[c - 1][1];
    for(int i = 1; i <= N; ++i)
        cout << F[i] << " ";
    cout << endl;
    return 0;
}