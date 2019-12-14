#include "bits/stdc++.h"
using namespace std;
vector <int> odd;
vector <int> even;
int a, b, c, d;

bool chk(vector <int> S)
{
    int l = S.size();
    for(int i = 1; i < l; ++i){
        if(abs(S[i] - S[i - 1]) == 1)
            continue;
        return false;
    }
    return true;
}

int main()
{
    cin >> a >> b >> c >> d;
    for(int i = 1; i <= a; ++i)
        even.push_back(0);
    for(int i = 1; i <= b; ++i)
        odd.push_back(1);
    
    for(int i = 1; i <= c; ++i)
        even.push_back(2);
    for(int i = 1; i <= d; ++i)
        odd.push_back(3);

    vector <int> res1;
    int l1 = 0;
    int l2 = 0;
    int N = a + b + c + d;
    for(int i = 0; i < N; ++i){
        if((i % 2) == 0 && (l1 < even.size()))
        {
            res1.push_back(even[l1++]);
        }
        else if(l2 < odd.size()){
            res1.push_back(odd[l2++]);
        }
    }
    l1 = 0;
    l2 = 0;
    vector <int> res2;
    for(int i = 0; i < N; ++i){
        if((i % 2) == 0 && (l2 < odd.size()))
        {
            res2.push_back(odd[l2++]);
        }
        else if(l1 < even.size()){
            res2.push_back(even[l1++]);
        }
    }
    if(chk(res1) && res1.size() == N){
        cout << "YES\n";
        for(int i = 0; i < N; ++i)
            cout << res1[i] << " ";
        cout << endl;
    }
    else if(chk(res2) && res2.size() == N){
        cout << "YES\n";
        for(int i = 0; i < N; ++i)
            cout << res2[i] << " ";
        cout << endl;
    }
    else cout << "NO\n";
    return 0;
}