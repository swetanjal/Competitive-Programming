#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e3 + 5;
int N, M, t;
int A[2 * MAXN];
int a[MAXN], b[MAXN];
int chosen[2 * MAXN];
bool complete()
{
    for(int i = 1; i <= 2 * N; ++i)
    {
        if(chosen[i] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= (2 * N); ++i)
        cin >> A[i];
    for(int i = 1; i <= M; ++i)
    {
        cin >> a[i] >> b[i];
    }
    cin >> t;
    int prev = -1;
    while(complete() == false)
    {
        if(t == 1){
            //my turn
            //Search for idx in one of the M pairs.
            int choice = -1;
            for(int i = 1; i <= M; ++i){
                if(a[i] == prev && chosen[b[i]] == 0)
                {
                    choice = b[i];
                    break;
                }
                else if(b[i] == prev && chosen[a[i]] == 0)
                {
                    choice = a[i];
                    break;
                }
            }
            if(choice == -1){
                //I am not bound.
                for(int i = 1; i <= M; ++i){
                    if(!chosen[a[i]] && !chosen[b[i]])
                    {
                        if(A[a[i]] > A[b[i]])
                            choice = a[i];
                        else
                            choice = b[i];
                    }
                }
                if(choice == -1){
                    // Choose greatest.
                    int res = 0;
                    for(int i = 1; i <= 2 * N; ++i)
                    {
                        if(chosen[i] == 0)
                            res = max(res, A[i]);
                    }
                    for(int i = 1; i <= 2 * N; ++i)
                    {
                        if(chosen[i] == 0 && res == A[i])
                        {
                            choice = i;
                            break;
                        }
                    }
                    chosen[choice] = 1;
                    cout << choice << endl;
                }
                else{
                    chosen[choice] = 1;
                    cout << choice << endl;
                }
            }
            else{
                chosen[choice] = 1;
                cout << choice << endl;
            }
            t = 2;
            fflush(stdout);
        }
        else{
            //opponent's turn.
            int idx;
            cin >> idx;
            prev = idx;
            chosen[idx] = 1;
            t = 1;
        }
    }
    return 0;
}