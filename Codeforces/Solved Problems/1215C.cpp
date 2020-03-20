#include "bits/stdc++.h"
using namespace std;
vector <int> X;
vector <int> Y;
int N;
string A;
string B;
int main()
{
    cin >> N;
    cin >> A;
    cin >> B;
    for(int i = 0; i < N; ++i){
        if(A[i] == 'a' && B[i] == 'b')
            X.push_back(i);
        else if(A[i] == 'b' && B[i] == 'a')
            Y.push_back(i);
    }
    if((X.size() + Y.size()) % 2)
        cout << "-1\n";
    else{
        int res = 0;
        vector <int> ret1;
        vector <int> ret2;
        if((X.size() % 2) != 0){
            Y.push_back(X[X.size() - 1]);
            
            ret1.push_back(X[X.size() - 1]);
            ret2.push_back(X[X.size() - 1]);
            X.pop_back();
        }
        for(int i = 0; i < X.size(); i += 2){
            ret1.push_back(X[i]);
            ret2.push_back(X[i + 1]);
        }
        for(int i = 0; i < Y.size(); i += 2){
            ret1.push_back(Y[i]);
            ret2.push_back(Y[i + 1]);
        }
        cout << ret1.size() << endl;
        for(int i = 0; i < ret1.size(); ++i)
            cout << (ret1[i]+1) << " " << (ret2[i] + 1) << endl;
    }
    
    return 0;
}