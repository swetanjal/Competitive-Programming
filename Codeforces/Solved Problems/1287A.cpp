#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        char S[N];
        for(int i = 0; i < N; ++i)
            cin >> S[i];
        int res = 0;
        int st = N;
        for(int i = 0; i < N; ++i){
            if(S[i] == 'A')
            {
                st = i;
                break;
            }
        }
        int curr = -1;
        for(int i = st; i < N; ++i){
            if(S[i] == 'A'){
                curr = i;
                continue;
            }
            res = max(res, abs(curr - i));
        }
        cout << res << endl;
    }
    return 0;
}