#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5 + 5;
int N;
int A[MAXN];
vector <int> f[6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i] == 4)
            f[0].push_back(i);
        else if(A[i] == 8)
            f[1].push_back(i);
        else if(A[i] == 15)
            f[2].push_back(i);
        else if(A[i] == 16)
            f[3].push_back(i);
        else if(A[i] == 23)
            f[4].push_back(i);
        else if(A[i] == 42)
            f[5].push_back(i);
        else
            assert(false);
    }
    int res = 0;
    while(!(f[0].empty() || f[1].empty() || f[2].empty() || f[3].empty() || f[4].empty() || f[5].empty())){
        int idx = f[5][f[5].size() - 1];
        f[5].pop_back();
        int ok = 1;
        for(int i = 4; i >= 0; --i){
            while(f[i].empty() == false && f[i][f[i].size() - 1] > idx)
                f[i].pop_back();
            if(f[i].empty())
            {
                ok = 0;
                break;
            }
            idx = f[i][f[i].size() - 1];
            f[i].pop_back();
        }
        if(ok == 0)
            break;
        res++;
    }
    cout << (N - (6 * res)) << endl;
    return 0;
}