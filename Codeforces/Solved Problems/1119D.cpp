#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, T;
long long int A[MAXN];
pair <long long int , long long int > DP[MAXN];
pair <long long, int> cases[MAXN];
long long res[MAXN];
int main()
{
    
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    for(int i = 0; i < N - 1; ++i)
        DP[i] = make_pair(A[i + 1] - A[i] , A[i]);
    sort(DP, DP + (N - 1));
    cin >> T;
    for(int i = 0; i < T; ++i){
        long long l, r;
        cin >> l >> r;
        long long len = r - l + 1;
        cases[i] = make_pair(len, i);
    }
    sort(cases, cases + T);
    int idx = N - 2;
    long long ans = 0;
    for(int i = T - 1; i >= 0; --i){
        if(i == (T - 1)){
            long long left = A[0];
            long long right = A[0];
            for(int j = 0; j < N; ++j){
                if(A[j] <= right){
                }
                else{
                    ans = ans + (A[j - 1] - left + 1) + (cases[i].first - 1);
                    left = A[j];
                }
                right = A[j] + cases[i].first - 1;
            }
            ans += (right - left + 1);
            res[cases[i].second] = ans;
        }
        else{
            ans = ans - cases[i + 1].first + cases[i].first;
            ans = ans - (N - 2 - idx) * cases[i + 1].first + (N - 2 - idx) * cases[i].first;
            for(int j = idx; j >= 0; --j){
                if(DP[j].first > (cases[i].first - 1)){
                    idx -= 1;
                    ans = ans - (DP[j].first) + cases[i].first;
                }
                else{
                    break;
                }
            }
            res[cases[i].second] = ans;
        }
    }
    for(int i = 0; i < T; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}