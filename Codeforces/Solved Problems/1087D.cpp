#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
long double K;
vector <int> edges[MAXN];
int main()
{
    cin >> N >> K;
    for(int i = 1; i < N; ++i){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    long double c = 0;
    for(int i = 1; i <= N; ++i){
        if(edges[i].size() == 1){
            c++;
        }
    }
    long double tmp = K / c;
    tmp *= 2;
    cout << fixed << setprecision(9) << tmp << endl;
    return 0;
}