#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
int A[MAXN];
int sol[MAXN];
int freq[MAXN];
vector <int> S[MAXN];
int ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    int cum = 0;
    for(int i = 0; i < N; ++i){
        sol[i] = N - A[i];
        S[sol[i]].push_back(i);
    }
    int impossible = 0;
    for(int i = 1; i < MAXN; ++i){
        if(S[i].size() % i == 0){

        }
        else{
            impossible = 1;
            break;
        }
    }
    int hat = 1;
    if(impossible)
        cout << "Impossible\n";
    else{
        cout << "Possible\n";
        for(int i = 1; i < MAXN; ++i){
            if(S[i].size() == 0)continue;
            int L = S[i].size();
            for(int j = 0; j < L; j += i){

                for(int k = j; k < j + i; k++)
                    ans[S[i][k]] = hat;
                ++hat;
            }
        }
        for(int i = 0; i < N; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}