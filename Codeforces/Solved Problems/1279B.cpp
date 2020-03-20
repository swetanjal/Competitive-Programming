#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N; long long S;
        cin >> N >> S;
        long long A[N + 1];
        long long cum[N + 1];
        cum[0] = 0;
        A[0] = 0;
        for(int i = 1; i <= N; ++i){
            cin >> A[i];
            cum[i] = cum[i - 1] + A[i];
        }
        int idx = 0;
        long long curr = 0;
        long long ANS = -10000000000000000;
        for(int i = 0; i <= N; ++i){
            int low = i + 1; int high = N;
            int mid; int pos = -1;
            while(high >= low)
            {
                int mid = (high + low) / 2;
                if((curr + cum[mid] - cum[i]) <= S)
                {
                    low = mid + 1;
                    pos = mid;
                }
                else
                    high = mid - 1;
            }
            // cout << pos << endl;
            long long add = 0;
            if(i == 0 || i == 1)
                add = 0;
            else if(curr <= S)
                add = i - 1;
            long long ret = add;
            if(pos != -1)
                ret += (pos - i);
            if(ret > ANS){
                ANS = ret;
                idx = i;
            }
            // ANS = max(ANS, ret);
            curr += A[i];
        }
        cout << idx << endl;
    }
    return 0;
}