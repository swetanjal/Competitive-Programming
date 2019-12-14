#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
string S;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cin >> S;
        int res[N];
        int flag = 0;
        for(int i = 0; i <= 9; ++i){
            int lst = 0;
            for(int j = 0; j < N; ++j)
                res[j] = 0;
            for(int j = 0; j < N; ++j){
                if((S[j] - '0') <= i && (S[j] - '0') >= lst)
                    res[j] = 1, lst = (S[j] - '0');
            }
            for(int j = 0; j < N; ++j){
                if((S[j] - '0') >= i && res[j] == 0 && (S[j] - '0') >= lst)
                    res[j] = 2, lst = (S[j] - '0');
            }
            int cnt = 0;
            for(int j = 0; j < N; ++j){
                if(res[j] == 0)
                    cnt++;
            }
            if(cnt == 0){
                for(int j = 0; j < N; ++j)
                    cout << res[j];
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout << "-";
        cout << endl;
    }
    return 0;
}