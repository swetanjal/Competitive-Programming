#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    int L = s.size();
    long long int cum1[L];
    long long int cum2[L];
    for(int i = 0; i < L; ++i)
        cum1[i] = 0, cum2[i] = 0;
    for(int i = 1; i < L; ++i){
        if(s[i] == 'v' && s[i - 1] == 'v')
            cum1[i] = cum1[i - 1] + 1;
        else
            cum1[i] = cum1[i - 1];         
    }
    for(int i = (L - 2); i >= 0; --i)
    {
        if(s[i] == 'v' && s[i + 1] == 'v')
            cum2[i] = cum2[i + 1] + 1;
        else
            cum2[i] = cum2[i + 1];
    }
    long long res = 0;
    for(int i = 0; i < L; ++i){
        if(s[i] == 'o'){
            res = res + (cum1[i] * cum2[i]);
        }
    }
    cout << res << endl;
    return 0;
}