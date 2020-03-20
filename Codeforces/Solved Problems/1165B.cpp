#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    int day = 0;
    for(int i = 0; i < N; ++i){
        if(A[i] > day)
            day++;
    }    
    cout << day << endl;
    return 0;
}