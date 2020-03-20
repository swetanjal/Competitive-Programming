#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int r;
    cin >> r;
    int done = 0;
    for(int i = 1; i <= 1000000; i++){
        long long num = (r - (i * 1LL * i) - i - 1);
        long long den = 2 * i;
        if((num % den) == 0 && (num / den) > 0)
        {
            done = 1;
            cout << i << " " << (num / den) << endl;
            break;
        }
    }
    if(!done)
        cout << "NO\n";
    return 0;
}