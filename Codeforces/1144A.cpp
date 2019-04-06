#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int l = s.size();
        char A[l];
        for(int i = 0; i < l; ++i)
            A[i] = s[i];
        sort(A, A + l);
        int flag = 1;
        for(int i = 1; i < l; ++i){
            if((A[i] - A[i - 1]) == 1)
                continue;
            flag = 0;
            break;
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}