#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3005;
int N, M, R, C;
long long int x, y, z, g0;
int A[MAXN][MAXN];
vector <int> g;
vector <int> f(vector <int> a, int k)
{
    vector <int> s;
    priority_queue < pair <int, int>, vector <pair <int, int> > , greater < pair <int, int> >  > P;
    for(int i = 0; i < k; ++i){
        P.push({a[i], i});
    }
    int l = a.size();
    s.push_back(P.top().first);
    for(int i = k; i < l; ++i){
        while((P.empty() == false) && (P.top().second <= (i - k))){
            P.pop();
        }
        P.push({a[i], i});
        s.push_back(P.top().first);
    }
    return s;
}

int main(){
    cin >> N >> M >> R >> C;
    cin >> g0 >> x >> y >> z;
    g.push_back(g0);
    for(int i = 1; i <= 9000000; ++i)
        g.push_back((int)(((g[i - 1] * 1LL * x) % z) + y) % z);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            A[i][j] = g[i * M + j];
    vector < vector <int> > ret;
    for(int i = 0; i < N; ++i){
        vector <int> t;
        for(int j = 0; j < M; ++j)
            t.push_back(A[i][j]);
        vector <int> res = f(t, C);
        ret.push_back(res);
    }
    N = ret.size();
    M = ret[0].size();
    long long s = 0;
    for(int j = 0; j < M; ++j){
        vector <int> t;
        for(int i = 0; i < N; ++i)
            t.push_back(ret[i][j]);
        vector <int> res = f(t, R);
        for(int i = 0; i < res.size(); ++i)
            s += res[i];
    }
    cout << s << endl;
    return 0;
}