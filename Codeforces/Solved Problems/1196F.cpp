#include "bits/stdc++.h"
using namespace std;

// Template for Floyd Warshall
/*
    Author: Swetanjal Dutta(swetanjal)
    This template is used to compute All Pair Shortest Path in O(N ^ 3).
    Usage:
    1. FloydWarshall obj(N)
    2. obj.addEdge(u, v, c)
    3. obj.computeShortestPaths()
*/
class FloydWarshall{
public:
    const long long int INF = 1000000000000000;
    vector < vector < long long > > DP;
    int N;
    FloydWarshall(int n){
        N = n;
        vector <long long> t;
        for(int i = 0; i <= n; ++i)
            t.push_back(INF);
        for(int i = 0; i <= n; ++i)
            DP.push_back(t);
        for(int i = 1; i <= n; ++i)
            DP[i][i] = 0;
    }
    void addEdge(int u, int v, long long cost)
    {
        DP[u][v] = cost;
        DP[v][u] = cost;
    }
    void computeShortestPaths()
    {
        for(int k = 1; k <= N; k++)
		    for(int i = 1; i <= N; i++)
			    for(int j = 1; j <= N; j++)
				    DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
    }
};
// End of template for Floyd Warshall
const int MAXM = 2e5 + 5;
int N, M, K;
pair < long long int, pair <int, int> > A[MAXM];
int main()
{
    cin >> N >> M >> K;
    int copyK = K;
    K = min(K, M);
    for(int i = 0; i < M; ++i){
        cin >> A[i].second.second >> A[i].second.first >> A[i].first;
    }
    sort(A, A + M);
    map < int , int > H;
    int cnt = 1;
    for(int i = 0; i < K; ++i)
    {
        if(H.find(A[i].second.first) == H.end())
            H[A[i].second.first] = cnt++;
        if(H.find(A[i].second.second) == H.end())
            H[A[i].second.second] = cnt++;
    }
    FloydWarshall obj(H.size());
    for(int i = 0; i < K; ++i){
        obj.addEdge(H[A[i].second.second], H[A[i].second.first], A[i].first);
    }
    obj.computeShortestPaths();
    vector <long long int> res;
    for(int i = 1; i < cnt; ++i){
        for(int j = i + 1; j < cnt; ++j)
            if(obj.DP[i][j] != 0 && obj.DP[i][j] != obj.INF)
            res.push_back(obj.DP[i][j]);
    }
    sort(res.begin(), res.end());
    cout << res[copyK - 1] << endl;
    return 0;
}