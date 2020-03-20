#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int N;
        cin >> N;
        int mod = (N % 14);
        if(N <= 6)
            cout << "NO\n";
        else if(mod >= 1 && mod <= 6)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}