#include "bits/stdc++.h"
using namespace std;

long long int eval(long long N, long long D)
{
    return N * (2 + (N - 1) * D) / 2;
}

int main()
{
    long long int N;
    cin >> N;
    set <long long int> S;
    for(long long int i = 1; i * i <= N; ++i){
        if((N % i) == 0){
            S.insert(eval(N / i, i));
            S.insert(eval(i, N / i));
        }
    }
    set <long long int> :: iterator it;
    for(it = S.begin(); it != S.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}