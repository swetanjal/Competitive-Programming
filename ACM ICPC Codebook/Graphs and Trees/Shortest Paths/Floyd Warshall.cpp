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