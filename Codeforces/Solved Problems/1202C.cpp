#include "bits/stdc++.h"
using namespace std;
int L;
string S;

bool chk(int m){
    int r = 0; int c = 0;
    vector <int> R;
    vector <int> C;
    int used = 0;
    for(int i = 0; i < L; ++i){
        if(S[i] == 'D')
            r++;
        if(S[i] == 'U')
            r--;
        if(S[i] == 'L')
            c--;
        if(S[i] == 'R')
            c++;
        if(abs(r) > m){
            if((f.size() - 2) >= 0){
                g(f[f.size() - 2]);
            }
        }
        if(abs(c) > m){

        }
    }    
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> S;
        L = S.size();
    }
    return 0;
}