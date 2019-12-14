#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int T, N;
int A[MAXN];
int tree[4 * MAXN];
int tree_idx[4 * MAXN];

void build(int node, int st, int en)
{
    if(st == en){
        tree[node] = 0;
        tree_idx[node] = 0;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = 0;
    tree_idx[node] = st;
}
int curr;
pair <int, int>  query(int node, int low, int high, int qlow, int qhigh)
{
    if(low > high)
        return {INT_MIN, -1};
    if(high < qlow || low > qhigh)
        return {INT_MIN, -1};
    if(qlow <= low && high <= qhigh)
        return {tree[node], tree_idx[node]};
    int mid = (low + high) / 2;
    pair <int, int> p1 = query(2 * node, low, mid, qlow, qhigh);
    pair <int, int> p2 = query(2 * node + 1, mid + 1, high, qlow, qhigh);
    if(p1.first == p2.second && p1.second == curr){
        return p2;
    }
    else if(p1.first == p2.second){
        return p1;
    }
    if(p1.first > p2.first)
        return p1;
    return p2;
}

void update(int node, int low, int high, int qlow, int qhigh, int x, int val)
{
    if(low == high && x == low)
    {    
        tree[node] = val, tree_idx[node] = low; return;
    }
    if(low == high)
        return;
    if(high < qlow || low > qhigh)
        return;
    int mid = (high + low) / 2;
    update(2 * node, low, mid, qlow, qhigh, x, val);
    update(2 * node + 1, mid + 1, high, qlow, qhigh, x, val);
    if(tree[2 * node] > tree[2 * node + 1])
    {
        tree[node] = tree[2 * node];
        tree_idx[node] = tree_idx[2 * node];
    }
    else{
        tree[node] = tree[2 * node + 1];
        tree_idx[node] = tree_idx[2 * node + 1];
    }
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        build(1, 1, N);
        int str[N];
        for(int i = 0; i < N; ++i)
            str[i] = -1;
        for(int i = N - 1; i >= 0; --i){
            curr = A[i];
            pair <int, int> p = query(1, 1, N, A[i], N);
            if(p.first == 0)
            {
                str[i] = -1;
                update(1, 1, N, A[i], A[i], A[i], 1);
                continue;
            }
            str[i] = p.second;
            if(p.second == A[i])
            update(1, 1, N, A[i], A[i], A[i], p.first);
            else
            update(1, 1, N, A[i], A[i], A[i], 1+p.first);
        }
        int gone[N];
        for(int i = 0; i < N; ++i)
            gone[i] = 0;
        int start =  query(1, 1, N, 1, N).second ;
        int idx = -1;
        for(int i = 0; i < N; ++i){
            if(start == A[i]){
                idx = i;
                break;
            }
        }
        for(int i = idx; i < N; ++i){
            int nxt = str[i];
            gone[i] = 1;
            if(nxt == -1)
                break;
            for(int j = i + 1; ; ++j){
                if(nxt == A[j])
                {   
                    i = j - 1;
                    break;
                    
                }
            }
        }
        int res = 0;
        map <int, int> H;
        for(int i = 0; i < N; ++i){
            if(gone[i] == 1)
                continue;
            if(H.find(A[i]) != H.end())
                continue;
            H[A[i]] = 1;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}