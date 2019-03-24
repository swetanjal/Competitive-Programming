#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        int L;
        cin >> L;
        char A[L];
        for(int i = 0; i < L; ++i)
            cin >> A[i];
        int idx1 = -1;
        int idx2 = -1;
        for(int i = 0; i < L; ++i){
            if(A[i] == '>')
            {
                idx1 = i;
                break;
            }
        }
        for(int i = L - 1; i >= 0; i--){
            if(A[i] == '<'){
                idx2 = i;
                break;
            }
        }
        int res = 0;
        if(idx1 != -1 && idx2 != -1)
            res = min(idx1, L - 1 - idx2);
        else if(idx1 == -1)
            res = L - 1 - idx2;
        else
            res = idx1;
        cout << res << endl;
    }
    return 0;
}