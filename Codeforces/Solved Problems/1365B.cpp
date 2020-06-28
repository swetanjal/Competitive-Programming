#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int A[N];
        int B[N];
        vector <int> x;
        vector <int> y;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        for(int i = 0; i < N; ++i)
            cin >> B[i];
        for(int i = 0; i < N; ++i){
            if(B[i] == 0)
                x.push_back(A[i]);
            else
                y.push_back(A[i]);
        }
        int flag1 = 0;
        int flag2 = 0;
        for(int i = 1; i < x.size(); ++i){
            if(x[i] >= x[i - 1])
                continue;
            flag1 = 1;
            break;
        }
        for(int i = 1; i < y.size(); ++i){
            if(y[i] >= y[i - 1])
                continue;
            flag2 = 1;
            break;
        }
        if((flag1 == 1 && (y.size() == 0)) || (flag2 == 1 && (x.size() == 0)))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}