#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1005;
struct element{
    long long x;
    long long y;
};
int N;
set < pair <long long, pair < long long, pair < long long, long long > > > > S;
pair <long long, pair < long long, pair < long long, long long > > > comp(long double x1, long double y1, long double x2, long double y2){
    pair <long long, pair < long long, pair < long long, long long > > > tmp;
    tmp.first = y2 - y1; tmp.second.first = x2 - x1;
    long long g = __gcd(tmp.first, tmp.second.first);
    tmp.first /= g; tmp.second.first /= g;
    tmp.second.second.first = tmp.second.first * y1 - tmp.first * x1;
    tmp.second.second.second = tmp.second.first;
    g = __gcd(tmp.second.second.first, tmp.second.second.second);
    if(g != 0 && tmp.second.second.second != 0){
        tmp.second.second.first /= g;
        tmp.second.second.second /= g;
    }
    return tmp;
}
element A[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i].x >> A[i].y;
    }
    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            if(i == j)
                continue;
            pair <long long, pair < long long, pair < long long, long long > > > k = comp(A[i].x, A[i].y, A[j].x, A[j].y);
            //cout << k.first << " " << k.second.first << " " << k.second.second.first << " " << k.second.second.second << endl;
            S.insert(k);
        }
    }
    long long res =  S.size() * 1LL * (S.size() - 1) / 2;
    map < pair <long long, long long> , long long > H;
    set < pair <long long, pair < long long, pair < long long, long long > > > > :: iterator it;
    for(it = S.begin(); it != S.end(); ++it){
        pair <long long, pair < long long, pair < long long, long long > > > itr = *it;
        if(H.find({itr.first, itr.second.first}) != H.end())
            H[{itr.first, itr.second.first}]++;
        else
            H[{itr.first, itr.second.first}] = 1;
    }
    map < pair <long long, long long> , long long> :: iterator it1;
    for(it1 = H.begin(); it1 != H.end(); ++it1){
        res = res - (it1->second * 1LL * (it1->second - 1) / 2);
    }
    cout << res << endl;
    return 0;
}