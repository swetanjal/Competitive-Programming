#include "bits/stdc++.h"
using namespace std;
long long int inf = 1e13;
const int MAXN = 2e5 + 5;
pair < long long int, int > A[MAXN];
long long DP[MAXN];
long long DP_SEG[MAXN];
int keep[MAXN];
int N;

// Start of Segment Tree Template

const int segtreeMAXN = 2e5 + 5; // Modify this line to change maximum number of elements in array
long long int tree_min[4 * segtreeMAXN];
long long int tree_max[4 * segtreeMAXN];
long long int tree_sum[4 * segtreeMAXN];
long long int lazy[4 * segtreeMAXN];
long long int segtreeA[segtreeMAXN];


class SegmentTree{
private:
    int N;
public:
    SegmentTree(int n){
        N = n;
        for(int i = 0; i < 4 * segtreeMAXN; ++i)
            tree_max[i] = 0, tree_min[i] = 0, lazy[i] = 0;
        for(int i = 0; i < segtreeMAXN; ++i)
            segtreeA[i] = 0;
    }
    void propagate(int low, int high, int node)
    {
        if(lazy[node] != 0)
        {
            tree_max[node] += lazy[node];
            tree_min[node] += lazy[node];
            tree_sum[node] += ((high - low + 1) * 1LL * lazy[node]);
            if(low != high)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void point_update(int node, int low, int high, int idx, long long int val)
    {
        if(low == high && idx == low)
        {
            tree_min[node] = val;
            tree_max[node] = val;
            tree_sum[node] = val;
            segtreeA[idx] = val;
            lazy[node] = 0;
            return;
        }
        if(idx > high || idx < low)
            return;
        if(idx >= low && idx <= high)
        {
            int mid = (low + high) / 2;
            point_update(2 * node, low, mid, idx, val);
            point_update(2 * node + 1, mid + 1, high, idx, val);
        }
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    }
    void range_update(int node, int low, int high, int qlow, int qhigh, long long int val)
    {
        propagate(low, high, node);
        if(low > qhigh || high < qlow)
            return;
        
        if(qlow <= low && high <= qhigh)
        {
            lazy[node] += val;
            propagate(low, high, node);
            return;
        }
        if(low == high)
            return;
        int mid = (low + high) / 2;
        range_update(2 * node, low, mid, qlow, qhigh, val);
        range_update(2 * node + 1, mid + 1, high, qlow, qhigh, val);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    }
    long long int query_minimum(int node, int low, int high, int qlow, int qhigh)
    {
        propagate(low, high, node);
        if(qlow <= low && high <= qhigh)
            return tree_min[node];
        if(qlow > high || qhigh < low)
            return 1000000000;
        int mid = (low + high) / 2;
        long long int m1 = query_minimum(2 * node, low, mid, qlow, qhigh);
        long long int m2 = query_minimum(2 * node + 1, mid + 1, high, qlow, qhigh);
        return min(m1, m2);
    }
    long long int query_maximum(int node, int low, int high, int qlow, int qhigh)
    {
        propagate(low, high, node);
        if(qlow <= low && high <= qhigh)
            return tree_max[node];
        if(qlow > high || qhigh < low)
            return -1000000000;
        int mid = (low + high) / 2;
        long long int m1 = query_maximum(2 * node, low, mid, qlow, qhigh);
        long long int m2 = query_maximum(2 * node + 1, mid + 1, high, qlow, qhigh);
        return max(m1, m2);
    }
    long long int query_sum(int node, int low, int high, int qlow, int qhigh)
    {
        propagate(low, high, node);
        if(qlow <= low && high <= qhigh)
            return tree_sum[node];
        if(qlow > high || qhigh < low)
            return 0;
        int mid = (low + high) / 2;
        long long int m1 = query_sum(2 * node, low, mid, qlow, qhigh);
        long long int m2 = query_sum(2 * node + 1, mid + 1, high, qlow, qhigh);
        return (m1 + m2);
    }

};
// End of Template

int main()
{
    cin >> N;
    SegmentTree obj(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + N);
    DP[N - 1] = inf; DP_SEG[N - 1] = inf;
    DP[N - 2] = inf; DP_SEG[N - 2] = inf;
    DP[N - 3] = A[N - 1].first - A[N - 3].first; DP_SEG[N - 3] = DP[N - 3];
    if((N - 3) > 0)
        DP_SEG[N - 3] += A[N - 4].first;
    obj.point_update(1, 0, N - 1, N - 1, DP_SEG[N - 1]);
    obj.point_update(1, 0, N - 1, N - 2, DP_SEG[N - 2]);
    obj.point_update(1, 0, N - 1, N - 3, DP_SEG[N - 3]);
    for(int i = (N - 4); i >= 0; --i)
    {
        DP[i] = A[N - 1].first - A[i].first;
        if(i == 0)
        {
            DP[i] = min(-A[i].first + obj.query_minimum(1, 0, N - 1, i + 3, N - 1), DP[i]);
            DP_SEG[i] = DP[i];
        }
        else{
            DP[i] = min(-A[i].first + obj.query_minimum(1, 0, N - 1, i + 3, N - 1), DP[i]);
            DP_SEG[i] = DP[i] + A[i - 1].first;
        }
        obj.point_update(1, 0, N - 1, i, DP_SEG[i]);
    }
    int count = 1;

    for(int i = 0; i < N; ++i){
        long long int stop = DP[i] + A[i].first;
        int j;
        for(j = i; j < N; ++j){
            //cout << stop << " ";
            keep[A[j].second] = count;
            if(DP_SEG[j] == stop && (j - i) >= 3){
                break;
            }
        }
        //cout << endl;
        count++;
        i = j - 1;
    }
    cout << DP[0] << " " << (count - 1) << endl;
    for(int i = 0; i < N; ++i)
        cout << keep[i] << " ";
    cout << endl;
    return 0;
}