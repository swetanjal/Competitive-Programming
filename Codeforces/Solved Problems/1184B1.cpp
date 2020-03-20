#include "bits/stdc++.h"
using namespace std;
const int MAXS = 1e5 + 5;
int S, B;
long long int A[MAXS];
long long cum[MAXS];
vector < pair <long long, long long> > V;
int main()
{
    cin >> S >> B;
    for(int i = 0; i < S; ++i)
        cin >> A[i];
    for(int i = 0; i < B; ++i){
        long long int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(V.begin(), V.end());
    cum[0] = V[0].second;
    for(int i = 1; i < B; ++i)
        cum[i] = cum[i - 1] + V[i].second;
    for(int i = 0; i < S; ++i){
        int low = 0; int high = B - 1;
        int pos = -1;
        while(high >= low){
            int mid = (high + low) / 2;
            if(V[mid].first <= A[i])
            {
                pos = mid;
                low = mid + 1;
            }            
            else
                high = mid - 1;
        }
        if(pos == -1)
            cout << "0\n";
        else
            cout << cum[pos] << " ";
    }
    cout << endl;
    return 0;
}