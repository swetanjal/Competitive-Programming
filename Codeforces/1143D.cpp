#include "bits/stdc++.h"
using namespace std;

long long lcm(long long a, long long b){
    return (a * b) / __gcd(a, b);
}

int main()
{
    long long N, K, A, B;
    cin >> N >> K;
    cin >> A >> B;
    long long start = 1 + A;
    long long minimum = LONG_LONG_MAX;
    long long maximum = LONG_LONG_MIN;
    for(long long int i = 1; i <= (N * K); i += K){
        long long e1 =  i - B;
        while(e1 <= 0)
            e1 += (N * K);
        if(e1 <= start){
            e1  = N*K + e1;
        }
        long long e2 = i + B;
        if(e2 <= start){
            e2 = N*K + e2;
        }
        long long d1 = (N * K) / __gcd(N * K, (e1 - start));
        long long d2 = (N * K) / __gcd(N * K, (e2 - start));
        minimum = min(minimum, min(d1, d2));
        maximum = max(maximum, max(d1, d2));
    }    
    cout << minimum << " " << maximum << endl;
    return 0;
}