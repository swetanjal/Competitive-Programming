#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 2e5 + 5;
int N;
long long int A[MAXN];
long long int mark[MAXN];
map <int, int> L;
map <int, int> R;
vector < pair <int, int> > V;

void marker(int st, int en)
{
    if(st == 0)
        mark[st] = 1;
    else
        mark[st] = 2;
    for(int i = st + 1; i <= en; ++i)
        mark[i] = 1;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(L.find(A[i]) == L.end()){
            L[A[i]] = i;
            R[A[i]] = i;
        }
        else{
            R[A[i]] = i;
        }
    }
    map <int, int> :: iterator it1;
    map <int, int> :: iterator it2;
    for(it1 = L.begin(), it2 = R.begin(); it1 != L.end(), it2 != R.end(); ++it1, ++it2){
        V.push_back(make_pair(it1 -> second, it2 -> second));
    }
    sort(V.begin(), V.end());
    int l = V[0].first; int r = V[0].second;
    for(int i = 1; i < V.size(); ++i){
        if(V[i].first <= r)
            r = max(V[i].second, r);
        else{
            marker(l, r);
            l = V[i].first;
            r = V[i].second;
        }
    }
    marker(l, r);
    long long prod = 1;
    for(int i = 0; i < N; ++i)
        prod = (prod * mark[i]) % MOD;
    cout << prod << endl;
    return 0;
}