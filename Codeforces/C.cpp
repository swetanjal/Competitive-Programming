#include "bits/stdc++.h"
using namespace std;
string S;
int main()
{
    cin >> S;
    int ans = 0;
    int L = S.size();
    for(int i = 0; i < L; i += 3){
        if(S[i] != 'P')
            ans++;
    }
    for(int i = 1; i < L; i += 3){
        if(S[i] != 'E')
            ans++;
    }
    for(int i = 2; i < L; i += 3){
        if(S[i] != 'R')
            ans++;
    }
    cout << ans << endl;
    return 0;
}