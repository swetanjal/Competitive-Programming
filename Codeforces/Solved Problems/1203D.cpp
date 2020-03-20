#include "bits/stdc++.h"
using namespace std;
string S, T;
int LS, LT;
int main()
{
    cin >> S;
    cin >> T;
    LS = S.size();
    LT = T.size();
    int DP1[LS];
    int DP2[LS];
    int DPf[LS + 5];
    int DPl[LS + 5];
    int ptr = 0;
    for(int i = 0; i < LS; ++i){
        if(ptr < LT && S[i] == T[ptr]){
            ptr++;
            DPf[ptr - 1] = i;
        }
        DP1[i] = ptr;
    }
    ptr = LT - 1;
    for(int i = LS - 1; i >= 0; --i){
        if(ptr >= 0 && S[i] == T[ptr]){
            ptr--;
            DPl[ptr + 1] = i;
        }
        DP2[i] = ptr + 1;
    }
    int ans = 0;
    for(int i = 0; i < LT; ++i){
        ans = max(ans, DPl[i] - DPf[i - 1] - 1);
        //cout << DPf[i] << " " << DPl[i] << endl;
    }
    
    for(int i = 0; i < LS; ++i)
    {
        if(DP2[i] == 0){
            ans = max(ans, i);
        }
    }
    
    for(int i = LS - 1; i >= 0; --i){
        if(DP1[i] == LT){
            ans = max(ans, LS - 1 - i);
        }
    }
    
    //cout << endl;
    for(int i = 0; i < LS; ++i){
        if(DP1[i] == LT){
            ans = max(ans, LS - i - 1);
            continue;
        }
        int low = i; int high = LS - 1;
        int mid; int pos = -1;
        while(high >= low){
            mid = (high + low) / 2;
            if(DP2[mid] == DP1[i]){
                low = mid + 1;
                pos = mid;
            }
            else if(DP2[mid] > DP1[i]){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(pos != -1){
            ans = max(ans, pos - i - 1);
        }
    }    
    cout << ans << endl;
    return 0;
}