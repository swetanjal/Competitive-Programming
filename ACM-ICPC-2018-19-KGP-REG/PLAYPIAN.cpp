#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string S;
        cin >> S;
        int L = S.size();
        int valid = 1;
        for(int i = 0; i < L; i += 2)
        {
            if(S[i] != S[i + 1])
            {
                continue;
            }
            else{
                valid = 0;
                break;
            }
        }
        if(valid)
            cout << "yes\n";
        
        else
            cout << "no\n";
    }
    return 0;
}