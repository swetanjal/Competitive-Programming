#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <long long> res;
    vector <long double> A;
    long long s = 0;
    for(int i = 0; i < N; ++i){
        long double t;
        cin >> t;
        res.push_back(ceil(t));
        //cout << res[i] << " ";
        A.push_back(t);
        s += res[i];
    }
    if(s != 0){
        for(int i = 0; i < N; ++i){
            if(A[i] == res[i])
                continue;
            res[i] = res[i] - 1;
            s -= 1;
            if(s == 0)
                break;
        }
    }
    for(int i = 0; i < N; ++i)
        cout << res[i] << endl;
    return 0;
}