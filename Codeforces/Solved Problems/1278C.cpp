#include "bits/stdc++.h"
using namespace std;
int T;
int main()
{
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        N = 2 * N;
        int A[N];
        int cum = 0;
        for(int i = 0; i < N; ++i){
            cin >> A[i];
            if(A[i] == 1)
                cum += 1;
            else
                cum -= 1;
        }
        
        int curr = 0;
        vector <pair <int, int> > S;
        for(int i = (N / 2) - 1; i >= 0; --i)
        {
            if(A[i] == 1)
                curr += 1;
            else
                curr -= 1;
            S.push_back({curr, i});
        }
        sort(S.begin(), S.end());
        //for(int i = 0; i < (N / 2); ++i)
        //    cout << S[i].first << " " << S[i].second << endl;
        int ans = N;
        for(int i = (N / 2); i <= N; ++i){
            int low = 0; int high = (N / 2) - 1;
            int mid; int pos = -1;
            while(high >= low)
            {
                int mid = (high + low) / 2;
                if(S[mid].first == cum)
                {
                    pos = mid;
                    low = mid + 1;
                }
                else if(S[mid].first > cum)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            if(pos != -1)
            {
                ans = min(ans, ((N / 2) - S[pos].second) + (i - (N / 2)));
            }
            if(cum == 0)
            {
                ans = min(ans, (i - (N / 2)));
            }
            if(i == N)
                break;
            if(A[i] == 1)
                cum -= 1;
            else
                cum += 1;
        }
        cout << ans << endl;
    }
    return 0;
}