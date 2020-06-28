#include "bits/stdc++.h"
using namespace std;
int T, N, M;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        long long A[N];
        for(int i = 0; i < N; ++i){
            cin >> A[i];
        }
        sort(A, A + N, cmp);
        long long f[M];
        for(int i = 0; i < M; ++i){
            cin >> f[i];
        }
        int c = 0;
        sort(f, f + M);
        vector <long long int> assn[M];
        priority_queue <pair <int, int> , vector <pair <int, int> >, greater <pair <int, int>> > P;
        for(int i = 0; i < M; ++i){
            f[i] -= 1;
            assn[i].push_back(A[i]);
            c++;
            if(f[i] > 0)
                P.push({f[i], i});
        }
        while(P.empty() == false)
        {
            int idx = P.top().second;
            int rem = P.top().first;
            P.pop();
            while(rem > 0)
            {
                assn[idx].push_back(A[c++]);
                rem--;
            }
        }
        long long res = 0;
        for(int i = 0; i < M; ++i){
            sort(assn[i].begin(), assn[i].end());
            res += assn[i][0];
            res += assn[i][assn[i].size() - 1];
        }
        cout << res << endl;
    }
    return 0;
}