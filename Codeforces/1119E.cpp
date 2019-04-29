#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int N;
long long int A[MAXN];
long long int res;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    res = 0;
    vector <long long int> past;
    for(int i = 0; i < N; ++i){
        int l = past.size();
        for(int j = l - 1; j >= 0; --j){
            if(A[i] < 2)
                break;
            A[i] -= 2;
            res++;
            past.pop_back();
        }
        res = res + (A[i] / 3);
        for(int j = 1; j <= (A[i] % 3); ++j)
            past.push_back(i);
    }
    cout << res << endl;
    return 0;
}