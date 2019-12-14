#include "bits/stdc++.h"
using namespace std;
int N;
string S;
vector < int > V;
vector < char > A;
bool valid()
{
    int L = A.size();
    int l = 0; int r = L - 1;
    while(l <= r)
    {
        if(A[l] != A[r])
            break;
        if(l == r && V[l] < 2)
        {
            l--;
            r++;
            break;
        }
        if(l == r)
        {
            break;
        }
        if((V[l] + V[r]) < 3)
            break;
        l++;
        r--;
    }
    if(l != r)
        return false;
    return true;
}


int main()
{
    cin >> S;
    N = S.size();
    char lst = S[0];
    int cnt = 1;
    for(int i = 1; i < N; ++i){
        if(lst == S[i])
            cnt++;
        else{
            V.push_back(cnt);
            A.push_back(lst);
            cnt = 1;
            lst = S[i];
        }
    }
    V.push_back(cnt);
    A.push_back(lst);
    if(valid())
        cout << (V[V.size() / 2] + 1) << endl;
    else
        cout << 0 << endl;
    return 0;
}