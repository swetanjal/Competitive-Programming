#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int A, B;
        cin >> A >> B;
        int N;
        cin >> N;
        long long low = A; long long high = B;
        long long mid;
        while(high >= low)
        {
            mid = (high + low) / 2;
            cout << mid << endl;
            string s;
            cin >> s;
            if(s == "CORRECT")
                break;
            if(s == "TOO_SMALL")
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}