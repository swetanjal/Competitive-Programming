#include "bits/stdc++.h"
using namespace std;
const int MAXN = 4e5 + 5;
long long int I;
int N;
long long A[MAXN];
map <long long, int> H;
set <long long> S;

bool add(int idx)
{
    if(H.find(A[idx]) == H.end())
    {
        H[A[idx]] = 1;
        S.insert(A[idx]);
    }
    else {
        H[A[idx]]++;
        S.insert(A[idx]);
    }
    if((N * 1LL * ceil(log2(S.size())) <= 8 * I)){
        return true;
    }
    else{
        H[A[idx]]--;
        if(H[A[idx]] == 0)
            S.erase(A[idx]);
        return false;
    }
}

bool remove(int idx){
    H[A[idx]]--;
    if(H[A[idx]] == 0){
        S.erase(A[idx]);
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> I;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    int l = 0; int r = 0;
    int ans = INT_MAX;
    while(r < N)
    {
        while(r < N && add(r)){
            r++;
        }
        //r--;
        ans = min(ans, l + N - r);
        while(l < r && remove(l)){
            l++;
        }
        l++;
        ans = min(ans, l + N - r);
    }
    cout << ans << endl;
    return 0;
}