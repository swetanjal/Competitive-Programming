#include "bits/stdc++.h"
using namespace std;
const int MAXM = 2e5 + 5;
int N, M, K, T;
int A[MAXM];
pair < pair < int, int >, int > S[MAXM];

bool chk(int idx)
{
    int val = A[M - idx];
    long long ans = N + 1;
    int max_point = 0;
    for(int i = 0; i < K; ++i)
    {
        if(S[i].second <= val || S[i].first.second < max_point)
        {
            continue;
        }
        int pos = S[i].first.first - 1;
        max_point = max(max_point, S[i].first.second);
        int j;
        for(j = i + 1; j < K; ++j)
        {
            if(S[j].first.first <= max_point)
            {
                if(S[j].second <= val)
                    continue;
                max_point = max(max_point, S[j].first.second);
            }
            else
                break;
        }
        i = j - 1;
        ans = ans + 2 * (max_point - pos);
    }
    
    // cout << ans << endl;
    if(ans <= T)
        return true;
    return false;
}

bool cmp(pair < pair < int , int > , int > x, pair < pair < int , int > , int > y)
{
    if(x.first.first != y.first.first)
        return x.first.first < y.first.first;
    return x.first.second > y.first.second;
}

int main()
{
    cin >> M >> N >> K >> T;
    for(int i = 0; i < M; ++i)
        cin >> A[i];
    sort(A, A + M);
    for(int i = 0; i < K; ++i)
        cin >> S[i].first.first >> S[i].first.second >> S[i].second;
    sort(S, S + K, cmp);
    //cout << chk(3) << endl;
    int low = 1; int high = M ;
    int pos = 0;

    while(high >= low)
    {
        int mid = (high + low) / 2;
        if(chk(mid) == true)
        {
            pos = mid;
            low = mid + 1;            
        }
        else
            high = mid - 1;
    }
    cout << pos << endl;
    return 0;
}