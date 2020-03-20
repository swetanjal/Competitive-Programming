#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int pos = -1;
    for(int i = 0; i < N; ++i){
        if(A[i] == N){
            pos = i;
            break;
        }
    }
    int no = 0;
    for(int i = 1; i <= pos; ++i){
        if(A[i] > A[i - 1])
            continue;
        no = 1;
    }
    for(int i = pos; i < (N - 1); ++i){
        if(A[i] > A[i + 1])
            continue;
        no = 1;
    }
    if(no)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}