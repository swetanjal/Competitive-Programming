#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    cin >> N;
    if((N % 2) != 0)
        cout << "0\n";
    else{
        int L = N / 2;
        long long p = 1;
        for(int i = 1; i <= L; ++i)
            p *= 2;
        cout << p << endl;
    }
    return 0;
}