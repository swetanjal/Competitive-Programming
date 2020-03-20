#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int A[MAXN];
int st[MAXN];
int en[MAXN];
int lst = -1;
int color[MAXN];
int _;
int N;
int comp;
int main()
{
    cin >> N >> _;
    for(int i = 0; i < MAXN; ++i){
        st[i] = N + 5;
        en[i] = -1;
    }
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        st[A[i]] = min(st[A[i]], i);
        en[A[i]] = max(en[A[i]], i);
    }
    for(int i = 0; i < N; ++i){
        if(lst < i){
            lst = en[A[i]];
            color[i] = ++comp; 
        }
        else
            lst = max(lst, en[A[i]]);
    }
    for(int i = 1; i < N; ++i)
    {
        if(color[i] == 0)
            color[i] = color[i - 1];
    }
    int idx = 0;
    int res = 0;
    for(int i = 1; i <= comp; ++i){
        map < int, int > H;
        set < pair < int, int > > S;
        int start = idx;
        for(int j = idx; color[j] == i && j < N; ++j){
            if(H.find(A[j]) == H.end()){
                H[A[j]] = 1;
                S.insert({-1, A[j]});
            }
            else{
                S.erase(S.find({-H[A[j]], A[j]}));
                H[A[j]] += 1;
                S.insert({-H[A[j]], A[j]});
            }
            idx += 1;
        }
        res = res + idx - start + (*S.begin()).first; 
    }
    cout << res;
    cout << endl;
    return 0;
}