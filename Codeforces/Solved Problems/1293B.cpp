#include "bits/stdc++.h"
using namespace std;

int main()
{
    long double res = 0;
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i)
        res = res + (1.0 / i);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}