#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long A[N];
    long long s = 0;
    map < long long, int> H;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(H.find(A[i]) == H.end())
            H[A[i]] = 1;
        else
            H[A[i]]++;
    }    
    sort(A, A + N);
    int ok = 0;
    set < pair <int, long long> > S;
    for(int i = 0; i < N; ++i)
    {
        S.insert({H[A[i]], A[i]});
    }
    for(int i = 0; i < N; ++i){
        if(A[i] > 0){
            if(H.find(A[i] - 1) == H.end()){
                S.insert({1, A[i] - 1});
                S.erase(S.find({H[A[i]], A[i]}));
                S.insert({H[A[i]] - 1, A[i]});
                set < pair <int, long long> > :: iterator it = S.end();
                --it;
                pair <int, long long> p = *it;
                if(p.first < 2)
                {
                    ok = 1;
                    break;
                }
                S.erase(S.find({H[A[i]] - 1, A[i]}));
                S.insert({H[A[i]], A[i]});
                S.erase(S.find({1, A[i] - 1}));
            }
            else{
                S.erase(S.find({H[A[i] - 1], A[i] - 1}));
                S.insert({H[A[i] - 1] + 1, A[i] - 1});
                S.erase(S.find({H[A[i]], A[i]}));
                S.insert({H[A[i]] - 1, A[i]});
                set < pair <int, long long> > :: iterator it = S.end();
                --it;
                pair <int, long long> p = *it;
                if(p.first < 2)
                {
                    ok = 1;
                    break;
                }
                S.erase(S.find({H[A[i]] - 1, A[i]}));
                S.insert({H[A[i]], A[i]});
                S.erase(S.find({H[A[i] - 1] + 1, A[i] - 1}));
                S.insert({H[A[i] - 1], A[i] - 1});
            }
        }
    }
    int next = (A[0] == 0) ? 1 : 0;
    for(int i = 0; i < N; ++i){
        if(A[i] == 0)
            continue;
        s += (A[i] - next);
        next += 1;
    }
    if(((s % 2) == 0) || !ok)
        cout << "cslnb\n";
    else
        cout << "sjfnb\n";
    return 0;
}