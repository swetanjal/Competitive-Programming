#include "bits/stdc++.h"
using namespace std;
const int MAXN = 100005;
int N, M;
int F[MAXN];
map < pair <int, int> , int > H;
int A[MAXN];
int B[MAXN];

void rev(int st, int en)
{
    if(st > en)
        return;
    vector <int> lol;
    for(int i = st; i <= en; ++i)
        lol.push_back(A[i]);
    reverse(lol.begin(), lol.end());
    int cnt = 0;
    for(int i = st; i <= en; ++i)
        A[i] = B[i] = lol[cnt++];
    return;
}

int main()
{
    cin >> N >> M;
    if(N == 1)
    {
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= N; ++i)
        A[i] = B[i] = i;
    for(int i = 1; i <= M; ++i)
    {
        int u, v;
        cin >> u >> v;
        F[u]++;
        F[v]++;
        H[make_pair(min(u, v), max(u, v))] = 1;
    }
    int yes = 0;
    int idx = -1;
    for(int i = 1; i <= N; ++i)
    {
        if(F[i] != (N - 1))
        {
            yes = 1;
            idx = i;
            break;
        }
    }
    if(yes)
    {
        int ind = -1;
        for(int i = 1; i <= N; ++i)
        {
            if(i != idx && H.find(make_pair(min(i, idx), max(i, idx))) == H.end())
            {
                ind = i;
                break;
            }
        }
        cout << "YES\n";
        rev(idx + 1, ind);
        B[ind] = B[idx];
        for(int i = 1; i <= N; ++i)
            cout << A[i] << " ";
        cout << endl;
        for(int i = 1; i <= N; ++i)
            cout << B[i] << " ";
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}