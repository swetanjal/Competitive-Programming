#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e3 + 5;
int N;
long long H;
long long A[MAXN];
bool chk(int idx){
    long long tmp[idx];
    for(int i = 0; i < idx; ++i)
        tmp[i] = A[i + 1];
    sort(tmp, tmp + idx);
    long long ret = 0;
    for(int i = idx - 1; i >= 0; i -= 2)
        ret += tmp[i];
    if(ret <= H)
        return true;
    return false;
}

int main()
{
    cin >> N >> H;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    long long low = 1;
    long long high = N;
    long long mid;
    long long res = -1;
    while(low <= high){
        mid = (high + low) / 2;
        if(chk(mid)){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}