#include "bits/stdc++.h"
using namespace std;

bool chk(int cap, int A, int B, int C)
{
    int group1 = min(cap, A);
    int remA = A - group1;
    int group2 = 0;
    int remC = C;
    if(remA > 0)
    {
        group2 = min(cap, remA);
        remA = remA - group2;
    }
    else{
        group2 = min(cap, C);
        remC = C - group2;
    }
    int group3 = min(cap, remC);
    remC = remC - group3;

    if(remA > 0 || remC > 0)
        return false;
    
    if(B <= (cap - group1) + (cap - group2) + (cap - group3))
        return true;
    return false;
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        int low = 1; int high = 1000;
        int mid; int pos = -1;
        while(high >= low)
        {
            int mid = (high + low) / 2;
            if(chk(mid, A, B, C)){
                high = mid - 1;
                pos = mid;
            }
            else
                low = mid + 1;
        }
        cout << pos << endl;
    }
    return 0;
}