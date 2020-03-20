#include "bits/stdc++.h"
using namespace std;
const int MAXN  = 2e5 + 5;
int N;
char A[MAXN];
int color[MAXN];

bool chk(int depth)
{
    int c[N];
    for(int i = 0; i < N; ++i)
        c[i] = -1;
    // Color 0s
    int curr = 0;
    for(int i = 0; i < N; ++i){
        if(A[i] == '(' && curr < depth){
            curr++;
            c[i] = 0;
        }
        if(A[i] == ')' && curr > 0){
            --curr;
            c[i] = 0;
        }
    }
    // Color 1s
    curr = 0;
    for(int i = 0; i < N; ++i){
        if(c[i] != -1)
            continue;
        if(A[i] == '(' && curr < depth){
            curr++;
            c[i] = 1;
        }
        if(A[i] == ')' && curr > 0){
            curr--;
            c[i] = 1;
        }
    }
    for(int i = 0; i < N; ++i){
        if(c[i] == -1)
            return false;
    }
    for(int i = 0; i < N; ++i)
        color[i] = c[i];
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int low = 0; int high = 2e5 + 5;
    int mid;
    int best = -1;
    while(high >= low){
        mid = (high + low) / 2;
        if(chk(mid)){
            high = mid - 1;
            best = mid;
        }
        else
            low = mid + 1;
    }    
    //cout << best << endl;
    for(int i = 0; i < N; ++i)
        cout << color[i];
    cout << endl;
    return 0;
}