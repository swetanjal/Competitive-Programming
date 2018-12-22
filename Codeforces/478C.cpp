#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int A[3];
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    long long res = A[0];
    long long reqd = 2 * A[0];
    reqd = reqd - max(reqd, (A[2] - A[1]));
    if(reqd > 0)
    {
        A[2] = A[1];
        res = res + min(A[1], (A[2] + A[1] - reqd) / 3);
    }
    else{
        A[2] -= (2 * A[0]);
        res = res + min(A[1], (A[1] + A[2]) / 3);
    }

    cout << res << endl;
    return 0;
}