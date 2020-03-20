#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long res = 0;
    for(long long i  = 1; i * i <= N; ++i){
        res = i;
    }
    long long int add = 0;
    if(res * res < N){
        add = (N - (res * res));
        add = ceil(add * 1.0/ res);
        add = int(add);
    }
    res *= 2;
    res += add;
    cout << res << endl;
    return 0;
}