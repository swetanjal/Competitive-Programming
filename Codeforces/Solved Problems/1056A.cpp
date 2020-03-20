#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
int A[MAXN][MAXN];
int N, T;
int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> T;
        for(int j = 1; j <= T; ++j)
        {
            int tmp;
            cin >> tmp;
            A[i][tmp] = 1;
        }
    }
    for(int i = 1; i < MAXN; ++i){
        int flag = 1;
        for(int j = 1; j <= N; ++j){
            if(A[j][i] == 0){
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}