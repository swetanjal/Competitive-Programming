#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    char A[N][M];
    int r[N];
    int c[M];
    for(int i = 0; i < N; ++i)
        r[i] = 0;
    for(int i = 0; i < M; ++i)
        c[i] = 0;
    int chk = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> A[i][j];
            if(A[i][j] == '*')
                r[i]++, c[j]++, chk++;
        }
    }    
    int posr = -1;
    int posc = -1;
    int invalid = 0;
    for(int i = 0; i < N; ++i){
        if(r[i] > 1 && posr != -1)
        {
            invalid = 1;
            break;
        }
        else if(r[i] > 1){
            posr = i;
        }
    }
    for(int i = 0; i < M; ++i){
        if(c[i] > 1 && posc != -1)
        {
            invalid = 1;
            break;
        }
        else if(c[i] > 1){
            posc = i;
        }
    }
    if(invalid){
        cout << "NO\n";
        return 0;
    }
    int cnt = 0;
    for(int i = posr; i >= 0; --i){
        if(A[i][posc] == '*')
            cnt++;
        else
            break;
    }
    for(int i = posr + 1; i < N; ++i){
        if(A[i][posc] == '*')
            cnt++;
        else
            break;
    }

    for(int i = posc; i >= 0; --i){
        if(A[posr][i] == '*')
            cnt++;
        else
            break;
    }
    for(int i = posc + 1; i < M; ++i){
        if(A[posr][i] == '*')
            cnt++;
        else
            break;
    }
    //cout << cnt << endl;
    //cout << chk << endl;
    if(cnt == (chk + 1)&& posr != 0 && posr != (N - 1) && posc != 0 && posc != (M - 1) && A[posr][posc] == '*' && A[posr + 1][posc] == '*' && A[posr - 1][posc] == '*'
    && A[posr][posc + 1] == '*' && A[posr][posc - 1] == '*')
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}