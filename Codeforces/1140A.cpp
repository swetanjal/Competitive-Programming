#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int A[N + 1];
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    int limit = 0;
    int res = 0;
    for(int i = 1; i <= N; ++i){
        limit = limit + 1;
        res++;
        while(i <= limit){
            limit = max(limit, A[i]);
            i++;
        }
        i = limit;
    }
    cout << res << endl;
    return 0;
}