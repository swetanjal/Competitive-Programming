#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        int N;
        cin >> N;
        int row[N + 5][N + 5];
        int col[N + 5][N + 5];
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j)
                row[i][j] = col[i][j] = 0;
        }
        long long s = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                int a;
                cin >> a;
                row[i][a] += 1;
                col[j][a] += 1;
                if(i == j)
                    s += a;
            }
        }
        int res_row = 0;
        int res_col = 0;
        for(int i = 1; i <= N; ++i){
            int flag_row = 0;
            int flag_col = 0;
            for(int j = 1; j <= N; ++j){
                if(row[i][j] > 1)
                    flag_row = 1;
                if(col[i][j] > 1)
                    flag_col = 1;
            }
            res_row += flag_row;
            res_col += flag_col;
        }
        cout << "Case #" << cases << ": " << s << " " << res_row << " " << res_col << endl;
    }
    return 0;
}