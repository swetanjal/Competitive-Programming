#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long s, i, f;
        cin >> s >> i >> f;
        if(s >(i + f))
			cout << f+1 << "\n";
        else
        cout << (f - floor((i + f - s) * 1.0/ 2)) << endl;
    }
    return 0;
}