#include "bits/stdc++.h"
using namespace std;
int cases;
int main()
{

    cin >> cases;
    int flag = 1;
    while(cases--)
    {
        int T, N;
        cin >> T >> N;
        int A[N];
        for(int i = 0; i < N; ++i)
        {
            int u, v;
            cin >> u >> v;
            A[i] = (v - u);
        }
        int lol_flag = 0;
        for(int i = T; i >= 1; --i){
            int curr_time = i;
            int tmp_flag = 1;
            for(int j = 0; j < N; ++j){
                //cout << curr_time << endl;
                if(curr_time >= A[j] && (T - curr_time) >= A[j]){
                    // Choose the minimum
                    curr_time = max(curr_time, T - curr_time) + A[j];
                }
                else if(curr_time < A[j] && (T - curr_time) < A[j]){
                    tmp_flag = 0;
                    break;
                }
                else
                {
                    curr_time = min(curr_time, T - curr_time) + A[j];
                }
            }
            lol_flag = lol_flag | tmp_flag;
            if(lol_flag)
                break;
        }
        flag = flag & lol_flag;
    }
    if(flag)
        cout << "possible\n";
    else
        cout << "impossible\n";
    return 0;
}