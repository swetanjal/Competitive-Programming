#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    long long int cost = 1000000000000000000;
    int t = -1;
    for(int i = 1; i <= 105; ++i){
        int tmp = 0;
        for(int j = 0; j < N; ++j){
            tmp = tmp + min(abs(i - A[j]), min(abs(i + 1 - A[j]), abs(i - 1 - A[j])));
        }
        if(tmp < cost)
        {
            cost = tmp;
            t = i;
        }
    }
    cout << t << " " << cost << endl;
    return 0;
}