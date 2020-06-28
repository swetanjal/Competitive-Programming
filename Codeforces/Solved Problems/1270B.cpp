#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        long long int A[N];
        for(int i = 0; i < N; ++i){
            cin >> A[i];
        }
        int flag = 0;
        for(int i = 1; i < N; ++i){
            if(abs(A[i] - A[i - 1]) == 1){
                continue;
            }
            else if(abs(A[i] - A[i - 1]) == 0)
                continue;
            flag = 1;
        }
        if(flag == 0)
            cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i = 1; i < N; ++i){
                if(abs(A[i] - A[i - 1]) >= 2){
                    cout << i << " " << (i + 1) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}