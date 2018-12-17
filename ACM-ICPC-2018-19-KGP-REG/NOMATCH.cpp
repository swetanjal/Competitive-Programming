#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        long long int A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        sort(A, A + N);
        vector <long long> S;
        int cnt = N - 1;
        for(int i = 0; i < N; ++i)
        {
            if(S.size() == N)
                break;
            S.push_back(A[i]);
            S.push_back(A[cnt]);
            cnt--;
        }
        long long int res = 0;
        for(int i = 1; i < N; i += 2)
            res = res + abs(S[i] - S[i - 1]);
        cout << res << endl;
    }
    return 0;
}