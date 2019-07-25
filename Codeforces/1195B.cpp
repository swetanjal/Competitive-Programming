#include "bits/stdc++.h"
using namespace std;

int main()
{
    long double N, K;
    cin >> N >> K;
    long double l = 9 - 4 * (-2 * N - 2 * K);
    l = sqrt(l);
    l = l - 3;
    l = l / 2;
    long long res = (N - l);
    cout << res << endl;
    return 0;
}