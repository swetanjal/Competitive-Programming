#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        map <int, int> H;
        for(int i = 0; i < N; ++i)
        {
            int tmp;
            cin >> tmp;
            if(H.find(tmp) == H.end())
                H[tmp] = 1;
            else
                H[tmp] += 1;
        }
        int pos = -1;
        for(int i = 0; i <= N; ++i){
            if(i == 0 && H.find(N - 1) != H.end() && H[N - 1] == N)
            {
                pos = i;
                break;
            }
            else if(i == N && H.find(0) != H.end() && H[0] == N)
            {
                pos = i;
                break;
            }
            else if(H.find(N - i) != H.end() && H[N - i] == i && H.find(N - i - 1) != H.end() && H[N - i - 1] == (N - i))
            {
                pos = i;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}