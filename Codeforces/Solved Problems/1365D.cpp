#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
char A[MAXN][MAXN];
int N, M, T;
int vis[MAXN][MAXN];
int DP[MAXN][MAXN];
void fill(int i, int j)
{
    if(i < 0 || j < 0 || i == N || j == M)
        return;
    if(A[i][j] == '.')
    A[i][j] = '#';
}

void dfs(int r, int c)
{
    if(r == N || c == M || r < 0 || c < 0)
        return;
    if(vis[r][c] || A[r][c] == '#')
        return;
    vis[r][c] = 1;
    DP[r][c] = 1;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                cin >> A[i][j];
        for(int i = 0; i < N; ++i)
        {
            
            for(int j = 0; j < M; ++j){
                DP[i][j] = 0;
                vis[i][j] = 0;
                if(A[i][j] == 'B'){
                    fill(i - 1, j);
                    fill(i + 1, j);
                    fill(i, j + 1);
                    fill(i, j - 1);
                }
            }
        }
        dfs(N - 1, M - 1);
        int no = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(A[i][j] == 'G'){
                    if(DP[i][j] == 0)
                        no = 1;
                }
                if(A[i][j] == 'B'){
                    if(DP[i][j] == 1)
                        no = 1;
                }
            }
        }
        if(no)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}