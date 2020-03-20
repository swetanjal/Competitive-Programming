#include "bits/stdc++.h"
using namespace std;

long long comp(long long S)
{
    long long prod = 1;
    int cnt = 0;
    while((S % 2) == 0){
        S /= 2;
        cnt++;
    }
    prod = prod * (cnt + 1);
    for(long long i = 3; i * i <= S; i += 2){
        cnt = 0;
        while((S % i) == 0){
            S /= i;
            cnt++;
        }
        prod = prod * (cnt + 1);
    }
    if(S > 2)
        prod = prod * 2;
    return (prod - 2);
}


int main()
{
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long int A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        sort(A, A + N);
        int l = 0; int r = N - 1;
        long long res = -1;
        int cont = 0;
        while(l <= r){
            if(res == -1){
                res = A[l] * A[r];
                l++;
                r--;
            }
            else{
                if(res != (A[l] * A[r]))
                {
                    cont = 1;
                }
                l++;
                r--;
            }
            //cout << res << endl;
        }
        if(cont)
            cout << "-1\n";
        else{
            long long cnt = comp(res);
            if(cnt == N)
                cout << res << endl;
            else
                cout << "-1\n";
        }
    }
    return 0;
}