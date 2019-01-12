#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
struct element{
    int l;
    int r;
    int idx;
};
int T, N;
element A[MAXN];
int res[MAXN];
bool cmp(element a, element b)
{
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}
int main()
{
    cin >> T;
    while(T--){
        cin >> N;
        for(int i= 0; i < N; ++i){
            cin >> A[i].l >> A[i].r;
            A[i].idx = i;
        }
        sort(A, A + N, cmp);
        int en = 0;
        int max_r = A[0].r;
        for(int i = 1; i < N; ++i){
            if(A[i].l <= max_r){
                en = i;
                max_r = max(max_r, A[i].r);
            }
            else
                break;
        }
        int got = -1;
        for(int i = en + 1; i < N; ++i){
            if(A[i].l > max_r)
            {
                got = i;
                break;
            }
        }
        if(got == -1)
            cout << got << endl;
        else{
            int maxi = 0;
            for(int i = 0; i < got; ++i){
                res[A[i].idx] = 1;
                maxi = max(maxi, A[i].r);
            }
            for(int i = got; i < N; ++i){
                res[A[i].idx] = 2;
            }
            if(A[got].l <= maxi){
                cout << "-1\n";
            }
            else{
                for(int i = 0; i < N; ++i)
                    cout << res[i] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}