#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A, A + N);
    vector <int> x;
    vector <int> y;
    int flag = 1;
    for(int i = 0; i < N; ++i){
       if(x.size() > 0 && x[x.size() - 1] == A[i] && y.size() > 0 && y[y.size() - 1] == A[i]){
           flag = 0;
       } 
        if(x.size() > 0 && x[x.size() - 1] == A[i])
            y.push_back(A[i]);
        else
            x.push_back(A[i]);
    }
    if(flag == 0)
        cout << "NO\n";
    else{
        cout << "YES\n";
        cout << x.size() << endl;
        for(int i = 0; i < x.size(); ++i)
            cout << x[i] << " ";
        cout << endl;
        cout << y.size() << endl;
        for(int i = y.size() - 1; i >= 0; --i)
            cout << y[i] << " ";
        cout << endl;
    }
    return 0;
}