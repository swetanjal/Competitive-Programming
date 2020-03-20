#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    if(N == 1 && M == 1)
    {
        cout << "0\n";
        return 0;
    }
    if(M == 1)
    {
        for(int i = 1; i <= N; ++i)
        {
            cout << (i + 1) << endl;
        }
        return 0;
    }
    long long int A[N][M];
    int count = 1;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
            A[i][j] = (i + 1);
        count++;
    }
    for(int j = 0; j < M; ++j){
        for(int i = 0; i < N; ++i)
            A[i][j] *= count;
        count++;
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}