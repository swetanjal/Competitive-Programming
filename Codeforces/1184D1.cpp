#include "bits/stdc++.h"
using namespace std;
int N, K, M, T;
int main()
{
    cin >> N >> K >> M >> T;
    int curr_sz = N;
    int curr_idx = K;
    while(T--)
    {
        int key, idx;
        cin >> key >> idx;
        if(key == 0){
            // Break Link
            if(idx < curr_idx){
                curr_sz -= idx;
                curr_idx -= idx;
            }
            else{
                curr_sz = idx;
            }
        }
        else{
            // Add Link
            if(idx <= curr_idx){
                curr_idx += 1;
                curr_sz += 1;
            }
            else{
                curr_sz += 1;
            }
        }
        cout << curr_sz << " " << curr_idx << endl;
    }
    return 0;
}