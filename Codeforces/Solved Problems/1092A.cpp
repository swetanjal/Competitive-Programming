#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        int cnt = 0;
        char A[N];
        for(int i = 0; i < N; ++i)
        {
            A[i] = (char)(97 + (cnt % K));
            cnt++;
        }
        for(int i = 0; i < N; ++i)
            cout << A[i];
        cout << endl;
    }
    return 0;
}