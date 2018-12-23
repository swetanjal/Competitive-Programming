#include "bits/stdc++.h"
using namespace std;
long long int N, M, X;
int main()
{
    cin >> N >> M >> X;
    while((N != 0) || (M != 0) || (X != 0)){
        long long res = 0;
        long long int ptr = 0;
        for(int i = 1; i <= 1000; ++i){
            long long int low = ptr + 1; long long int high = M; long long int mid;
            long long thres = ((low * N) + X - N) / M;
            long long int pos = -1;
            while(high >= low)
            {
                mid = (high + low) / 2;
                long long f = (X + (mid * N) - N) / M;
                if(f == thres)
                {
                    low = mid + 1;
                    pos = mid;
                }
                else
                    high = mid - 1;
            }
            if(pos != -1){
                res += ((pos - ptr) * thres);
                ptr = pos;
            }
            else
                break;
        }
        cout << res << endl;
        cin >> N >> M >> X;
    }
    return 0;
}