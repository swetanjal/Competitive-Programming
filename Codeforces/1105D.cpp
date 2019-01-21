#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1005;
int N, M, P;
char A[MAXN][MAXN];
int filled;
long long int cost[10];
vector < pair <int, int> > frontier[10];
int visited[MAXN][MAXN];
bool chk(int x, int y)
{
    if(x < 0 || y < 0)
        return false;
    if(x == N)
        return false;
    if(y == M)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> N >> M >> P;
    for(int i = 1; i <= P; ++i)
        cin >> cost[i];
    int turn = 1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> A[i][j];
            if(A[i][j] == '#')
                filled++;
        }
    }
    for(int i = 1; i <= P; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < M; ++k)
            {
                char c = char(48 + i);
                if(A[j][k] == c)
                    frontier[i].push_back(make_pair(j, k));
            }
        }
    }
    for(int lol = 1; lol <= 5000000; ++lol)
    {
        queue < pair < int, pair <int, int> >  > Q;
        int l = frontier[turn].size();
        for(int i = 0; i < l; ++i){
            int x = frontier[turn][i].first;
            int y = frontier[turn][i].second;
            Q.push(make_pair(cost[turn], make_pair(x, y)));
        }
        frontier[turn].clear();
        while(Q.empty() == false){
            int x = Q.front().second.first;
            int y = Q.front().second.second;
            int dist = Q.front().first;
            Q.pop();
            if(visited[x][y] == 0 && (A[x][y] == '.' || A[x][y] == (char)(48 + turn))){
                if(dist != 0){
                    visited[x][y] = 1;
                    filled++;
                }
                A[x][y] = (char)(48 + turn);
                if(dist == 0)
                    frontier[turn].push_back(make_pair(x, y));
                else{
                    if(chk(x + 1, y) && visited[x + 1][y] == false)
                        Q.push(make_pair(dist - 1, make_pair(x + 1, y)));
                    if(chk(x - 1, y) && visited[x - 1][y] == false)
                        Q.push(make_pair(dist - 1, make_pair(x - 1, y)));
                    if(chk(x, y + 1) && visited[x][y + 1] == false)
                        Q.push(make_pair(dist - 1, make_pair(x, y + 1)));
                    if(chk(x, y - 1) && visited[x][y - 1] == false)
                        Q.push(make_pair(dist - 1, make_pair(x, y - 1)));
                }
            }
        }
        turn++;
        if(turn > P)
            turn = 1;
    }
    for(int i = 1; i <= P; ++i){
        int res = 0;
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < M; ++k){
                if(A[j][k] == (char)(48 + i))
                    res++;
            }
        }
        cout << res << " ";
    }
    cout << "\n";
    return 0;

}