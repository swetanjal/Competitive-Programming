#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int N;
char A[MAXN];
int DPA[MAXN];
int DPB[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        DPA[i] = DPB[i] = -1;
    long long res = 0;
    int pos = -1;
    for(int i = N - 1; i >= 0; --i){
        DPA[i] = pos;
        if(A[i] == 'A')
            pos = i;
    }    
    pos = -1;
    for(int i = N - 1; i >= 0; --i){
        DPB[i] = pos;
        if(A[i] == 'B')
            pos = i;
    }
    for(int i = 0; i < N; ++i){
        if(A[i] == 'A'){
            if(DPA[i] == -1)
                continue;
            res = res + (N - DPA[i]);
            if(DPB[i] > DPA[i])
                res--;
        }
        else{
            if(DPB[i] == -1)
                continue;
            res = res + (N - DPB[i]);
            if(DPA[i] > DPB[i])
                res--;
        }
    }
    cout << res << endl;
    return 0;
}