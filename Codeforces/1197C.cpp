#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector <long long int> t;
    long long prev;
    cin >> prev;
    long long ans = -prev;
    for(int i = 1; i < N; ++i){
        long long curr;
        cin >> curr;
        t.push_back(prev - curr);
        prev = curr;
    }
    ans += prev;
    sort(t.begin(), t.end());
    for(int i = 0; i < (K - 1); ++i)
        ans += t[i];
    cout << ans << endl;
    return 0;
}