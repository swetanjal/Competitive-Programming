#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int A[N + 5];
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    long long res = 100000000000000000;
    for(int i = 1; i <= N; ++i)
    {
        long long sum = 0;
        int x = i;
        for(int j = 1; j <= N; ++j)
            sum = sum + (A[j] * 2 * (abs(j - 1) + abs(x - j) + abs(x - 1)));
        res = min(res, sum); 
    }
    cout << res << endl;
    return 0;
}