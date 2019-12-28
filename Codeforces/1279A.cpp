#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long A, B, C;
        cin >> A >> B >> C;
        long long sum = ceil((A + B + C) * 1.0 / 2);
        if(A > sum || B > sum || C > sum)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}