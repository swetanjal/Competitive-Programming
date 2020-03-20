#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int N;
char A[MAXN];

// Start of Segment Tree Template
/*
    1. Create object: SegmentTree obj(N);
    2. Do a point update at index idx with value val as follows: obj.point_update(1, 0, N - 1, idx, val)
    3. Query sum: obj.query_sum(1, 0, N - 1, l, r)
    4. Query minimum : obj.query_minimum(1, 0, N - 1, l, r)
    5. Query maximum : obj.query_maximum(1, 0, N - 1, l, r)
    6. Range Update : obj.range_update(1, 0, N - 1, l, r, val)
*/
const int segtreeMAXN = 1e6 + 5; // Modify this line to change maximum number of elements in array
int tree_min[4 * segtreeMAXN];
int tree_max[4 * segtreeMAXN];
int tree_sum[4 * segtreeMAXN];
int lazy[4 * segtreeMAXN];
int segtreeA[segtreeMAXN];


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
        if(lazy[node]!=0)
	    {
		    tree_sum[node] += ((high - low + 1) * 1LL * lazy[node]);
            tree_min[node] += lazy[node];
            tree_max[node] += lazy[node];
		    if(low != high)
		    {
			    lazy[(2 * node)] += lazy[node];
			    lazy[(2 * node) + 1] += lazy[node];
		    }
		    lazy[node]=0;
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
    int query_minimum(int node, int low, int high, int qlow, int qhigh)
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
    int query_maximum(int node, int low, int high, int qlow, int qhigh)
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
    int query_sum(int node, int low, int high, int qlow, int qhigh)
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

char text[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //cout.tie(false);
    cin >> N;
    SegmentTree obj(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int idx = 0;
    for(int i = 0; i < N; ++i){
        if(A[i] == 'L'){
            idx--;
            idx = max(0, idx);
            int lst = obj.query_minimum(1, 0, N - 1, N - 1, N - 1);
            int minimum = obj.query_minimum(1, 0, N - 1, 0, N - 1);
            if(minimum > -1 && lst == 0)
                cout << obj.query_maximum(1, 0, N - 1, 0, N - 1) << " ";
            else
                cout << "-1 ";
        }
        else if(A[i] == 'R'){
            idx++;
            int lst = obj.query_minimum(1, 0, N - 1, N - 1, N - 1);
            int minimum = obj.query_minimum(1, 0, N - 1, 0, N - 1);
            if(minimum > -1 && lst == 0)
                cout << obj.query_maximum(1, 0, N - 1, 0, N - 1) << " ";
            else
                cout << "-1 ";
        }
        else if(A[i] == '('){
            int v = 0;
            if(text[idx] == ')')
                v = 2;
            else if(text[idx] == '(')
                v = 0;
            else
                v = 1;
            text[idx] = A[i];
            obj.range_update(1, 0, N - 1, idx, N - 1, v);

            int lst = obj.query_minimum(1, 0, N - 1, N - 1, N - 1);
            int minimum = obj.query_minimum(1, 0, N - 1, 0, N - 1);
            if(minimum > -1 && lst == 0)
                cout << obj.query_maximum(1, 0, N - 1, 0, N - 1) << " ";
            else
                cout << "-1 ";
        }
        else if(A[i] == ')'){
            int v = 0;
            if(text[idx] == '(')
                v = -2;
            else if(text[idx] == ')')
                v = 0;
            else
                v = -1;
            text[idx] = A[i];
            obj.range_update(1, 0, N - 1, idx, N - 1, v);

            int lst = obj.query_minimum(1, 0, N - 1, N - 1, N - 1);
            int minimum = obj.query_minimum(1, 0, N - 1, 0, N - 1);
            if(minimum > -1 && lst == 0)
                cout << obj.query_maximum(1, 0, N - 1, 0, N - 1) << " ";
            else
                cout << "-1 ";
        }
        else{
            // Do nothing!!
            int v = 0;
            if(text[idx] == '(')
                v = -1;
            else if(text[idx] == ')')
                v = 1;
            
            text[idx] = A[i];
            obj.range_update(1, 0, N - 1, idx, N - 1, v);
            
            int lst = obj.query_minimum(1, 0, N - 1, N - 1, N - 1);
            int minimum = obj.query_minimum(1, 0, N - 1, 0, N - 1);
            if(minimum > -1 && lst == 0)
                cout << obj.query_maximum(1, 0, N - 1, 0, N - 1) << " ";
            else
                cout << "-1 ";
        }
    }
    cout << endl;
    return 0;
}