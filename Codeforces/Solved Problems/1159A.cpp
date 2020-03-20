#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        char c;
        cin >> c;
        if(c == '+')
            cnt++;
        else
            cnt--;
        res = min(res, cnt);
    }
    cnt = cnt + abs(res);
    cout << cnt << endl;
    return 0;
}