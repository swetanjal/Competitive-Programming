#include "bits/stdc++.h"
using namespace std;

map <int, int> H;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    int res = 0;
    for(int i = 0; i < N; ++i){
        if((A[i] - 1) > 0 && H.find(A[i] - 1) == H.end()){
            H[A[i] - 1] = 1;
            res++;
        }
        else if((A[i]) > 0 && H.find(A[i]) == H.end()){
            H[A[i]] = 1;
            res++;
        }
        else if((A[i] + 1) > 0 && H.find(A[i] + 1) == H.end()){
            H[A[i] + 1] = 1;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}