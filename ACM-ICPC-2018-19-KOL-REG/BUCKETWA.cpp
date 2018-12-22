#include "bits/stdc++.h"
using namespace std;
long double dH, dL, dR, K;
long double func(long double x)
{
    return sqrt(dH * dH + x * x) / K + sqrt(dL * dL + (dR - x) * (dR - x));
}

long double compute(long double x)
{
    return sqrt(dH * dH + x * x) + sqrt(dL * dL + (dR - x) * (dR - x));
}

long double solve()
{
    long double l = 0;
    long double r = dR;
    for(int i = 0; i < 500; ++i){
        long double l1 = (2 * l + r) / 3;
        long double l2 = (l + 2 * r) / 3;
        if(func(l1) < func(l2))
            r = l2;
        else
            l = l1;
    }
    return compute(l);
}

int main()
{
    cin >> dH >> dL >> dR >> K;
    while(dH != 0 || dL != 0 || dR != 0 || K != 0)
    {
        cout << solve() << endl;
        cin >> dH >> dL >> dR >> K;
    }
    return 0;
}