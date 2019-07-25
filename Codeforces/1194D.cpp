#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long N, K;
        cin >> N >> K;
        if((K % 3) == 0 && (N >= K)){
            // Things get shifted
            long long lol = N % (K + 1);
            if(lol == K)
                cout << "Alice\n";
            else if((lol % 3) == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        else{
            if((N % 3) == 0)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }    
    return 0;
}