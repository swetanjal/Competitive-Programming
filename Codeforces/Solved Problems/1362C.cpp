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
        long long sum = 0;
        for(long long int i = 1; i <= 61; ++i){
            // cout << i << endl;
            long long int diff = N - (1LL << (i - 1));
            if(diff < 0)
                break;
            
            long long int occ = (diff / (1LL << i)) + 1;
            // cout << i << " " << occ << endl;
            sum = sum + (i * 1LL * occ);
        }
        cout << sum << endl;
    }
    return 0;
}