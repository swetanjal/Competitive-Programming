#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, M;
int A[MAXN];
int freq[MAXN];
set <int> S;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; ++i)
        cin >> A[i];
    for(int i = 0; i < M; ++i){
        S.insert(A[i]);
        freq[A[i]]++;
        if(S.size() == N){
            set <int> :: iterator it;
            vector <int> pres;
            for(it = S.begin(); it != S.end(); ++it){
                pres.push_back(*it);
            }
            S.clear();
            for(int j = 0; j < N; ++j){
                freq[pres[j]]--;
                if(freq[pres[j]] > 0)
                    S.insert(pres[j]);
            }
            cout << "1";
        }
        else
            cout << "0";
    }
    cout << "\n";
    return 0;
}