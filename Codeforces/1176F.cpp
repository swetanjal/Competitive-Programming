#include "bits/stdc++.h"
using namespace std;
const long long inf = 1e10;
const long long neg_inf = -1e10;
const int MAXN = 2e5 + 5;
vector <long long> D[MAXN][4];
int N;
long long DP[MAXN][10];

bool cmp(long long a, long long b)
{
    return a > b;
}

long long get_best(int idx, int l, int r){
    long long res = 0;
    for(int i = l; i <= r; ++i)for(int j = 0; j < D[idx][i].size(); ++j)res = max(res, D[idx][i][j]);
    return res;
}

pair < long long, long long > get_best_2(int idx, int l, int r, int f){
    pair <long long, long long > p = make_pair(neg_inf, neg_inf);
    if(D[idx][1].size() >= 2)
        p.first = D[idx][1][0], p.second = D[idx][1][1];
    if(D[idx][1].size() >= 1 && D[idx][2].size() >= 1 && (f * max(D[idx][1][0], D[idx][2][0]) + min(D[idx][1][0], D[idx][2][0])) > (f * p.first + p.second)){
        p.first = max(D[idx][1][0], D[idx][2][0]);
        p.second = min(D[idx][1][0], D[idx][2][0]);
    }
    return p;
}

long long rec(int idx, int i_th){
    i_th = i_th % 10;
    if(idx == N)return 0;
    if(DP[idx][i_th] != -1)return DP[idx][i_th];
    // Play 0 cards
    DP[idx][i_th] = rec(idx + 1, i_th % 10);
    // Play 1 card
    long long tmp = neg_inf;
    if(i_th == 0)tmp = (2 * get_best(idx, 1, 3)) + rec(idx + 1, (i_th + 1) % 10);
    else tmp = get_best(idx, 1, 3) + rec(idx + 1, (i_th + 1) % 10);
    DP[idx][i_th] = max(DP[idx][i_th], tmp);
    // Play 2 cards
    tmp = neg_inf;
    pair <long long, long >  k;
    if(i_th == 0 || i_th == 9){
        k = get_best_2(idx, 1, 2, 2);
        tmp = k.first * 2 + rec(idx + 1, (i_th + 2) % 10);
    }
    else{
        k = get_best_2(idx, 1, 2, 1);
        tmp = k.first + rec(idx + 1, (i_th + 2) % 10);
    } 
    if(k.second != neg_inf)DP[idx][i_th] = max(DP[idx][i_th], tmp + k.second);
    // Play 3 cards
    tmp = neg_inf;
    if(i_th == 0 || i_th == 9 || i_th == 8){
        if(D[idx][1].size() >= 3)
            tmp = D[idx][1][0] * 2 + D[idx][1][1] + D[idx][1][2] + rec(idx + 1, (i_th + 3) % 10);
    }
    else
        if(D[idx][1].size() >= 3)
            tmp = D[idx][1][0] + D[idx][1][1] + D[idx][1][2] + rec(idx + 1, (i_th + 3) % 10);
    return DP[idx][i_th] = max(DP[idx][i_th], tmp);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        int n; 
        cin >> n;
        for(int j = 0; j < n; ++j)
        {
            long long c, d;
            cin >> c >> d;
            D[i][c].push_back(d);
        }
        for(int j = 1; j <= 3; ++j)
            sort(D[i][j].begin(), D[i][j].end(), cmp);
    }
    for(int i = 0; i < N; ++i)for(int j = 0; j < 10; ++j)DP[i][j] = -1;
    cout << rec(0, 1) << endl;
    return 0;
}