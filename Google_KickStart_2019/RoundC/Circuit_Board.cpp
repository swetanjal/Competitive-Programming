#include "bits/stdc++.h"
using namespace std;
const int MAXN = 305;
int T, R, C, K;
long long DP[MAXN][MAXN];
long long A[MAXN][MAXN];
int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> R >> C >> K;
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> A[i][j];
            }
        }
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                int curr = j;
                long long MIN = A[i][j];
                long long MAX = A[i][j];
                
                for(int k = j + 1; k < C; ++k){
                    MIN = min(MIN, A[i][k]);
                    MAX = max(MAX, A[i][k]);
                    if((MAX - MIN) > K)
                        break;
                    curr = k;
                }
                DP[i][j] = curr;
            }
        }
        long long res = 0;
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                long long minimum = abs(DP[i][j] - j) + 1;
                res = max(res, minimum);
                for(int k = (i + 1); k < R; ++k){
                    minimum = min(minimum, abs(DP[k][j] - j) + 1);
                    long long tmp = minimum * (abs(k - i) + 1);
                    res = max(res, tmp);
                }
            }
        }
        cout << "Case #" << cases << ": " << res << endl;
    }
    return 0;
}