#include "bits/stdc++.h"
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++){
        int N, B;
        cin >> N >> B;
        int A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        sort(A, A + N);
        int res = 0;
        for(int i = 0; i < N; ++i){
            if(B >= A[i]){
                res++;
                B -= A[i];
            }
        }
        cout << "Case #" << cases << ": " << res << endl;
    }
    return 0;
}