#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        int A[N][M];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j)
                cin >> A[i][j];
        }
        int c = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                int flag1 = 0;
                for(int k = 0; k < M; ++k){
                    if(A[i][k] == 0)
                        continue;
                    flag1 = 1;
                }
                int flag2 = 0;
                for(int k = 0; k < N; ++k){
                    if(A[k][j] == 0)
                        continue;
                    flag2 = 1;
                }
                if(flag1 == 0 && flag2 == 0){
                    A[i][j] = 1;
                    c++;
                }
            }
        }
        if((c % 2) == 0){
            cout << "Vivek\n";
        }
        else{
            cout << "Ashish\n";
        }
    }
    return 0;
}