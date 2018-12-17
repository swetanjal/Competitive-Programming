#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, K;
long long A[MAXN];
int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    long long int diff = 0;
    int done = 0;
    for(int i = 0; i < N; i++){
        long long tmp = A[i];
        tmp = tmp - diff;
        if(tmp == 0)
            continue;
        done++;
        diff = diff + tmp;
        cout << tmp << endl;
        if(done == K)
            break;
    }
    for(int i = done; i < K; ++i)
    cout << "0\n";
    return 0;
}