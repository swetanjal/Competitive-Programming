#include "bits/stdc++.h"
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    while(Q--)
    {
        long long int L, R, D;
        cin >> L >> R >> D;
        if(D < L)
            cout << D << endl;
        else{
            long long tmp = ceil(R * 1.0 / D);
            if((R % D) == 0)
                tmp++;
            cout << tmp * D << endl;
        }
    }
    return 0;
}