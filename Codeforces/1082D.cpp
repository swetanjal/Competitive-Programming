#include "bits/stdc++.h"
using namespace std;
const int MAXN = 505;
int res[MAXN][MAXN];
int A[MAXN];
priority_queue < pair <int, int> > P;
vector <pair <int, int> > V;
vector <pair <int, int> > B;
int done[MAXN];
int DP[MAXN][MAXN];
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];   
    int best = -1;
    
    for(int i = 1; i < N; ++i){
        
        for(int j = 1; j <= N; ++j)
            for(int k = 1; k <= N; ++k)
                DP[j][k] = 0;
        while(P.empty() == false)
            P.pop();
        for(int j = 0; j < N; ++j){
            P.push(make_pair(A[j], j + 1));
        }
        V.clear();
        B.clear();    
        
        for(int j = 1; j <= N; ++j)
            done[j] = 0;
        int impossible = 0;
        for(int j = 1; j <= i; ++j)
        {
            if(P.empty()){
                impossible = 1;
                break;
            }
            B.push_back(P.top());
            P.pop();
        }
        if(impossible){
            continue;
        }
        if(P.empty()){
            continue;
        }
        V.push_back(P.top());
        int u, v;
        u = P.top().second;
        P.pop();
        done[u] = 1;
        for(int j = 0; j < B.size(); ++j){
            P.push(B[j]);
        }
        for(int j = 1; j <= i; j++){
            v = P.top().second;
            V.push_back(P.top());
            P.pop();
            DP[u][v] = 1;
            DP[v][u] = 1;
            u = v;
            done[u] = 1;
        }
        while(P.empty() == false){
            P.pop();
        }
        
        for(int j = 0; j <= i; j++)
        {
            int x = V[j].first;
            int y = V[j].second;
            if(j == 0 || j == i)
                P.push(make_pair(x - 1, y));
            else{
                if((x - 2) < 0){
                    impossible = 1;
                    break;
                }
                P.push(make_pair(x - 2, y));
            }
        }
        if(impossible)
            continue;
        for(int j = 1; j <= N; ++j){
            if(done[j] == 0){
                u = j;
                if(P.top().second == j){
                    // No self loop
                    pair <int, int> lol = P.top();
                    P.pop();
                    if(P.top().first <= 0){
                        impossible = 1;
                        break;
                    }
                    else{
                        v = P.top().second;
                        int c = P.top().first;
                        c -= 1;
                        P.pop();
                        P.push(make_pair(c, v));    
                    }
                    P.push(lol);
                }
                else if(P.top().first <= 0){
                    impossible = 1;
                    break;
                }
                else{
                    v = P.top().second;
                    int c = P.top().first;
                    c -= 1;
                    P.pop();
                    P.push(make_pair(c, v));
                }
                P.push(make_pair(A[j - 1] - 1, j));
                DP[u][v] = 1;
                DP[v][u] = 1;
            }
        }
        if(impossible == 0){
            best = i;
            for(int k = 1; k <= N; ++k){
                for(int j = 1; j <= N; ++j)
                    res[k][j] = DP[k][j];
            }
        }
    }
    if(best == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES " << best << endl;
        int edges = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = i; j <= N; ++j){
                if(res[i][j] == 1)
                    edges++;
            }
        }
        cout << edges << endl;
        for(int i = 1; i <= N; ++i){
            for(int j = i; j <= N; ++j){
                if(res[i][j])
                    cout << i << " " << j << endl;
            }
        }
    }
    
    return 0;
}