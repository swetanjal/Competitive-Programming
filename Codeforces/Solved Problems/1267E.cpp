#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    pair < int, int > A[M];
    int cum[N];
    for(int i = 0; i < N; ++i)
        cum[i] = 0;
    int tot = 0;
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j < N; ++j)
        {
            int tmp;
            cin >> tmp;
            cum[j - 1] += tmp;
        }
        cin >> A[i - 1].first;
        tot += A[i - 1].first;
        A[i - 1].second = i;
    }
    int res = -1;
    for(int i = 0; i < (N - 1); ++i)
        res = max(res, cum[i]);
    sort(A, A + M);
    int running = 0;
    int count = 0;
    int idx = -1;

    if(tot <= res)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = M - 1; i >= 0; --i){
        if(running > res)
            break;
        running += A[i].first;
        idx = i;
        count = count + 1;
    }
    cout << count << endl;
    for(int i = M - 1; i >= idx; --i)
    {
        cout << A[i].second << " ";
    }
    cout << endl;
    return 0;
}