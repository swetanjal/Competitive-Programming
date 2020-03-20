#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 4e5 + 5;

int pos[MAXN];
int N, M;
int Rank[MAXN];
int best[MAXN];
int worst[MAXN];

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
        Rank[i] = i, pos[i] = i, best[i] = i, worst[i] = i;
    for(int i = 1; i <= M; ++i){
        int idx;
        cin >> idx;
        int getRank = Rank[idx];
        if(getRank == 1)
            continue;
        int before = pos[getRank - 1];
        swap(pos[getRank], pos[getRank - 1]);
        Rank[idx] = getRank - 1;
        Rank[before] = getRank;

        best[idx] = min(best[idx], Rank[idx]);
        worst[idx] = max(worst[idx], Rank[idx]);

        best[before] = min(best[before], Rank[before]);
        worst[before] = max(worst[before], Rank[before]);
    }
    for(int i = 1; i <= N; ++i)
        cout << best[i] << " " << worst[i] << endl;
    return 0;
}