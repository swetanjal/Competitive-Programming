#include "bits/stdc++.h"
using namespace std;
#define MAXN 200005
int N;
int MAX[MAXN];
int A[MAXN];

int main()
{
    
    cin >> N;
    
    int global = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        int tmp;
        for(int j = 1; j <= A[i]; ++j)
        {
            cin >> tmp;
            MAX[i] = max(MAX[i], tmp);
        }
        global = max(global, MAX[i]);
    }
    long long res = 0;
    for(int i = 0; i < N; ++i){
        if(MAX[i] == global)
            continue;
        res = res + ((global - MAX[i]) * 1LL * A[i]);
    }
    cout << res << endl;
    return 0;
}