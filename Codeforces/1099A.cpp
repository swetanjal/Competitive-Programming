#include "bits/stdc++.h"
using namespace std;

int main()
{
    int W, H;
    cin >> W >> H;
    int u1, d1;
    int u2, d2;
    cin >> u1 >> d1;
    cin >> u2 >> d2;
    for(int i = H; i >= 0; i--)
    {
        W += i;
        if(i == d1)
            W -= u1;
        else if(i == d2)
            W -= u2;
        W = max(0, W);
    }
    cout << W << endl;
    return 0;
}