#include "bits/stdc++.h"
using namespace std;

int main()
{
    ifstream cin("leapfrog_ch_.txt");
    ofstream cout("1.out");
    int T;
    cin >> T;
    int cases = 1;
    while(T--){
        string S;
        cin >> S;
        int L = S.size();
        int c = 0;
        for(int i = 0; i < L; ++i)
        {
            if(S[i] == 'B')
                c++;
        }
        if((c >= min(2, (L / 2)) && (c <= (L - 2))))
            cout << "Case #" << cases << ": Y\n";
        else
            cout << "Case #" << cases << ": N\n";
        cases++;
    }
    return 0;
}