#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        int N;
        cin >> N;
        pair < int, pair <int, int> > A[N];
        for(int i = 0; i < N; ++i){
            cin >> A[i].first >> A[i].second.first;
            A[i].second.second = i;
        }
        sort(A, A + N);
        int C_time = 0;
        int J_time = 0;
        string res = "";
        for(int i = 0; i < N; ++i){
            res = res + "4";
        }
        for(int i = 0; i < N; ++i){
            if(C_time <= A[i].first){
                res[A[i].second.second] = 'C';
                C_time = A[i].second.first;
            }
            else if(J_time <= A[i].first){
                res[A[i].second.second] = 'J';
                J_time = A[i].second.first;
            }
            else{
                res = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << cases << ": " << res << endl;
    }
    return 0;
}