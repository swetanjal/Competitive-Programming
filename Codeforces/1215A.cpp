#include "bits/stdc++.h"
using namespace std;

int main()
{
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int calc1 = min(a1, (n / k1)) + min(a2, (n - min(a1, (n / k1)) * k1) / k2);
    int calc2 = min(a2, (n / k2)) + min(a1, (n - min(a2, (n / k2)) * k2) / k1);
    cout << min(calc1, calc2) << " " << max(calc1, calc2) << endl;
    return 0;
}