#include "bits/stdc++.h"
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    long long ret = 0;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < M; ++j){
            if(i > N || j > N)
                continue;
            if((((i * i) % M + (j * j) % M) % M) == 0)
            {
                long long k = (N - i) / M;
                long long l = (N - j) / M;
                if(i != 0)
                    k++;
                if(j != 0)
                    l++;
                ret = ret + (k * l);
            }
        }
    }    
    cout << ret << endl;
    return 0;
}