#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
struct element{
    int sz;
    vector <long long int> V;
    vector <long long int> cum;
};
bool cmp(element l, element y)
{
    return l.sz > y.sz;
}
bool cmp2(long long int x, long long int y)
{
    return x > y;
}
int N, M;
element A[MAXN];
int main()
{
    cin >> N >> M;
    for(int i = 0; i < MAXN; ++i){
        A[i].sz = 0;
    }
    for(int i = 1; i <= N; ++i){
        long long int S;
        long long int R;
        cin >> S >> R;
        A[S].V.push_back(R);
        A[S].sz++;
        A[S].cum.push_back(0);
    }
    for(int i = 1; i <= M; ++i){
        sort(A[i].V.begin(), A[i].V.end(), cmp2);
        if(A[i].sz > 0){
            A[i].cum[0] = A[i].V[0];
        }
        for(int j = 1; j < A[i].sz; ++j){
            A[i].cum[j] = A[i].cum[j - 1] + A[i].V[j];
        }
    }
    sort(A, A + MAXN, cmp);
    long long res = 0;
    for(int i = 1; i <= N; ++i){
        long long tmp = 0;
        for(int j = 0; j < M; ++j){
            if(A[j].sz < i)
                break;
            if(A[j].cum[i - 1] > 0)
                tmp = tmp + A[j].cum[i - 1];
        }
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}