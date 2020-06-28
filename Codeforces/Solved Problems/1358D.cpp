#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int N, X;
    cin >> N >> X;
    long long int A[2 * N];
    long long int S[2 * N];
    long long int cpy[2 * N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = N; i < 2 * N; ++i)
        A[i] = A[i - N];
    for(int i = 0; i < 2 * N; ++i)
        S[i] = A[i] * (A[i] + 1) / 2;
    for(int i = 0; i < 2 * N; ++i)
        cpy[i] = A[i];
    for(int i = 1; i < 2 * N; ++i){
        S[i] += S[i - 1];
        A[i] += A[i - 1];
    }
    long long int best = 0;
    for(int i = N; i < 2 * N; ++i){
        int low = 0;
        int high = i;
        int pos = -1;
        while(low <= high){
            int mid = (high + low) / 2;
            if((A[i] - A[mid]) <= X){
                pos = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        long long int rem = (X - (A[i] - A[pos]));
        long long int P = S[i] - S[pos];
        P = P + ((cpy[pos] * (cpy[pos] + 1) / 2) - ((cpy[pos] - rem) * (cpy[pos] - rem + 1) / 2));
        best = max(best, P);
    }
    cout << best << endl;
    return 0;
}