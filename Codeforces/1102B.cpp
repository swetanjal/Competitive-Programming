#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    pair < int, int >  A[N];
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        A[i] = make_pair(tmp, i);
    }
    sort(A, A + N);
    int DP[N];
    int flag = 1;
    int color[N];
    for(int i = 0; i < K; ++i){
        DP[i + 1] = A[i].first;
        color[A[i].second] = i + 1;
    }   
    int cnt = 0; 
    
    for(int i = K; i < N; ++i){
        if(cnt == K)
            cnt = 0;
        cnt++;
        if(DP[cnt] != A[i].first)
        {
            DP[cnt] = A[i].first;
            color[A[i].second] = cnt;
            continue;
        }
        flag = 0;
        break;
    }
    if(flag){
        cout << "YES\n";
        for(int i = 0; i < N; ++i)
            cout << color[i] << " ";
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}