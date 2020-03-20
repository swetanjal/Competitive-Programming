#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int A, B, C;
    cin >> A >> B >> C;
    long long ans = 0;
    // fix A
    if(B >= (A + 1) && C >= (A + 2))
        ans = max(ans, A + A + 1 + A + 2);
    // fix B
    if(A >= (B - 1) && C >= (B + 1))
        ans = max(ans, B - 1 + B + B + 1);
    // fix C
    if(B >= (C - 1) && A >= (C - 2))
        ans = max(ans, C + C - 1 + C - 2);
    cout << ans << endl;
    return 0;
}