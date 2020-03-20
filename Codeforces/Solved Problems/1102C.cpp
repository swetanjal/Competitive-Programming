#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    long long A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    if(X > Y){
        cout << N << endl;
        return 0;
    }    
    else{
        int cnt = 0;
        for(int i = 0; i < N; ++i){
            if(A[i] <= X)
                cnt++;
        }
        cnt = ceil(cnt * 1.0 / 2);
        cout << cnt << endl;
    }
    return 0;
}