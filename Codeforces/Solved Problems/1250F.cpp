#include "bits/stdc++.h"
using namespace std;
long long A;
int main()
{
    cin >> A;
    long long res = 1e18;
    for(int i = 1; i <= 100000; ++i){
        long long int l = i;
        if((A % l) != 0)
            continue;
        long long int b = A / l;
        long long ar = 2 * (l + b);
        res = min(res, ar);
    }
    cout << res << endl;
    return 0;
}