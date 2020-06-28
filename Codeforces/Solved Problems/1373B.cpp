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
        int res = 0;
        int got = 1;
        while(got){
            got = 0;
            int pos = -1;
            int L = S.size();
            for(int i = 1; i < L; ++i){
                if(S[i] != S[i - 1]){
                    got = 1;
                    pos = i;
                    break;
                }
            }
            if(pos != -1){
                string tmp = "";
                for(int i = 0; i < L; ++i){
                    if(pos == (i + 1)){
                        continue;
                    }
                    else if(pos == i)
                        continue;
                    else
                        tmp = tmp + S[i];
                }
                S = tmp;
                res++;
            }
        }
        // cout << res << endl;
        if((res%2) == 0)
            cout << "NET\n";
        else
            cout << "DA\n";
    }
    return 0;
}