#include "bits/stdc++.h"
using namespace std;
const int MAXN = 505;
int N, M;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> A[i][j];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> B[i][j];
    int flag = 1;
    for(int i = 0; i < N; ++i)
    {
        int c = 0;
        for(int j = 0; j < M; ++j)
        {
            if(A[i][j] != B[i][j])
                c++;
        }
        if((c % 2) != 0)
            flag = 0;
    }
    for(int j = 0; j < M; ++j){
        int c = 0;
        for(int i = 0; i < N; ++i){
            if(A[i][j] != B[i][j])
                c++;
        }
        if((c % 2) != 0)
            flag = 0;
    }
    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}