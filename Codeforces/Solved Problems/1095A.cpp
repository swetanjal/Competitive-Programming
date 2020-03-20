#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    char A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int cnt = 1;
    for(int i = 0; i < N; i += cnt){
        cout << A[i];
        cnt++;
    }
    cout << endl;
    return 0;
}