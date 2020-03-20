#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    cout << (N + 1) << endl;
    cout << "2 " << N << " " << "1"<<endl;
    cout << "1 " << N << " " << (2 * N) << endl; 
    int tar = (2 * N);
    for(int i = 1; i < N; ++i)
    {
        cout << "2 " << i << " " << tar << endl;
        tar--;
    }
    return 0;
}