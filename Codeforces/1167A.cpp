#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        char A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        int idx = -1;
        for(int i = 0; i < N; ++i){
            if(A[i] == '8')
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
            cout << "NO\n";
        else{
            if((N - idx) >= 11)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}