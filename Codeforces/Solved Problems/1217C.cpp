#include "bits/stdc++.h"
using namespace std;
int T;
string S;

long long decimal(int l, int r)
{
    long long int ex = 1;
    long long ans = 0;
    for(int i = r; i >= l; --i){
        if(S[i] == '1')
            ans = ans + ex;
        ex *= 2;
    }
    return ans;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> S;
        int N = S.size();
        long long ans = 0;
        long long int lst = -1;
        long long int DP[N];
        for(int i = 0; i < N; ++i){
            DP[i] = lst;
            if(S[i] == '1')
                lst = i;
        }
        for(int i = 0; i < N; ++i){
            for(int j = i; j >= 0; --j){
                if(abs(i - j) == 18)
                    break;
                if(S[j] == '0')
                    continue;
                long long int val = decimal(j, i);
                long long int reqd = val - (i - j + 1);
                if(reqd >= 0){
                    long long int rrr = (j - 1) - DP[j];
                    if(rrr >= reqd){
                        //cout << j << " " << i << " " << val << endl;
                        ans++;
                    }
                }
                
            }
        }
        cout << ans << endl;
    }
    return 0;
}